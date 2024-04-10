// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <list>
 
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
  
#include <bits/stdc++.h>
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
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
void upmax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void upmin(T& x, T y) {
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
  
const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-6;
const int maxn = (int)3e5 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const double PI = acos(-1.0);
 
const int mod = 998244353;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}

int a[85][85];

vector<int> path;

int n, k;
ll ans = llinf;

bool ban[85];
vector<pair<int, int>> srt[80][80];

void solve() {
    for (int i = 0; i < path.size(); i++) {
        ban[path[i]] = 1;
    }

    long long res = 0;
    for (int i = 0; i + 1 < path.size(); i++) {
        int u = path[i];
        int v = path[i + 1];
        bool ok = false;

        for (int k = 0; k < srt[u][v].size(); k++) {
            int t = srt[u][v][k].second;
            if (ban[t]) {
                continue;
            }
            ok = true;
            res += srt[u][v][k].first;
            break;
        }
        if (!ok) {
            for (int i = 0; i < path.size(); i++) {
                ban[path[i]] = 0;
            }
            return;
        }
    }
    ans = min(ans, res);

    for (int i = 0; i < path.size(); i++) {
        ban[path[i]] = 0;
    }
}

void dfs(int pos) {
    if (pos == k) {
        path.push_back(0);
        solve();
        path.pop_back();
        return;
    }
    for (int j = 0; j < n; j++) {
        path.push_back(j);
        dfs(pos + 2);
        path.pop_back();
    }
}

int main() {
    fast_io;
    // files1;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                srt[i][j].push_back(make_pair(a[i][k] + a[k][j], k));
            }
            sort(all(srt[i][j]));
        }

    path.push_back(0);
    dfs(2);
    cout << ans;
    return 0;
}