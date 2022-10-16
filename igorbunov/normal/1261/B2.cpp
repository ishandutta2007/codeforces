#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

class node {
public:
    int prior;
    int value;
    int add;
    int sum;
    int sz;
    int min;
    int min_ind;
    bool rev = 0;
    node *left;
    node *right;
    node() {
        prior = (rand() << 16) | rand();
        value = 0;
        add = 0;
        sum = 0;
        min_ind = 0;
        sz = 1;
        rev = 0;
        min = 10000000000LL;
        left = nullptr;
        right = nullptr;
    }
};

void _dump(node* T) {
    if (T == nullptr) {
        //cout << "empty";
        return;
    }
    if (T->left != nullptr) {
        cout << "<";
        //_dump(T->left);
        cout << ">";
    }
    cout << T->value << "(" << T->min << ")";
    if (T->right != nullptr) {
        cout << "<";
        //dump(T->right);
        cout << ">";
    }
}

node* push(node *T) {
    if (T->rev) {
        swap(T->left, T->right);
        T->left->rev ^= true;
        T->right->rev ^= true;
        T->rev = false;
    }
    /*T->value += T->add;
    if (T->left != nullptr) {
        T->left->add += T->add;
    }
    if (T->right !=nullptr) {
        T->right->add += T->add;
    }
    T->sum += T->sz + T->add;*/
    return T;
}

node* pull(node *T) {
    T->sz = 1;
    if (T->left != nullptr) {
        T->sz += T->left->sz;
    }
    if (T->right != nullptr) {
        T->sz += T->right->sz;
    }
    int min1 = 1000000000;
    int min1_ind = -1;
    if (T->left != nullptr) {
    	if (T->left->min < min1) {
    		min1 = T->left->min;
    		min1_ind = T->left->min_ind;
    	}
    }

    if (T->value <= min1) {
    	min1 = T->value;
    	min1_ind = 0;
    	if (T->left != nullptr) {
    		min1_ind += T->left->sz;
    	}
    }
    
    if (T->right != nullptr) {
        if (T->right->min <= min1) {
    		min1 = T->right->min;
    		min1_ind = T->right->min_ind + 1;
    		if (T->left != nullptr) {
    			min1_ind += T->left->sz;
    		}
    	}
    }
    //cout << "MIN IS " << min1 << endl;
    T->min = min1;
    T->min_ind = min1_ind;
    return T;
}

node* merge(node* L, node* R) {
    if (L == nullptr) {
        return R;
    }
    if (R == nullptr) {
        return L;
    }
    L = push(L);
    R = push(R);
    if (L->prior < R->prior) {
        L->right = merge(L->right, R);
        return pull(L);
    } else {
        R->left = merge(L, R->left);
        return pull(R);
    }
}

pair<node*, node*> split(node* T, int x) {
    if (T == nullptr) {
        return make_pair(nullptr, nullptr);
    }
    T = push(T);
    int ind;
    if (T->left == nullptr) {
        ind = 0;
    } else {
        ind = T->left->sz;
    }
    if (x <= ind) {
        pair<node*, node*> p = split(T->left, x);
        node* L = p.first;
        T->left = p.second;
        T = pull(T);
        return make_pair(L, T);
    } else {
        pair<node*, node*> p = split(T->right, x - ind - 1);
        T->right = p.first;
        node* R = p.second;
        T = pull(T);
        return make_pair(T, R);
    }
}

node* insert(node* T, int i, int a) {
    node* c = new node();
    c->value = a;
    c->min = a;
    pair<node*, node*> p = split(T, i);
    node* L = p.first;
    node* R = p.second;
    node* A = merge(L, c);
    node* B = merge(A, R);
    return B;
}

pair<node*, int> find_min(node* T, int i, int j) {
    pair<node*, node*> p = split(T, j);
    pair<node*, node*> q = split(p.first, i);
    int ret = q.second->min;
    node* new_root = merge(q.first, q.second);
    new_root =  merge(new_root, p.second);
    return {new_root, ret};
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    node* arr = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	arr = insert(arr, i, a);
    }

    int m;
    cin >> m;

    map<int, vector<pair<int, int>>> tasks;

    for (int i = 0; i < m; i++) {
    	int k, pos;
    	cin >> k >> pos;
    	pos--;
    	tasks[k].push_back(make_pair(pos, i));
    }
    vector<int> ans(m);
    for (int i = n; i >= 1; i--) {
    	for (auto p: tasks[i]) {
    		auto p1 = find_min(arr, p.first, p.first + 1);
    		arr = p1.first;
    		ans[p.second] = p1.second;
    	}
    	int ind1 = arr->min_ind;
    	auto p = split(arr, ind1);
    	auto q = split(p.second, 1);
    	arr = merge(p.first, q.second);
    }

    for (int i = 0; i < m; i++) {
    	cout << ans[i] << endl;
    }
}