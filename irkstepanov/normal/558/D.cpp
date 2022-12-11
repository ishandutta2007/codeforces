#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int amax = 200500;
const int inf = 1e9;

struct node
{
    node* left;
    node* right;
    ll val;
    node(ll val) : left(nullptr), right(nullptr), val(val) {}
};

node* root;

void recursive(node* v)
{
    if (v->left != nullptr) {
        recursive(v->left);
        v->left = nullptr;
    }
    if (v->right != nullptr) {
        recursive(v->right);
        v->right = nullptr;
    }
}

void update(node* v, ll tl, ll tr, ll l, ll r)
{
    if (tl == l && tr == r) {
        v->val = 0;
        recursive(v);
        return;
    }
    if (v->val == 0) {
        return;
    }
    ll tm = (tl + tr) >> 1;
    if (v->left == nullptr) {
        v->left = new node(v->val / 2);
    }
    if (v->right == nullptr) {
        v->right = new node(v->val / 2);
    }
    if (l <= tm) {
        update(v->left, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        update(v->right, tm + 1, tr, max(l, tm + 1), r);
    }
    v->val = v->left->val + v->right->val;
}

ll get(node* v, ll tl, ll tr)
{
    if (tl == tr) {
        return tl;
    }
    ll tm = (tl + tr) >> 1;
    if (v->left != nullptr && v->left->val == 1) {
        return get(v->left, tl, tm);
    } else {
        return get(v->right, tm + 1, tr);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int h, q;
    scanf("%d%d", &h, &q);
    --h;
    ll maxx = (1LL << (h + 1)) - 1;
    root = new node(1LL << h);

    while (q--) {
        int k;
        ll a, b;
        int ans;
        scanf("%d%I64d%I64d%d", &k, &a, &b, &ans);
        while (a * 2 <= maxx) {
            a *= 2;
        }
        while (b * 2 + 1 <= maxx) {
            b = b * 2 + 1;
        }
        if (ans == 1) {
            if (a != (1LL << h)) {
                update(root, (1LL << h), maxx, (1LL << h), a - 1);
            }
            if (b != maxx) {
                update(root, (1LL << h), maxx, b + 1, maxx);
            }
        } else {
            update(root, (1LL << h), maxx, a, b);
        }
    }

    if (root->val < 1) {
        cout << "Game cheated!\n";
        return 0;
    }
    if (root->val > 1) {
        cout << "Data not sufficient!\n";
        return 0;
    }

    cout << get(root, (1LL << h), maxx);

}