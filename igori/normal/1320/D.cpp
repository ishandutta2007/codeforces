#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

ll inq(ll x, ll y, ll mod)
{
    if (!y) re 1 % mod;
    ll l = inq(x, y / 2, mod);
    if (y % 2) re l * l % mod * x % mod;
    re l * l % mod;
}

ll inv(ll x, ll mod)
{
    return inq(x, mod - 2, mod);
}

const int N = 405949; // 405949 is my favorite number, but it's less than 5e5
const int P = 1e9 + 97;
const int Q = 1e6 + 3;
const int INV = inv(Q, P);

int n;
string s;
int deg[N];

struct Value{
    int sl, sr, len, cnt;
    long long h;
    operator == (Value B)
    {
        return sl == B.sl && sr == B.sr && len == B.len && h == B.h && cnt == B.cnt;
    }
};
Value Tree[4 * N];

Value Merge(Value A, Value B)
{
    Value C;
    if (!A.len) return B;
    if (!B.len) return A;
    C.sl = A.sl;
    C.sr = B.sr;
    if (A.sr && B.sl)
    {
        if (A.len == 1 && B.len == 1) return {0, 0, 0, 0, 0};
        if (A.len == 1)
        {
            C.sl = 0, C.sr = B.sr;
            C.len = B.len - 1;
            C.cnt = B.cnt - 1;
            C.h = (B.h + P - deg[B.len - 1]) % P;
            return C;
        }
        if (B.len == 1)
        {
            C.sl = A.sl, C.sr = 0;
            C.len = A.len - 1;
            C.cnt = A.cnt - 1;
            C.h = (A.h - 1 + P) * INV % P;
            return C;
        }
        C.len = A.len + B.len - 2;
        C.cnt = A.cnt + B.cnt - 2;
        A.h = (A.h - 1 + P) * INV % P;
        B.h = (B.h + P - deg[B.len - 1]) % P;
        C.h = (A.h * deg[B.len - 1] + B.h) % P;
        return C;
    }
    else
    {
        C.len = A.len + B.len;
        C.cnt = A.cnt + B.cnt;
        C.h = (A.h * deg[B.len] + B.h) % P;
        return C;
    }
    cout << "Fail" << endl;
    cout << "Check correctness" << endl;
    exit(0);
}

void Build(int L = 0, int R = n, int V = 0)
{
    if (L + 1 < R)
    {
        int M = (L + R) / 2;
        Build(L, M, 2 * V + 1);
        Build(M, R, 2 * V + 2);
        Tree[V] = Merge(Tree[2 * V + 1], Tree[2 * V + 2]);
    }
    else
    {
        Tree[V].sl = s[L] - '0';
        Tree[V].sr = s[L] - '0';
        Tree[V].h = s[L] - '0';
        Tree[V].len = 1;
        Tree[V].cnt = s[L] - '0';
    }
}

Value Get(int l, int r, int L = 0, int R = n, int V = 0)
{
    if (l <= L && R <= r)
    {
        return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return {0, 0, 0, 0, 0};
    }
    int M = (L + R) / 2;
    return Merge(Get(l, r, L, M, 2 * V + 1), Get(l, r, M, R, 2 * V + 2));
}

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    deg[0] = 1;
    for (int i = 1; i < N; i++) deg[i] = 1ll * deg[i - 1] * Q % P;
    cin >> n;
    cin >> s;
    Build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l1, l2, t;
        cin >> l1 >> l2 >> t;
        l1--, l2--;
        if (Get(l1, l1 + t) == Get(l2, l2 + t))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}