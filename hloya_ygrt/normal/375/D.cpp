#include <algorithm>
#include <assert.h>
#include <bitset>
// #include <bits/stdc++.h>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
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
    while (!(c >= '0' && c <= '9') || c == '-') {
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
const int maxn = 1e5 + 10, base = 1e9;
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

int c[maxn], sz[maxn], ans[maxn];

vector<int> g[maxn];
vector<int> * inSub[maxn];

int tree[2 * maxn];

int getSum(int l, int r = (int)1e5 + 5, int n = (int)1e5 + 5) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (r & 1) res += tree[--r];
    }
    return res;
}

void modify(int p, int v, int n = (int)1e5 + 5) {
    for (tree[p += n] += v; p > 1; p >>= 1)
        tree[p >> 1] = tree[p] + tree[p ^ 1];
}

int cnt[maxn];
vector<pair<int, int> > query[maxn];

void getTreeSz(int v, int p = -1) {
    sz[v] = 1;
    for (int to:g[v])
        if (to != p)
            getTreeSz(to, v), sz[v] += sz[to];
}

void add(int v) {
    v = c[v];
    if (cnt[v])
        modify(cnt[v], -1);
    cnt[v]++;
        modify(cnt[v], 1);
}

void rem(int v) {
    v = c[v];
    assert(cnt[v]);
        modify(cnt[v], -1);
    cnt[v]--;
    if (cnt[v])
        modify(cnt[v], 1);
}

void dfs(int v, int p = -1, bool save = true) {
    int mxSon = -1, weight = 0;

    for (int to:g[v])
        if (to != p && sz[to] > weight)
            mxSon = to, weight = sz[to];
    for (int to:g[v])
        if (to != p && to != mxSon)
            dfs(to, v, 0);

    if (mxSon != -1)
        dfs(mxSon, v, 1), inSub[v] = inSub[mxSon];
    else
        inSub[v] = new vector<int>();

    inSub[v]->pb(v);
    add(v);

    for (int to:g[v])
        if (to != p && to != mxSon)
            for (int j:*inSub[to])
                inSub[v]->pb(j), add(j);

    // ans
    for (auto Pair:query[v]) {
        int k = Pair.first, it = Pair.second;
        ans[it] = getSum(k);
    }

    if (save == false) {
        for (int j:*inSub[v])
            rem(j);
    }
}

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < n; i++)
        read(c[i]);

    for (int i = 1; i < n; i++) {
        int f, t;
        read(f, t);
        f--, t--;

        g[f].pb(t);
        g[t].pb(f);
    }

    for (int i = 0; i < m; i++) {
        int v, k;
        read(v, k);
        v--;

        query[v].pb(mp(k, i));
    }

    getTreeSz(0);
    dfs(0);

    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}