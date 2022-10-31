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
const int maxn = 1e6 + 500;
const int mod = 258280327;

int main() {
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    fast_io;

    int t;
    cin >> t;
    // t = 100000;

    while (t--) {
        int n;
        cin >> n;
        
        vector<uint32_t> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<vector<uint32_t>> pa, pb;
        pa.push_back(a);
        pb.push_back(b);
        
        uint32_t ans = 0;

        for (int i = 29; i >= 0; i--) {
            uint32_t oxb = 1u << i;
            bool ok_all = true;
            vector<vector<uint32_t>> new_pa, new_pb;
            for (int j = 0; j < pa.size(); j++) {
                vector<uint32_t> a0, a1, b0, b1;
                for (int k = 0; k < pa[j].size(); k++) {
                    if (pa[j][k] & oxb) {
                        a1.push_back(pa[j][k]);
                    } else {
                        a0.push_back(pa[j][k]);
                    }
                    if (pb[j][k] & oxb) {
                        b1.push_back(pb[j][k]);
                    } else {
                        b0.push_back(pb[j][k]);
                    }
                }
                if (a0.size()) new_pa.push_back(a0);
                if (a1.size()) new_pa.push_back(a1);
                if (b1.size()) new_pb.push_back(b1);
                if (b0.size()) new_pb.push_back(b0);
                ok_all &= a0.size() == b1.size();
            }
            if (ok_all) {
                ans |= oxb;
                pa = new_pa;
                pb = new_pb;
            }
            
        }
        cout << ans << "\n";;
    }
    return 0;
}