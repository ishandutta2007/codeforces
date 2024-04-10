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
const int maxn = (int)2e6 + 12, base = 1e9 + 7;
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

int lp[(int)2e6];

int dp[2][maxn];
int lg[maxn];

int mnSt[maxn][23];
int n = (int)1e6 + 100;

void buildMn() {
    for (int i = 0; i < n; i++)
        mnSt[i][0] = dp[0][i];
    for (int i = 1; i < 23; i++)
        for (int j = 0; j + (1 << i) <= n; j++) {
            mnSt[j][i] = min(
                mnSt[j][i - 1],
                mnSt[j + (1 << (i - 1))][i - 1]);
        }
}

int get_min(int l, int r) {
    int j = lg[r - l + 1];
    return min(
        mnSt[l][j],
        mnSt[r - (1 << j) + 1][j]);
}

int main() {    
    for (int i = 2; i < maxn; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    int x;
    fast_io;
    // files1;
    cin >> x;   
    for (int i = 2; i < (int)2e6; i++)
        if (lp[i] == 0) {
            for (int j = i; j < (int)2e6; j += i)
                if (lp[j] == 0)
                    lp[j] = i;
        }

    for (int i = 0; i < 2; i++) {
        for (int y = 2; y <= (int)1e6; y++) {
            dp[i][y] = inf;

            int x = y;
            int x2 = x, last_p = 0;
            while (x >= 2) {
            
                int p = lp[x];
                x /= p;
                
                if (p == last_p) {
                    continue;
                }

                last_p = p;

                int k2 = x2 / p;

                int l = max(p + 1, (k2 - 1) * p + 1), r = min(x2, k2 * p);

                // if (i == 1 && y == 14) {
                    // cout << p << endl;
                    // cout << l << ' ' << r << endl;
                // }

                if (i == 0) {
                    if (l <= r)
                        amin(dp[i][y], l);
                    else {
                        // cerr << l << ' ' << r << endl;
                        // cerr << i << ' ' << y << endl;
                        dp[i][y] = inf;
                    }
                } else {
                    // if (i == 1)
                    dp[i][y] = get_min(l, r);
                }
                // for (int x1 = ; x; x1++) {
                //     int cur_k = (x1 + p - 1) / p;
                //     if (cur_k == x2 / p) {
                //         if (i == 0)
                //             amin(dp[i][y], x1);
                //         else {
                //             amin(dp[i][y], dp[i - 1][x1]);
                //         }
                //     }
                // }

                // if (dp[i][y] == )


            }

            // cout << i << ' ' << y << ' ' << dp[i][y] << endl;
        }

        if (i == 0) {
            buildMn();
        }
    }
    cout << dp[1][x];
    return 0;
}