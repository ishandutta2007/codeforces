#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int treesize = 1 << 18;

const int MAX = 1000006;
const int MOD = 1000000007;
const int maxn = 200005;

struct tq
{
    int l, r, id;
};

inline bool operator<(const tq &a, const tq &b)
{
    return a.l < b.l;
}

int tree[2 * treesize];
int a[maxn];
vector<pair<int, int>> primes[maxn];
int last[MAX], rev[MAX];
int answer[maxn];
int begins[maxn];
int wh[maxn];
tq q[maxn];
vector<int> endss[maxn];
int n, m;

inline int powmod(int a, int b)
{
    int tmp = a;
    int ans = 1;
    while (b)
    {
        if (b & 1) ans = ((ll)ans * tmp) % MOD;
        tmp = ((ll)tmp * tmp) % MOD;
        b >>= 1;
    }
    return ans;
}

inline int get(int cur, int cl, int cr, int x)
{
    if (x > cr || x < cl) return 1;
    if (cl == cr) return tree[cur];
    int cm = (cl + cr) / 2;
    return ((ll)get(cur * 2, cl, cm, x) * get(cur * 2 + 1, cm + 1, cr, x) * tree[cur]) % MOD;
}

inline void mul(int cur, int cl, int cr, int l, int r, int t)
{
    if (l > cr || r < cl) return;
    if (cl >= l && cr <= r)
    {
//         cout << "in mul " << cl << ' ' << cr << ' ' << l << ' ' << r << ' ' << t << endl;
        tree[cur] = ((ll)tree[cur] * t) % MOD;
        return;
    }
    int cm = (cl + cr) / 2;
    mul(cur * 2, cl, cm, l, r, t);
    mul(cur * 2 + 1, cm + 1, cr, l, r, t);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        int cura = a[i];
        for (int j = 2; j * j <= cura; j++) if (cura % j == 0)
        {
            while (cura % j == 0) cura /= j;
            primes[i].pb({j, last[j]});
            last[j] = i + 1;
            if (rev[j] == 0) rev[j] = powmod(j, MOD - 2);
        }
        if (cura > 1)
        {
            primes[i].pb({cura, last[cura]});
            last[cura] = i + 1;
            if (rev[cura] == 0) rev[cura] = powmod(cura, MOD - 2);
        }
    }
    for (int i = 0; i < 2 * treesize; i++) tree[i] = 1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].l--, q[i].r--;
        q[i].id = i;
        endss[q[i].r].pb(i);
    }
    sort(q, q + m);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
//         cout << "i = " << i << endl;
        begins[i] = cur;
        while (cur < m && q[cur].l == i)
        {
            wh[q[cur].id] = cur;
//             cout << q[cur].id << ' ' << cur << endl;
            cur++;
        }
        mul(1, 0, treesize - 1, 0, cur - 1, a[i]);
//         cout << "mull " << 0 << ' ' << cur - 1 << ' ' << a[i] << endl;
        for (auto x : primes[i])
        {
            mul(1, 0, treesize - 1, begins[x.se], cur - 1, (1 - rev[x.fi] + MOD) % MOD);
//             cout << "mul " << x.fi << ' ' << x.se << ' ' << begins[x.se] << ' ' << cur - 1 << ' ' << (1 - rev[x.fi] + MOD) % MOD << endl;
        }
        for (auto x : endss[i])
        {
            answer[x] = get(1, 0, treesize - 1, wh[x]);
        }
    }
    for (int i = 0; i < m; i++) printf("%d\n", answer[i]);
    return 0;
}