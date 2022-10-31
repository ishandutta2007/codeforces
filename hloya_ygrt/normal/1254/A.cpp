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
 
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);
 
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
const int maxn = (int)4e5 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
 
int binpow(int a, int s) { 
    int res = 1;
    while (s) {
        if (s % 2) {
            res = 1ll * res * a % base;
        }
        a = 1ll * a * a % base;
        s /= 2;
    }
    return res;
}

vector<int> pts[1005];
int col[105][105];
char c[105][105];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int cc = 0;
    for (int i = 0; i < n; i++) {
        pts[i].clear();
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'R') {
                cc++;
                pts[i].pb(j);
            }
        }
    }

    int g = cc / k;
    int c1 = k - cc % k;
    int cur = 0;
    int cnt = 0;

    int ord = 0;

    for (int i = 0; i < n; i++) {
        if (pts[i].empty()) {
            if (i > 0) {
                for (int j = 0; j < m; j++) {
                    col[i][j] = col[i - 1][j];
                }
            } else {
                for (int j = 0; j < m; j++) {
                    col[i][j] = 0;
                }
            }
            continue;
        }
        if (ord == 0) {
            for (int j = 0; j < m; j++) {
                col[i][j] = cur;
                if (c[i][j] == 'R') {
                    cnt++;
                    if (cnt == g) {
                        cur++;
                        cnt = 0;
                        c1--;

                        if (c1 == 0) {
                            g++;
                            c1 = inf;
                        }
                    }
                }
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                col[i][j] = cur;
                if (c[i][j] == 'R') {
                    cnt++;
                    if (cnt == g) {
                        cur++;
                        cnt = 0;
                        c1--;

                        if (c1 == 0) {
                            g++;
                            c1 = inf;
                        }
                    }
                }
            }
        }
        ord ^= 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int ca = col[i][j];

            upmin(ca, k - 1);
            
            if (ca < 26) {
                cout << char(ca + 'a');
            } else if (ca < 52) {
                cout << char(ca - 26 + 'A');
            } else {
                cout << char(ca - 52 + '0');
            }

            if (j == m - 1) {
                cout << endl;
            }
        }
}

int main() {
    // files1;
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}