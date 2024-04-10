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
    int len = 0;

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
const int maxn = 1e5 + 5, base = 1e9 + 7;
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

vector<int> g[maxn];
int timer, tin[maxn], tout[maxn], height[maxn]; 

int anc[maxn][20];

vector<pair<int, int> > onLayer[maxn];

void dfs(int v, int p, int h = 0) {
    tin[v] = ++timer;
    height[v] = h;

    anc[v][0] = p;
    for (int i = 1; i < 20; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];

    onLayer[h].push_back(make_pair(tin[v], v));

    for (int to:g[v])
        if (to != p)
            dfs(to, v, h + 1);

    tout[v] = ++timer;
}

int lift(int v, int len) {
    for (int i = 0; i < 20 && v != -1; i++)
        if (len & (1 << i))
            v = anc[v][i];
    return v;
}

int findOnLayer(int layer, int v) {
    int L = tin[v], R = tout[v];
    int lpos = upper_bound(onLayer[layer].begin(), onLayer[layer].end(), mp(L, -100))
             - onLayer[layer].begin();
    int rpos = upper_bound(onLayer[layer].begin(), onLayer[layer].end(), mp(R, -100))
             - onLayer[layer].begin() - 1;
    return rpos - lpos + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> roots;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0)
            roots.push_back(i);
        else {
            --x;
            g[x].pb(i);
            g[i].pb(x);
        }
    }

    memset(anc, -1, sizeof(anc));

    for (int i:roots)
        dfs(i, -1);
    int m;
    scanf("%d", &m);


    for (int i = 0; i < m; i++) {
        int v, p;
        scanf("%d %d", &v, &p);

        v--;

        if (height[v] - p < 0) {
            printf("0\n");
            continue;
        }        

        v = lift(v, p);

        int ans = findOnLayer(height[v] + p, v) - 1;
        printf("%d\n", ans);
    }
    return 0;
}