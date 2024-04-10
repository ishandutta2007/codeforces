#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <unordered_map>
#include <unordered_set>
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
const int maxn = 1e5 + 1, base = 1e9 + 7;
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

int cnt[maxn], verColor[maxn];

vector<int> * inSub[maxn], g[maxn];
map<int, ll> tree;

void add(int color) {
    int& curCnt = cnt[color];
    if (curCnt != 0) {
        tree[curCnt] -= color;
        if (tree[curCnt] == 0)
            tree.erase(curCnt);
    }
    curCnt++;
    tree[curCnt] += color;
}

void remove(int color) {
    int& curCnt = cnt[color];
    tree[curCnt] -= color;
    if (tree[curCnt] == 0)
        tree.erase(curCnt);

    curCnt--;

    if (curCnt != 0)
    tree[curCnt] += color;
}

ll getResult() {
    if (tree.empty())
        assert(0);
    return (--tree.end())->second;
}

ll answers[maxn];
int sz[maxn] = {-1};

void dfs(int v, int p = -1, int keep = 1) {
    cerr << v << endl;
    assert(sz[v] != -1);
    int mx = -1, heavySon = -1;
    
    for (int to:g[v])
        if (to != p && sz[to] > mx)
            mx = sz[to], heavySon = to;
    for (int to:g[v])
        if (to != p && to != heavySon)
            dfs(to, v, 0);

    if (heavySon != -1)
        dfs(heavySon, v, 1), inSub[v] = inSub[heavySon];
    else
        inSub[v] = new vector<int>();
    for (int to:g[v])
        if (to != p && to != heavySon)
            for (int newVer:*inSub[to]) {
                add(verColor[newVer]);
                inSub[v] -> push_back(newVer);
            }

    inSub[v] -> push_back(v);
        // if (v == 3)
        // exit(0);
    add(verColor[v]);

    answers[v] = getResult();
    if (keep == 0)
        for (int x:*inSub[v])
            remove(verColor[x]);
}

int getSz(int v, int p = -1) {
    int res = 1;
    for (int to:g[v])
        if (to != p)
            res += getSz(to, v);
    return sz[v] = res;
}
int main() {
    fast_io;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> verColor[i];

    for (int i = 1; i < n; i++) {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].pb(t);
        g[t].pb(f);
    }

    getSz(0);
    dfs(0);

    for (int i = 0; i < n; i++)
        cout << answers[i] << ' ';
    return 0;
}