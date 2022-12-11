#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

mt19937 rr(random_device{}());

struct node
{
    int key;
    int id;
    int size;
    int pri;
    int maxx;
    node* left;
    node* right;
    node(int key, int id) : id(id), key(key), size(1), pri(rr()), maxx(key), left(nullptr), right(nullptr) {}
};

int get_size(node* v)
{
    return (v == nullptr ? 0 : v->size);
}

int get_maxx(node* v)
{
    return (v == nullptr ? -1 : v->maxx);
}

void update(node* v)
{
    v->size = 1 + get_size(v->left) + get_size(v->right);
    v->maxx = max(v->key, max(get_maxx(v->left), get_maxx(v->right)));
}

pair<node*, node*> split_by_size(node* v, int s) // last s go right
{
    if (v == nullptr) {
        return mp(nullptr, nullptr);
    }
    if (get_size(v->right) >= s) {
        pair<node*, node*> p = split_by_size(v->right, s);
        v->right = p.first;
        update(v);
        return mp(v, p.second);
    } else {
        pair<node*, node*> p = split_by_size(v->left, s - get_size(v->right) - 1);
        v->left = p.second;
        update(v);
        return mp(p.first, v);
    }
}

pair<node*, node*> split_by_key(node* v, int key) // the biggest suffix <= key
{
    if (v == nullptr) {
        return mp(nullptr, nullptr);
    }
    if (v->maxx <= key) {
        return mp(nullptr, v);
    }
    if (get_maxx(v->right) > key || v->key > key) {
        pair<node*, node*> p = split_by_key(v->right, key);
        v->right = p.first;
        update(v);
        return mp(v, p.second);
    } else {
        pair<node*, node*> p = split_by_key(v->left, key);
        v->left = p.second;
        update(v);
        return mp(p.first, v);
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

void out(node* v)
{
    if (v == nullptr) {
        return;
    }
    out(v->left);
    printf("%d ", v->id);
    out(v->right);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int a, c;
        scanf("%d%d", &a, &c);
        c = min(c, i);
        pair<node*, node*> p1 = split_by_size(root, c);
        pair<node*, node*> p2 = split_by_key(p1.second, a);
        node* v = new node(a, i + 1);
        root = merge(p1.first, merge(p2.first, merge(v, p2.second)));
    }

    out(root);
    printf("\n");

}