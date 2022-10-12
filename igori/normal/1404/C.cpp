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

const int N = 405060;
const int INF = 1e9;

int n, q;
int a[N];

struct ask{
    int x, y;
    int id;
};

ask asks[N];

int ans[N];

bool comp(ask a, ask b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int fenw[N];

void add(int pos, int x)
{
    while (pos < N)
    {
        fenw[pos] += x;
        pos |= (pos + 1);
    }
}

int get(int pos)
{
    int res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

pair<int, int> wtree[4 * N];
int push[4 * N];

void Push(int V)
{
    wtree[2 * V + 1].first += push[V];
    push[2 * V + 1] += push[V];
    wtree[2 * V + 2].first += push[V];
    push[2 * V + 2] += push[V];
    push[V] = 0;
}

pair<int, int> Merge(pair<int, int> a, pair<int, int> b)
{
    if (a.first <= b.first) return a;
    return b;
}

void Build(int L = 0, int R = n, int V = 0)
{
    if (L + 1 == R)
    {
        wtree[V] = {0, L};
        return;
    }
    int M = (L + R) / 2;
    Build(L, M, 2 * V + 1);
    Build(M, R, 2 * V + 2);
    wtree[V] = Merge(wtree[2 * V + 1], wtree[2 * V + 2]);
}

void Add(int l, int r, int x, int L = 0, int R = n, int V = 0)
{
    if (r <= L || R <= l) return;
    if (l <= L && R <= r)
    {
        wtree[V].first += x;
        push[V] += x;
        return;
    }
    Push(V);
    int M = (L + R) / 2;
    Add(l, r, x, L, M, 2 * V + 1);
    Add(l, r, x, M, R, 2 * V + 2);
    wtree[V] = Merge(wtree[2 * V + 1], wtree[2 * V + 2]);
    //cout << L << " " << R << " " << wtree[V].first << " " << wtree[V].second << "\n";
}

pair<int, int> Get(int L = 0, int R = n, int V = 0)
{
    return wtree[0];
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < q; i++)
    {
        cin >> asks[i].x >> asks[i].y;
        asks[i].id = i;
    }
    sort(asks, asks + q, comp);

    Build();

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= i && i - c <= a[i])
        {
            Add(i, i + 1, a[i] - (i - c));
            add(i, 1);
            c++;
        }
        else
        {
            Add(i, i + 1, INF);
        }
    }
    int j = 0;
    for (int st = 0; st < n; st++)
    {
        while (j < q && asks[j].x == st)
        {
            ans[asks[j].id] = get(n - asks[j].y - 1);
            j++;
        }
        Add(st, st + 1, -1);
        //cout << "Block " << st << endl;
        //cout << Get().first << " " << Get().second << "\n";
        while (Get().first < 0)
        {
            int pos = Get().second;
            add(pos, -1);
            Add(pos, pos + 1, INF);
            Add(pos, n, -1);
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/