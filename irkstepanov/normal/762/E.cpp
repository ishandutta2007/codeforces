#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rr(random_device{}());

struct data
{
    int x, r, f;
    bool operator<(const data& other) const
    {
        if (r != other.r) {
            return r < other.r;
        }
        return x < other.x;
    }
};

bool comp(const data& a, const data& b)
{
    return a.x < b.x;
}

struct node
{
    int key;
    int size;
    int pri;
    node* left;
    node* right;
    node(int key) : key(key), size(1), pri(rr()), left(nullptr), right(nullptr) {}
};

int getSize(node* v)
{
    return (v == nullptr ? 0 : v->size);
}

void update(node* v)
{
    v->size = 1 + getSize(v->left) + getSize(v->right);
}

pair<node*, node*> split(node* v, int key) // <= key go left
{
    if (v == nullptr) {
        return {nullptr, nullptr};
    }
    if (v->key <= key) {
        pair<node*, node*> p = split(v->right, key);
        v->right = p.first;
        update(v);
        return {v, p.second};
    } else {
        pair<node*, node*> p = split(v->left, key);
        v->left = p.second;
        update(v);
        return {p.first, v};
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

node* erase(node* v, int key)
{
    if (v == nullptr) {
        return nullptr;
    }
    if (v->key == key) {
        v = merge(v->left, v->right);
        return v;
    }
    if (v->key > key) {
        v->left = erase(v->left, key);
        update(v);
        return v;
    } else {
        v->right = erase(v->right, key);
        update(v);
        return v;
    }
}

const int ff = 1e4 + 100;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<data> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].r >> v[i].f;
    }

    sort(all(v), comp);

    vector<node*> a(ff, nullptr);
    for (int i = 0; i < n; ++i) {
        a[v[i].f] = merge(a[v[i].f], new node(v[i].x));
    }

    sort(all(v));

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        int lf = v[i].x - v[i].r;
        int rg = v[i].x + v[i].r;
        for (int f = max(0, v[i].f - k); f <= v[i].f + k; ++f) {
            pair<node*, node*> p1 = split(a[f], lf - 1);
            pair<node*, node*> p2 = split(p1.second, rg);
            ans += getSize(p2.first);
            p1.second = merge(p2.first, p2.second);
            a[f] = merge(p1.first, p1.second);
        }
        a[v[i].f] = erase(a[v[i].f], v[i].x);
    }

    cout << ans - n << "\n";

}