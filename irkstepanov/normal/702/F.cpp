#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

mt19937 rr(random_device{}());

const int inf = 1e9 + 10;

struct node
{
    int val, pri, maxx, promise, add, id, added;
    node* left;
    node* right;
    node(int id_, int val_)
    {
        val = val_;
        pri = rr();
        maxx = val_;
        promise = 0;
        add = 0;
        added = 0;
        id = id_;
        left = right = nullptr;
    }
};

bool comp(const pii& a, const pii& b)
{
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int get_maxx(node* v)
{
    return (v == nullptr ? -inf : v->maxx);
}

void update(node* v)
{
    v->maxx = max(v->val, max(get_maxx(v->left), get_maxx(v->right)));
}

void push(node* v)
{
    if (v->left != nullptr) {
        v->left->val -= v->promise;
        v->left->maxx -= v->promise;
        v->left->promise += v->promise;
        v->left->add += v->add;
        v->left->added += v->add;
    }
    if (v->right != nullptr) {
        v->right->val -= v->promise;
        v->right->maxx -= v->promise;
        v->right->promise += v->promise;
        v->right->add += v->add;
        v->right->added += v->add;
    }
    v->add = 0;
    v->promise = 0;
}

pair<node*, node*> split(node* v, int key) // < key go left
{
    if (v == nullptr) {
        return mp(nullptr, nullptr);
    }
    push(v);
    if (v->val >= key) {
        pair<node*, node*> p = split(v->left, key);
        v->left = p.second;
        update(v);
        return mp(p.first, v);
    } else {
        pair<node*, node*> p = split(v->right, key);
        v->right = p.first;
        update(v);
        return mp(v, p.second);
    }
}

node* merge(node* a, node* b)
{
    if (a != nullptr) {
        push(a);
    }
    if (b != nullptr) {
        push(b);
    }
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

node* insert(node* v, node* u)
{
    if (v == nullptr) {
        return u;
    }
    push(v);
    if (v->pri > u->pri) {
        if (v->val < u->val) {
            v->right = insert(v->right, u);
            update(v);
            return v;
        } else {
            v->left = insert(v->left, u);
            update(v);
            return v;
        }
    }
    pair<node*, node*> p = split(v, u->val);
    u->left = p.first;
    u->right = p.second;
    update(u);
    return u;
}

node* add_and_decrease(node* v, int val)
{
    if (v == nullptr) {
        return nullptr;
    }
    v->val -= val;
    v->maxx -= val;
    v->promise += val;
    ++v->add;
    ++v->added;
    return v;
}

void destroy(node* v, vector<node*>& ans)
{
    if (v == nullptr) {
        return;
    }
    push(v);
    if (v->left != nullptr) {
        destroy(v->left, ans);
    }
    if (v->right != nullptr) {
        destroy(v->right, ans);
    }
    ans.pb(v);
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int q;
    scanf("%d", &q);
    vector<pii> v(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(all(v), comp);

    int n;
    scanf("%d", &n);
    node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, new node(i, val));
    }

    //cout << root->left->val << "\n";

    for (int i = 0; i < q; ++i) {
        int val = v[i].first;
        pair<node*, node*> p1 = split(root, val);
        pair<node*, node*> p2 = split(p1.second, 2 * val);
        //if (i == 0) cout << "0 : " << p2.second->val << "\n";
        p2.second = add_and_decrease(p2.second, val);
        //if (i == 0) cout << "0 : " << p2.second->val << "\n";
        //if (i == 1) cout << "1 : " << p2.first->left->val << "\n";
        vector<node*> t;
        //cout << get_maxx(p1.first) << " " << get_maxx(p2.first) << " " << get_maxx(p2.second) << "\n";
        destroy(p2.first, t);
        for (int j = 0; j < sz(t); ++j) {
            ++t[j]->added;
            t[j]->val -= val;
            t[j]->maxx -= val;
            t[j]->left = t[j]->right = nullptr;
            p1.first = insert(p1.first, t[j]);
        }
        root = merge(p1.first, p2.second);
    }

    vector<node*> t;
    vector<int> ans(n);
    destroy(root, t);
    for (int i = 0; i < sz(t); ++i) {
        //cout << t[i]->id << " " << t[i]->val << "\n";
        ans[t[i]->id] = t[i]->added;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

}