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
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
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
const int maxn = 1e6 + 5, base = 1e9 + 7;
const int sigm = 26;
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

int up[maxn][30];
int d[maxn], p[maxn];

vector<int> g[maxn];

int tin[maxn], tout[maxn];
int timer;

void dfs(int v) {
    tin[v] = ++timer;
    up[v][0] = p[v];

    for (int i = 1; i < 30; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int to:g[v]) {
        if (to != p[v])
            dfs(to);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=29; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dist(int a, int b) {
    int anc = lca(a, b);
    return d[a] + d[b] - 2 * d[anc];
}

int main() {
    //files1;
    int n;
    read(n);

    n *= 2;
    n += 4;

    for (int v = 1; v < 4; v++) {
        p[v] = 0;
        d[v] = d[p[v]] + 1;
        g[v].pb(p[v]);
        g[p[v]].pb(v);
    }

    for (int v = 4; v < n; v += 2) {
        read(p[v]);
        p[v]--;
        d[v] = d[p[v]] + 1;
        g[v].pb(p[v]);
        g[p[v]].pb(v);
        
        p[v + 1] = p[v];
        d[v + 1] = d[p[v + 1]] + 1;
        g[v + 1].pb(p[v + 1]);
        g[p[v + 1]].pb(v + 1);
    }

    dfs(0);

    int x = 0, y = 0, mxd = 0;
    for (int i = 1; i < n; i++) {
        int d1 = dist(i, x);
        int d2 = dist(i, y);

        if (d1 > mxd) {
            mxd = d1;
            y = i;
        }
        if (d2 > mxd) {
            mxd = d2;
            x = i;
        }

        if (i > 3 && i % 2)
        printf("%d\n", mxd);
    }
    return 0;
}