#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';

    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }

    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 4e5 + 5, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<int> g[maxn];
int sz[maxn], tin[maxn], timer, tout[maxn], n;
int P[maxn], L[maxn], R;
bool need[maxn];

vector<pair<int, int> > sortedSizes;

void getsz(int v, int p = -1) {
    tin[v] = timer++;
    P[v] = p;

    int res = 1;
    for (int to:g[v])
        if (to != p)
            getsz(to, v), res += sz[to];
    sz[v] = res;

    if (sz[v] <= R)
        sortedSizes.push_back(mp(sz[v], tin[v]));
    tout[v] = timer;
}

multiset<int> parentWay;
int answer[maxn];

void dfs(int v, int p = -1) {
    if (p != -1)
        parentWay.insert(n - sz[v]);

    if (!answer[v] && need[v]) {
        auto res = parentWay.lower_bound(L[v]);
        if (res != parentWay.end() && (*res) <= R)
            answer[v] = 1;
    }

    for (int to:g[v])
        if (p != to)
            dfs(to, v);

    if (p != -1)
        parentWay.erase(parentWay.find(n - sz[v]));
}

// calc_from_root
int from_root[maxn];

int fw[maxn];
void add(int x, int v) { while (x<=n + 1)fw[x]+=v, x+=x&(-x); }
int  sum(int r) { int s=0; while(r) s+=fw[r],r-=r&(-r);return s;}

void dfs2(int v, int p = -1) {
    if (need[v]) {
        from_root[v] = sum(R) - sum(L[v] - 1);
    }

    add(sz[v], 1);

    for (int to:g[v])
        if (to != p)
            dfs2(to, v);
    add(sz[v], -1);
}
//

struct Query
{
    int L, l, r, v;
    Query(int L, int l, int r, int v):L(L), l(l), r(r), v(v) {}

    bool operator < (const Query & T) const
    {
        return L < T.L || (L == T.L && v < T.v);
    }
};

vector<Query> ask;

void print(pii a) {
    cout << a.f << ' ' << a.s << endl;
}

int main (){
    //files1;
    read(n);
    R = n / 2;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        read(a, b);
        a--, b--;

        g[a].pb(b);
        g[b].pb(a);
    }

    getsz(0);

    for (int v = 0; v < n; v++) {
        int p = P[v];

        pair<int, int> maxx = mp(-1, -1), minn = mp(inf, -1);
        for (int to:g[v])
            if (to != p) {
                minn = min(minn, mp(sz[to], to));
                maxx = max(maxx, mp(sz[to], to));
            }
        if (p != -1) {
            minn = min(minn, mp(n - sz[v], p));
            maxx = max(maxx, mp(n - sz[v], p));
        }

        if (maxx.first * 2 <= n)
            answer[v] = 1;
        else {
            L[v] = (maxx.first - R);

            if (maxx.second == p) {
                ask.pb(Query(L[v], 0, tin[v] - 1, v));
                ask.pb(Query(L[v], tout[v], n, v));
                need[v] = 1;
            } else {
                if (tin[maxx.s] != tout[maxx.s] - 1)
                ask.pb(Query(L[v], tin[maxx.s], tout[maxx.s] - 1, v));
            }
        }
    }


    sort(ask.rbegin(), ask.rend());
    sort(sortedSizes.begin(), sortedSizes.end());

    dfs2(0);

    int lastAdded = sortedSizes.size();

    for (int j = 0; j < ask.size(); j++) {
        auto i = ask[j];
        int v = i.v, l = i.l, r = i.r;

        while (lastAdded &&
               sortedSizes[lastAdded - 1].first >= L[v]) {
            add(sortedSizes[lastAdded - 1].second + 1, 1), lastAdded--;
        }

        int cnt = sum(r + 1) - sum(l);
        if (j != ask.size() - 1 && ask[j + 1].v == v) { // if need(v)
            l = ask[j + 1].l, r = ask[j + 1].r;
            cnt += sum(r + 1) - sum(l);
            j++;
            cnt -= from_root[v];
        }

        answer[v] |= (cnt != 0);
    }

    dfs(0);
    for (int i = 0; i < n; i++)
        cout << answer[i] << ' ';
    return 0;
}