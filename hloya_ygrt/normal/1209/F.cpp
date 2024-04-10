// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 1000;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
    
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}

struct bor {
    int val;
    vector<bor*> nxt;
    int depth;
    int rod;
    
    vector<bor*> up;

    bor() {
        rod = -1;
        nxt.assign(10, nullptr);
    }
};

bor* root = new bor;
bor* opt[N];

vector<int> prs[N];

#define all(x) (x).begin(),(x).end()
vector<pair<int,int>> g[N];

bor* makenode(bor* par, int i) {
    bor* cur = new bor();
    cur-> depth = par->depth + 1;
    cur-> val = (1ll * par->val * 10 + i) % MOD;
    cur-> up.push_back(par);
    cur-> rod = i;

    for (int i = 1; (1 << i) <= cur->depth; i++) {
        cur->up.push_back(cur->up.back()->up[i - 1]);
    }
    // exit(0);
    return cur;
}

bool better(bor* cand, bor* cur) {
    if (cur == nullptr) return true;
    if (cand->depth < cur->depth) return true;
    if (cand->depth > cur->depth) return false;

    if (cand == cur) return false;
    int mxsz = cand->up.size();
    for (int i = mxsz - 1; i >= 0; i--) {
        if (i >= cand->up.size()) continue;
        if (cand->up[i] != cur->up[i]) {
            cand = cand->up[i];
            cur  = cur->up[i];
        }
    }
    assert(cand->rod != cur->rod);
    // exit(0);
    return cand->rod < cur->rod;
}

int32_t main()
{
    root->val = 0;
    root->depth = 0;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int y = i + 1;
        while (y) {
            prs[i + 1].pb(y % 10);
            y /= 10;
        }
        reverse(all(prs[i + 1]));

        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(mp(v, i + 1));
        g[v].pb(mp(u, i + 1));
    }

    opt[0] = root;
    set<pair<int, int>> q;
    q.insert(mp(0, 0));

    vector<int> used(n, 0);

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if (used[v]) continue; // fixme ?
        used[v] = 1;

        bor* cur = opt[v];
        assert(cur != nullptr);

        for (auto& [to, val] : g[v]) {
            bor* mda = cur;
            for (int i : prs[val]) {
                if (mda->nxt[i] != nullptr) {
                    mda = mda->nxt[i];
                } else {
                    mda->nxt[i] = makenode(mda, i);

                    mda = mda->nxt[i];
                }
            }

            if (better(mda, opt[to])) {
                opt[to] = mda;
                q.insert(mp(opt[to]->depth, to));
            }
        }
    }

    for (int i = 1; i < n; i++) {
        assert(opt[i] != nullptr);
        cout << opt[i]->val << "\n";
    }
    return 0;
}