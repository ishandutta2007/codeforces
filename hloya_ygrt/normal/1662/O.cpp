#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

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

#define files1 freopen("decomposable.in","r",stdin)
#define files2 freopen("decomposable.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "NO"){cout << mes;exit(0);}
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
const long double eps = 1e-12;
const ll llinf = 2e18 + 5;
const int maxn = 2e5 + 500;
const int mod = 258280327;

bool used[22][360];
bool iscban[22][360], isrban[22][360];

void solve() {
    int n;
    cin >> n;

    std::vector<tuple<int, int, int>> cban, rban;

    memset(iscban, 0, sizeof(iscban));
    memset(isrban, 0, sizeof(isrban));

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
            int r, t1, t2;
            cin >> r >> t1 >> t2;
            cban.emplace_back(r, t1, t2);

            if (t1 < t2) {
                for (int t = t1; t < t2; t++) {
                    iscban[r][t] = 1;
                }
            }
            else {
                for (int t = t1; t < 360; t++) {
                    iscban[r][t] = 1;
                }
                for (int t = 0; t < t2; t++) {
                    iscban[r][t] = 1;   
                }
            }
        } else {
            int r1, r2, t;
            cin >> r1 >> r2 >> t;
            rban.emplace_back(r1, r2, t);

            for (int r = r1; r < r2; r++) {
                isrban[r][t] = 1;
            }
        }
    }

    memset(used, 0, sizeof(used));

    queue<pair<int, int>> q;
    for (int i = 0; i < 360; i++) {
        q.push({0, i});
        used[0][i] = 1;
    }

    while (!q.empty()) {
        auto [r, t] = q.front();
        q.pop();

        // go to r+1

        if (r + 1 < 22 && !iscban[r + 1][t] && !used[r + 1][t]) {
            used[r + 1][t] = 1;
            q.push({r + 1, t});
        }
        // go to r-1
        if (r - 1 >= 0 && !iscban[r][t] && !used[r - 1][t]) {
            used[r-1][t] = 1;
            q.push({r-1, t});
        }
        // go to t+1
        int nt = (t + 1) % 360;
        if (!isrban[r][nt] && !used[r][nt]) {
            used[r][nt] = 1;
            q.push({r, nt});
        }
        // go to t-1
        int nt2 = (t - 1 + 360) % 360;
        if (!isrban[r][t] && !used[r][nt2]) {
            used[r][nt2] = 1;
            q.push({r, nt2});
        }
    }

    cout << (used[21][0] ? "YES" : "NO") << "\n";
}

int main() {
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}