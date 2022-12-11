#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define forn(i, n) for (int (i) = 0; (i) < n; ++(i))
#define ford(i, n) for (int (i) = (n) - 1; (i) >= 0; --(i))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

mt19937 rr(random_device{}());

struct node
{
    int size;
    int val;
    int pri;
    int start;
    node* left;
    node* right;
    node(int start, int val = -1) : size(1), val(val), pri(rr()), start(start), left(nullptr), right(nullptr) {}
};

// 1-indexed

int get_size(node* v)
{
    return (v == nullptr ? 0 : v->size);
}

void update(node* v)
{
    v->size = 1 + get_size(v->left) + get_size(v->right);
}

pair<node*, node*> split(node* v, int key) // first key go left
{
    if (v == nullptr) {
        return mp(nullptr, nullptr);
    }
    if (get_size(v->left) >= key) {
        pair<node*, node*> p = split(v->left, key);
        v->left = p.second;
        update(v);
        return mp(p.first, v);
    } else {
        pair<node*, node*> p = split(v->right, key - get_size(v->left) - 1);
        v->right = p.first;
        update(v);
        return mp(v, p.second);
    }
}

node* merge(node* a, node* b)
{
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    if (a->pri > b->pri) {
        a->right = merge(a->right, b);
        update(a);
        return a;
    } else {
        b->left = merge(a, b->left);
        update(b);
        return b;
    }
}

int res;
int start;

node* erase(node* v, int key)
{
    if (v == nullptr) {
        return nullptr;
    }
    if (get_size(v->left) >= key) {
        v->left = erase(v->left, key);
        update(v);
        return v;
    } else if (get_size(v->left) + 1 == key) {
        res = v->val;
        start = v->start;
        v = merge(v->left, v->right);
        return v;
    } else {
        v->right = erase(v->right, key - get_size(v->left) - 1);
        update(v);
        return v;
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, q;
    scanf("%d%d", &n, &q);

    node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = merge(root, new node(i + 1));
    }

    vector<int> init_pos(n + 1, -1);

    while (q--) {
        int val, pos;
        scanf("%d%d", &val, &pos);
        root = erase(root, pos);
        if (res != -1 && res != val) {
            printf("-1\n");
            return 0;
        }
        if (init_pos[val] != -1 && init_pos[val] != start) {
            printf("-1\n");
            return 0;
        }
        if (res == -1) {
            init_pos[val] = start;
        }
        root = merge(new node(start, val), root);
    }

    vector<int> ans(n + 1, -1);
    vector<int> empty;
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (init_pos[i] != -1) {
            ans[init_pos[i]] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            empty.pb(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (init_pos[i] == -1) {
            ans[empty[pos++]] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }

}