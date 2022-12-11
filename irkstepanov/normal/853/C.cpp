#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct node {
    int sum;
    node* left;
    node* right;
    node() : sum(0), left(nullptr), right(nullptr) {}
    node(node* other) {
        sum = other->sum;
        left = other->left;
        right = other->right;
    }
};

vector<node*> roots;

node* build(node* v, int tl, int tr) {
    if (tl == tr) {
        return v;
    }
    int tm = (tl + tr) >> 1;
    v->left = new node();
    v->left = build(v->left, tl, tm);
    v->right = new node();
    v->right = build(v->right, tm + 1, tr);
    return v;
}

void update(node* v, int tl, int tr, int pos) {
    ++v->sum;
    if (tl == tr) {
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        node* u = new node(v->left);
        v->left = u;
        update(v->left, tl, tm, pos);
    } else {
        node* u = new node(v->right);
        v->right = u;
        update(v->right, tm + 1, tr, pos);
    }
}

int get(node* v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return v->sum;
    }
    int ans = 0;
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        ans += get(v->left, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        ans += get(v->right, tm + 1, tr, max(l, tm + 1), r);
    }
    return ans;
}

int n;

ll f(int x, int y, int a, int b) {
    int k = get(roots[b], 1, n, x, y) - get(roots[a - 1], 1, n, x, y);
    return ll(k) * ll(k - 1) / 2;
}

ll solve(int x, int y, int d, int u) {
    ll ans = 0;
    ans += f(x, y, 1, n);
    if (d > 1) {
        ans -= f(x, y, 1, d - 1);
    }
    if (u + 1 < n) {
        ans -= f(x, y, u + 1, n);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int q;
    cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    node* root = new node();
    roots.pb(build(root, 1, n));

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        roots.pb(new node(roots.back()));
        update(roots.back(), 1, n, pos[i]);
    }

    while (q--) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        ll ans = 0;
        ans += solve(1, n, d, u);
        if (l > 1) {
            ans -= solve(1, l - 1, d, u);
        }
        if (r < n) {
            ans -= solve(r + 1, n, d, u);
        }
        cout << ans << "\n";
    }

}