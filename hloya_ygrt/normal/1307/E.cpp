// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v26

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
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))


#define ull unsigned long long
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
  
// mt19937_64 mt_rand(
//     chrono::system_clock::now().time_since_epoch().count()
// );

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

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

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e3 + 3, base = (int) 1e9 + 7;
const ll llinf = 2e18 + 5;

vector<pair<int,int>> cor[maxn];

int main() {
    // files1; 
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> hs(n, 0);
    for (int i = 0; i < m; i++) {
        int f, h;
        cin >> f >> h;

        int cc = 0;
        int posl = -1, posr = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == f) {
                cc++;
                if (cc == h) {
                    posl = i;
                    break;
                }
            }
        }

        cc = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == f) {
                cc++;
                if (cc == h) {
                    posr = i;
                    break;
                }
            }
        }

        if (posl != -1) {
            cor[f - 1].push_back(mp(posl, posr));
            hs[posl] = 1;
        }
    }

    int mx = 0, res = 1;
    for (int i = -1; i < n; i++) {
        if (i == -1 || hs[i]) {

            int cnt = 0;
            int prod = 1;
            for (int j = 0; j < n; j++) {
                int c1 = 0, c2 = 0, c12 = 0;
                int had = 0;
                int typehad;

                for (auto [l, r] : cor[j]) {
                    bool can1 = 0, can2 = 0;
                    if (l <= i) {
                        can1 = 1;
                    }
                    if (r > i) {
                        can2 = 1;
                    }
                    if (l == i) {
                        had = true;
                        typehad = can2;
                    }
                    if (can1 && can2) {
                        c12++;
                    } else if (can1) {
                        c1++;
                    } else if (can2) {
                        c2++;
                    }
                }

                if (c1 + c2 + c12 == 0) {
                    continue;
                }

                ll ways = 0;
                int mxtaken = 0;

                for (int t1 = 0; t1 < 2; t1++)
                    for (int t2 = 0; t2 < 2; t2++)
                        for (int t12 = 0; t12 < 4; t12++) {
                            if (t1 && c1 == 0) continue;
                            if (t2 && c2 == 0) continue;
                            if (t12 == 1 && c12 == 0) continue;
                            if (t12 == 2 && c12 == 0) continue;
                            if (t12 == 3 && c12 < 2) continue;

                            int g1 = (t1 > 0) + (t12 == 1 || t12 == 3);
                            int g2 = (t2 > 0) + (t12 == 2 || t12 == 3);
                            if (g1 > 1 || g2 > 1) {
                                continue;
                            }

                            int total = g1 + g2;
                            int ways1 = t1 == 0 ? 1 : c1;
                            int ways2 = t2 == 0 ? 1 : c2;
                            int ways3;
                            if (t12 == 0) {
                                ways3 = 1;
                            } else if (t12 == 1 || t12 == 2) {
                                ways3 = c12;
                            } else {
                                ways3 = c12 * (c12 - 1);
                            }

                            if (had) {
                                if (typehad == 0) {
                                    // c1
                                    if (t1 == 0) {
                                        continue;
                                    }
                                    ways1 = 1;
                                } else {
                                    // c12
                                    if (t12 == 1) {
                                        ways3 = 1;
                                    } else if (t12 == 3) {
                                        ways3 = c12 - 1;
                                    } else {
                                        continue;
                                    }
                                }
                            }

                            if (total > mxtaken) {
                                mxtaken = total;
                                ways = ways1 * ways2 * ways3;
                            } else if (total == mxtaken) {
                                ways += ways1 * ways2 * ways3;
                            }
                        }
                
                if (mxtaken != 0) {
                    ways %= base;
                    cnt += mxtaken;
                    prod = 1ll * prod * ways % base;
                }
            }

            if (cnt > mx) {
                mx = cnt;
                res = prod;
            } else if (cnt == mx) {
                res = (res + prod) % base;
            }
        }
    }
    if (mx == 0) {
        res = 1;
    }
    cout << mx << ' ' << res << "\n";
    return 0;
}