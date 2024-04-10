#pragma GCC optimize("Ofast")
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 4e5 + 239;

inline int sum(int a, int b) {
    a += b - MOD;
    a += (a >> 31) & MOD;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    a += (a >> 31) & MOD;
    return a;
}

inline void mkadd(int &a, int b) {
    a += b - MOD;
    a += (a >> 31) & MOD;
}

inline void mksub(int &a, int b) {
    a -= b;
    a += (a >> 31) & MOD;
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

inline int power(int a, int k) {
    int ans = 1;
    while (k) {
        if (k & 1) {
            ans = mul(ans, a);
        }
        k >>= 1;
        a = mul(a, a);
    }
    return ans;
}

int fact[X], inv[X];

int getC(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

struct Node {
    int x;
    ll y;
    int add;

    Node *l;
    Node *r;

    Node(int x_) {
        x = x_;
        y = rnd();
        add = 0;
        l = nullptr;
        r = nullptr;
    }
};

void upd(Node *p) {
    if (p == nullptr) {
        return;
    }
    p->x += p->add;
    if (p->l != nullptr) {
        p->l->add += p->add;
    }
    if (p->r != nullptr) {
        p->r->add += p->add;
    }
    p->add = 0;
}

pair<Node*, Node*> split(Node* p, int x) {
    if (p == nullptr) {
        return make_pair(nullptr, nullptr);
    }
    upd(p);
    if (p->x <= x) {
        pair<Node*, Node*> t = split(p->r, x);
        p->r = t.first;
        return make_pair(p, t.second);
    } else {
        pair<Node*, Node*> t = split(p->l, x);
        p->l = t.second;
        return make_pair(t.first, p);
    }
}

Node* merge(Node* l, Node* r) {
    upd(l);
    upd(r);
    if (l == nullptr) {
        return r;
    }
    if (r == nullptr) {
        return l;
    }
    if (l->y < r->y) {
        r->l = merge(l, r->l);
        return r;
    } else {
        l->r = merge(l->r, r);
        return l;
    }
}

Node* add(Node* root, int x) {
    pair<Node*, Node*> t = split(root, x);
    return merge(t.first, merge(new Node(x), t.second));
}

int getmin(Node* p) {
    upd(p);
    if (p->l == nullptr) {
        return p->x;
    }
    return getmin(p->l);
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> bd;
    Node* root = new Node(n);
    int cnt = 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        pair<Node*, Node*> t = split(root, y - 1);
        if (getmin(t.second) != y) {
            t.second = merge(new Node(y), t.second);
            cnt++;
        }
        t.second->add += 1;
        root = merge(t.first, t.second);
    }
    cout << getC(2 * n - cnt, n) << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < X; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[X - 1] = power(fact[X - 1], MOD - 2);
    for (int i = X - 2; i >= 0; i--) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}