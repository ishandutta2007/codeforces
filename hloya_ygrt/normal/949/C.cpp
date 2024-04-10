// hloya template v25
  
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
  
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <map>
#include <cstring>
#include <queue>
#include <iomanip>
#include <time.h>
// #Include
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
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
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-15;
const int maxn = (int)1e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
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

vector<int> g[maxn], gr[maxn];
bool used[maxn];

int u[maxn];

vector<int> cmp, order;

void dfs1(int v) {
    used[v] = 1;
    for (int to : g[v])
        if (!used[to]) dfs1(to);
    order.pb(v);
}

void dfs2(int v) {
    used[v] = 1;
    cmp.pb(v);
    for (int to : gr[v])
        if (!used[to]) dfs2(to);
}

int comp[maxn], sz[maxn];

int main() {
    int n, m, h;
    // files1;
    fast_io;
    read(n, m, h);
    for (int i = 0; i < n; i++) {
        read(u[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        read(a, b);
        a--, b--;

        if (u[a] + 1 == u[b] || (u[a] == h - 1 && u[b] == 0)) {
            g[a].pb(b);
            gr[b].pb(a);
        }
        swap(a, b);
        if (u[a] + 1 == u[b] || (u[a] == h - 1 && u[b] == 0)) {
            g[a].pb(b);
            gr[b].pb(a);
        }
    }

    memset(used, 0, sizeof(used));

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    memset(used, 0, sizeof(used));

    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        if (!used[v]) {
            cmp.clear();
            dfs2(v);
            
            for (int j : cmp) {
                comp[j] = v;
                sz[v]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int to : g[i])
            if (comp[to] != comp[i]) {
                sz[comp[i]] = 0;
            }
    }

    int res = inf, ans;
    for (int i = 0; i < n; i++) {
        if (sz[i] > 0 && sz[i] < res) {
            res = sz[i];
            ans = i;
        }
    }
    cout << res << endl;
    for (int i = 0; i < n; i++)
        if (comp[i] == ans)
            cout << i + 1 << ' ';
    return 0;
}