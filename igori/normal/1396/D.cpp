const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

struct Tree{
    vector<ll> a, b;
    int sz = 0;
    ll L;
    ll C;
    vector<ll> tree, push, mnA, mxA, sB;
    void Build(int L, int R, int V)
    {
        if (L + 1 == R)
        {
            tree[V] = a[L] * b[L] % MOD;
            mnA[V] = a[L];
            mxA[V] = a[L];
            sB[V] = b[L];
            return;
        }
        int M = (L + R) / 2;
        Build(L, M, 2 * V + 1);
        Build(M, R, 2 * V + 2);
        tree[V] = (tree[2 * V + 1] + tree[2 * V + 2]) % MOD;
        sB[V] = (sB[2 * V + 1] + sB[2 * V + 2]) % MOD;
        mnA[V] = min(mnA[2 * V + 1], mnA[2 * V + 2]);
        mxA[V] = max(mxA[2 * V + 1], mxA[2 * V + 2]);
    }
    Tree(vector<ll> _a, vector<ll> _b, ll _L)
    {
        sz = _a.size();
        tree.resize(4 * sz);
        push.resize(4 * sz, -1);
        mnA.resize(4 * sz);
        mxA.resize(4 * sz);
        sB.resize(4 * sz);
        a = _a;
        b = _b;
        L = _L;
        C = 0;
        for (int i = 0; i < b.size(); i++)
            C = (C + b[i]) % MOD;
        C = C * L % MOD;
        Build(0, sz, 0);
    }
    ll Get()
    {
        ll res = -tree[0];
        return ((C + res) % MOD + MOD) % MOD;
    }
    void Push(int V, int L, int M, int R)
    {
        if (push[V] != -1)
        {
            //cout << V << " " << push[V] << endl;
            push[2 * V + 1] = push[2 * V + 2] = push[V];
            mnA[2 * V + 1] = mnA[2 * V + 2] = push[V];
            mxA[2 * V + 1] = mxA[2 * V + 2] = push[V];
            tree[2 * V + 1] = sB[2 * V + 1] * push[V] % MOD;
            tree[2 * V + 2] = sB[2 * V + 2] * push[V] % MOD;
            push[V] = -1;
        }
    }
    void Set(int l, int r, ll x, int L, int R, int V)
    {
        //cout << l << " " << r << " " << x << " " << L << " " << R << " " << V << endl;
        int M = (L + R) / 2;
        if (L + 1 != R)
            Push(V, L, M, R);
        if (r <= L || R <= l) return;
        if (l <= L && R <= r && mxA[V] <= x)
        {
            mxA[V] = x;
            mnA[V] = x;
            tree[V] = sB[V] * x % MOD;
            push[V] = x;
            return;
        }
        if (L + 1 == R)
            return;
        Set(l, r, x, L, M, 2 * V + 1);
        if (x > mnA[2 * V + 2])
            Set(l, r, x, M, R, 2 * V + 2);
        tree[V] = (tree[2 * V + 1] + tree[2 * V + 2]) % MOD;
        mnA[V] = min(mnA[2 * V + 1], mnA[2 * V + 2]);
        mxA[V] = max(mxA[2 * V + 1], mxA[2 * V + 2]);
    }
    void Set(ll L, ll R, ll x)
    {
        Set(L, R + 1, x, 0, sz, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    int n, k, L;
    cin >> n >> k >> L;
    struct candy{
        int x, y, c, id;
    };
    vector<candy> A(n);
    for (int i = 0; i < n; i++) cin >> A[i].x >> A[i].y >> A[i].c, A[i].c--;
    sort(all(A), [&](candy A, candy B){
         return A.y < B.y;
         });
    for (int i = 0; i < n; i++) A[i].id = i;
    ll ans = 0;
    for (int lowest = 0; lowest < n; lowest++)
    {
        ll Down = A[lowest].y - (lowest ? A[lowest - 1].y : -1);
        vector<candy> omega;
        vector<set<int> > positions(k);
        for (int i = lowest; i < n; i++)
            omega.pb(A[i]);
        sort(all(omega), [&](candy A, candy B){
             return A.x < B.x;
             });
        map<int, int> S;
        int j = -1;
        vector<int> nxt(omega.size());
        vector<int> pos(n);
        for (int i = 0; i < omega.size(); i++)
        {
            pos[omega[i].id] = i;
            positions[omega[i].c].insert(i);
            while (j + 1 < omega.size() && S.size() != k)
            {
                S[omega[j + 1].c]++;
                j++;
            }
            if (S.size() != k)
            {
                j = omega.size();
            }
            nxt[i] = j;
            S[omega[i].c]--;
            if (S[omega[i].c] == 0) S.erase(omega[i].c);
        }
        //cout << lowest << endl;
        //for (int j = 0; j < omega.size(); j++)
        //    cout << nxt[j] << " ";
        //cout << endl;
        vector<ll> a(omega.size()), b(omega.size());
        for (int j = 0; j < omega.size(); j++)
        {
            if (nxt[j] == omega.size()) a[j] = L;
            else a[j] = omega[nxt[j]].x;
            b[j] = omega[j].x - (j ? omega[j - 1].x : -1);
        }
        Tree T(a, b, L);
        for (int i = n - 1; i >= lowest; i--)
        {
            ll cur = (i + 1 < n ? A[i + 1].y : L) - A[i].y;
            ll res = 0;
            res = T.Get();

            //cout << "[ " << Down << " " << cur << " " << res << "]" << endl;
            int pos_omega = pos[i];
            int color = A[i].c;
            auto it = positions[color].find(pos_omega);
            assert(it != positions[color].end());
            int Pr = -1;
            if (it != positions[color].begin())
            {
                it--;
                Pr = *it;
                it++;
            }
            int Nxt = omega.size();
            it++;
            if (it != positions[color].end())
            {
                Nxt = *it;
            }
            it--;
            T.Set(Pr + 1, pos_omega, (Nxt == omega.size() ? L : omega[Nxt].x));
            positions[color].erase(it);

            //for (int j = 0; j < omega.size(); j++)
            //    cout << nxt[j] << " ";
            //cout << endl;
            ans = (ans + cur * Down % MOD * res) % MOD;
        }
    }
    cout << ans;
}