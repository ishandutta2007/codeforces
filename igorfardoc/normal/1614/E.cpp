#include<bits/stdc++.h>
#define MAX 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    ll min = 0;
    ll max = 0;
    ll adding = 0;
};

void push(Node* root, int l, int r) {
    int mid = l + ((ll)r - l) / 2;
    if(root->l == nullptr) {
        root->l = new Node();
        root->l->min = l;
        root->l->max = mid;
    }
    if(root->r == nullptr) {
        root->r = new Node();
        root->r->min = mid + 1;
        root->r->max = r;
    }
}

void update(Node* root, int l, int r, int l1, int r1, int val) {
    if(l1 > r || l > r1) {
        return;
    }
    if(l1 <= l && r <= r1) {
        root->min += val;
        root->max += val;
        root->adding += val;
        return;
    }
    push(root, l, r);
    int mid = l + ((ll)r - l) / 2;
    update(root->l, l, mid, l1, r1, val);
    update(root->r, mid + 1, r, l1, r1, val);
    root->min = min(root->l->min, root->r->min) + root->adding;
    root->max = max(root->l->max, root->r->max) + root->adding;
}

int find_left(Node* root, int l, int r, int val, int adding=0) {
    if(l == r) {
        return l;
    }
    push(root, l, r);
    int mid = l + ((ll)r - l) / 2;
    adding += root->adding;
    if(root->l->max + adding >= val) {
        return find_left(root->l, l, mid, val, adding);
    }
    return find_left(root->r, mid + 1, r, val, adding);
}
int find_right(Node* root, int l, int r, int val, int adding=0) {
    if(l == r) {
        return l;
    }
    push(root, l, r);
    int mid = l + ((ll)r - l) / 2;
    adding += root->adding;
    if(root->r->min + adding <= val) {
        return find_right(root->r, mid + 1, r, val, adding);
    }
    return find_right(root->l, l, mid, val, adding);
}
ll get_el(Node* root, int l, int r, int pos) {
    if(l == r) {
        return root->max;
    }
    push(root, l, r);
    int mid = l + ((ll)r - l) / 2;
    if(mid >= pos) {
        return get_el(root->l, l, mid, pos) + root->adding;
    }
    return get_el(root->r, mid + 1, r, pos) + root->adding;
}

const int mod = 1000000001;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    Node* root = new Node();
    root->min = -MAX;
    root->max = MAX;
    int lastans = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int k;
        cin >> k;
        int left = find_left(root, -MAX, MAX, t);
        int right = find_right(root, -MAX, MAX, t);
        update(root, -MAX, MAX, -MAX, left - 1, 1);
        update(root, -MAX, MAX, right + 1, MAX, -1);
        for(int j = 0; j < k; j++) {
            int x1;
            cin >> x1;
            int x = ((ll)lastans + x1 + mod + mod + mod) % mod;
            lastans = get_el(root, -MAX, MAX, x);
            cout << lastans << '\n';
        }
    }

}