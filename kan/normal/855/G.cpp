#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 200005;

struct tpath
{
    int rep, sz;
    ll ansmiddle;
    int edgeleft, edgeright;
};

int p[maxn], s[maxn];
int sz[maxn], down[maxn], up[maxn], top[maxn];
vector<tpath> path, path2;
vector<int> gr[maxn];
ll dp1[maxn], dp2[maxn], ansmiddle[maxn];
int n, m;
ll answer;
int tin[maxn], tout[maxn];
int timer;

inline int find(int a)
{
    return (a == p[a] ? a : p[a] = find(p[a]));
}

inline bool isparent(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tin[b];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (s[a] > s[b]) swap(a, b);
    p[a] = b;
    if (s[a] == s[b]) s[b]++;
    if (tin[top[a]] < tin[top[b]])
    {
        sz[top[a]] += sz[top[b]];
        top[b] = top[a];
    } else
    {
        sz[top[b]] += sz[top[a]];
    }
}

void findpath(int a, int b)
{
    a = top[find(a)];
    b = top[find(b)];
//     cout << "findpath " << a << ' ' << b << endl;
    int lastdowna = 0;
    while (!isparent(a, b))
    {
        path.pb({a, sz[a], ansmiddle[a], lastdowna, n - down[a]});
        lastdowna = down[a];
        a = top[find(up[a])];
    }
    path2.clear();
    int lastdownb = 0;
    while (a != b)
    {
        path2.pb({b, sz[b], ansmiddle[b], n - down[b], lastdownb});
        lastdownb = down[b];
        b = top[find(up[b])];
    }
    path.pb({a, sz[a], ansmiddle[a], lastdowna, lastdownb});
    reverse(all(path2));
    for (auto t : path2) path.pb(t);
}

void addedge(int a, int b)
{
    if (find(a) == find(b)) return;
    path.clear();
    findpath(a, b);
    
//     cout << "addedge " << a << ' ' << b << endl;
//     for (auto t : path) cout << "(" << t.rep << ' ' << t.sz << ' ' << t.ansmiddle << ' ' << t.edgeleft << ' ' << t.edgeright << ")" << endl;
    
    // 3
    ll cnt0 = 1;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (auto t : path)
    {
        answer -= t.sz * cnt2 * 2 + (ll)t.sz * (t.sz - 1) * cnt1 * 2 + (ll)t.sz * (t.sz - 1) * (t.sz - 2);
        cnt2 += t.sz * cnt1 + (ll)t.sz * (t.sz - 1) * cnt0;
        cnt1 += t.sz * cnt0;
    }
    ll sum = cnt1;
    answer += ((ll)sum * (sum - 1) * (sum - 2));
    
//     cout << "after 3: " << answer << endl;
    
    // 2
    cnt1 = 0;
    for (auto t : path)
    {
        answer += cnt1 * (t.edgeleft - cnt1) * t.sz * 2;
        cnt1 += t.sz;
    }
    cnt1 = 0;
    for (int i = (int)path.size() - 1; i >= 0; i--)
    {
        auto &t = path[i];
        answer += cnt1 * (t.edgeright - cnt1) * t.sz * 2;
        cnt1 += t.sz;
    }

//     cout << "after 2: " << answer << endl;    
    
    // 1
    cnt1 = 0;
    cnt2 = 0;
    for (auto t : path)
    {
        answer += cnt2 * t.sz * 2;
        cnt2 += (n - t.edgeright - t.edgeleft - t.sz) * cnt1;
        cnt1 += n - t.edgeright - t.edgeleft - t.sz;
    }
    cnt1 = 0;
    cnt2 = 0;
    for (int i = (int)path.size() - 1; i >= 0; i--)
    {
        auto &t = path[i];
        answer += cnt2 * t.sz * 2;
        cnt2 += (n - t.edgeleft - t.edgeright - t.sz) * cnt1;
        cnt1 += n - t.edgeleft - t.edgeright - t.sz;
    }
//     cout << "after 1 old: " << answer << endl;
    ll ttldown1 = 0;
    ll ttldown2 = 0;
    for (auto t : path)
    {
        ll curdown = n - t.edgeleft - t.edgeright - t.sz;
        ll curdown2 = t.ansmiddle - curdown * (t.edgeleft + t.edgeright) * 2 - (ll)t.edgeleft * t.edgeright * 2;
        answer += curdown2 * (sum - t.sz);
        ttldown2 = ttldown2 + curdown2 + ttldown1 * curdown * 2;
        ttldown1 += curdown;
    }

//     cout << "after 1: " << answer << endl;
    
    for (int i = 1; i < (int)path.size(); i++) unite(path[i - 1].rep, path[i].rep);
    ansmiddle[top[find(path[0].rep)]] = ttldown2;
}

int go(int cur, int pr)
{
    down[cur] = 1;
    up[cur] = pr;
    dp1[cur] = 0;
    ansmiddle[cur] = 0;
    tin[cur] = timer++;
    for (auto t : gr[cur]) if (t != pr)
    {
        down[cur] += go(t, cur);
        answer += (ll)dp1[t] * dp1[cur] * 2;
        answer += (ll)dp1[t] * dp2[cur] * 2 + dp2[t] * dp1[cur] * 2;
        ansmiddle[cur] += (ll)dp1[t] * dp1[cur] * 2;
        answer += dp2[t] * 2;
        dp2[cur] += dp2[t];
        dp1[cur] += dp1[t];
    }
    ansmiddle[cur] += (ll)(n - down[cur]) * dp1[cur] * 2;
    dp2[cur] += dp1[cur];
    dp1[cur] += 1;
    tout[cur] = timer - 1;
//     cout << "exit " << cur << ' ' << answer << ' ' << dp1[cur] << ' ' << dp2[cur] << endl;
    return down[cur];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    go(0, -1);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        s[i] = 0;
        top[i] = i;
        sz[i] = 1;
    }
    printf("%lld\n", answer);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        addedge(a, b);
        printf("%lld\n", answer);
    }
    
    return 0;
}