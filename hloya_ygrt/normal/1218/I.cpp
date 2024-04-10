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
const int maxn = (int)2e5 + 12;//, base = 1e9 + 7;
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

int a[2005][2005], b[2005][2005], x[2005];

int R[2005], C[2005];
vector<pii> to[4005];

void setR(int i, int val) {
    if (R[i] == -1) R[i] = val;
    else {
        if (R[i] != val) {
            bad(-1);
        }
    }
}

void setC(int i, int val) {
    if (C[i] == -1) C[i] = val;
    else {
        if (C[i] != val) {
            bad(-1);
        }
    }
}

int n;
void setCon(int r, int c, int val) {
    to[r].pb(mp(c + n, val));
    to[c + n].pb(mp(r, val)); 
}

bool used[4005];

void dfs(int v, int c) {
    // cout << v << ' ' << c << "\n";

    if (v < n) {
        setR(v, c);
    } else {
        setC(v - n, c);
    }
    if (used[v]) return;
    used[v] = 1;
    for (auto [e, kek] : to[v]) {
        dfs(e, kek ^ c);
    }
}

int main() {
    fast_io;
    // files1;
    
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            R[i] = C[j] = -1;
            a[i][j] = c - '0';
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            // cout << b[i][j];
        }


    for (int i = 0; i < n; i++) {
        char c; 
        cin >> c;
        x[i] = c - '0';
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            // a_i_j
            bool r = 0, c = 0;
            if (x[j]) {
                // r_i 
                r = 1;
            }
            if (x[i]) {
                c = 1;
            }
            if (!r && !c) {
                if (a[i][j] != b[i][j]) {
                    cout << -1;
                    return 0;
                }
                continue;
            }
            if (r && (!c)) {
                setR(i, a[i][j] != b[i][j]);
            } else if (c && (!r)) {
                // cout << i << ' ' << j << ' ' << (a[i][j] != b[i][j]) << endl;
                setC(j, a[i][j] != b[i][j]);
            } else {
                // cout << i << ' ' << j + n << ' ' << (a[i][j] != b[i][j]) << endl;;
                setCon(i, j, a[i][j] != b[i][j]);
            }
        }
    // for (int i = 0; i < n; i++) {
    //     cout << R[i] << endl;
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << C[i] << endl;
    // }
    // return 0;
    for (int i = 0; i < n; i++)
        if (!used[i] && R[i] != -1) {
            dfs(i, R[i]);
        }
    for (int i = n; i < n + n; i++) {
        if (!used[i] && C[i - n] != -1) {
            dfs(i, C[i - n]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n + n; i++) {
        if (!used[i]) dfs(i, 0);
        if (i < n) {
            sum += R[i];
        } else {
            sum += C[i - n];
        }
    }
    cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        if (R[i]) {
            cout << "row " << i << "\n";
        }
    }
    for (int i = 0; i < n; i++) {
        if (C[i]) {
            cout << "col " << i << "\n";
        }
    }
    return 0;
}