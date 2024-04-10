// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
// #define endl '\n'
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
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-6;
const int maxn = (int)3e5 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const double PI = acos(-1.0);
 
const int mod = 1e9 + 7;
  
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
vector<pii> e;
int v[100];

int n, m;

map<pii, int> s;
int ans;

void go(int pos) {
    if (pos == n) {
        s.clear();

        for (int i = 0; i < m; i++) {
            s[minmax(v[e[i].f], v[e[i].s])] += 1;
        }

        int cc = 0;
        for (auto [k, val]: s) {
            int a = k.f, b = k.s;
            if (a == b) {
                cc++;
            } else {
                cc += min(val, 1);
            }
        }

        // if (cc == 21) {
        //     // cout << "kek" << endl;   
        //     cc = 0;     
        //     // for (int i = 0; i < n; i++) {
        //     //     cout << v[i] << ' ';
        //     // }
        //     // cout << endl;
        //     for (auto [k, val]: s) {
        //     int a = k.f, b = k.s;
        //     // cout << a << ' ' << b << ' ' << val << endl;
        //     if (a == b) {
        //         cc++;
        //     } else {
        //         cc += min(val, 2);
        //     }
        //     // cout << cc << endl;
        // }
        //     exit(0);
        // }

        upmax(ans, cc);
        return;
    }
    for (int c = 1; c <= 6; c++) {
        v[pos] = c;
        go(pos + 1);
    }
}

int main() {
    // files1;
    fast_io;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e.pb({u, v});
    }
    go(0);
    cout << ans << endl;
    return 0;
}