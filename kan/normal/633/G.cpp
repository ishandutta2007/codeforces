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

using tb = bitset<1000>;

const int maxn = 100005;
const int treesize = 1 << 17;

vector<int> primes;
bool bad[1005];
int tin[maxn], tout[maxn];
vector<int> gr[maxn];
int topush[2 * treesize];
tb tree[2 * treesize];
tb answer;
tb full;
int timer = 0;
int n, m;
int a[maxn];

void go(int cur, int pr)
{
    tin[cur] = timer++;
    tree[treesize + tin[cur]][a[cur] % m] = 1;
    for (auto x : gr[cur]) if (x != pr) go(x, cur);
    tout[cur] = timer - 1;
}

inline void rotate(tb &b, int x)
{
    b = ((b << x) | (b >> (m - x))) & full;
}

void push(int cur)
{
    if (topush[cur] == 0) return;
    topush[cur] %= m;
    topush[cur * 2] += topush[cur];
    topush[cur * 2 + 1] += topush[cur];
    rotate(tree[cur * 2], topush[cur]);
    rotate(tree[cur * 2 + 1], topush[cur]);
    topush[cur] = 0;
}

void add(int cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
        rotate(tree[cur], t);
        topush[cur] += t;
        return;
    }
    push(cur);
    int cm = (cl + cr) / 2;
    add(cur * 2, cl, cm, l, r, t);
    add(cur * 2 + 1, cm + 1, cr, l, r, t);
    tree[cur] = tree[cur * 2] | tree[cur * 2 + 1];
}

void get(int cur, int cl, int cr, int l, int r)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
        answer |= tree[cur];
        return;
    }
    push(cur);
    int cm = (cl + cr) / 2;
    get(cur * 2, cl, cm, l, r);
    get(cur * 2 + 1, cm + 1, cr, l, r);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i < m; i++) if (!bad[i])
    {
        primes.pb(i);
        for (int j = i * i; j < m; j += i) bad[j] = true;
    }
    for (int i = 0; i < m; i++) full[i] = 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    go(0, -1);
    for (int i = treesize - 1; i > 0; i--) tree[i] = tree[i * 2] | tree[i * 2 + 1];
//     cout << tree[1] << endl;
    int NQ;
    scanf("%d", &NQ);
    for (int q = 0; q < NQ; q++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int v, x;
            scanf("%d%d", &v, &x);
            v--;
            add(1, 0, treesize - 1, tin[v], tout[v], x % m);
        } else
        {
            int v;
            scanf("%d", &v);
            v--;
            answer.reset();
            get(1, 0, treesize - 1, tin[v], tout[v]);
//             cout << answer << endl;
            int curans = 0;
            for (auto p : primes) curans += answer[p];
            printf("%d\n", curans);
        }
    }
    return 0;
}