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
const int maxn = (int)2e5 + 450, base = 998244353;
const ll llinf = 2e18 + 5;
const int mod = 1e9 + 7;

int main() {
    // files1;
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> d1 (n);
        int l=0, r=-1;

        for (int i=0; i<n; ++i) {
          int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
          while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
          d1[i] = k;
          if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
        }
        vector<int> d2 (n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
          int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
          while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
          d2[i] = k;
          if (i+k-1 > r)
            l = i-k,  r = i+k-1;
        }

        pair<int, int> pos;
        int ans = 0;

        int mc = 0;
        for (int i = 0, j = n - 1; i < j && s[i] == s[j]; i++, j--) {
            mc++;
        }

        for (int i = 0; i < n; i++) {
            int a = i - d1[i] + 1, b = i + d1[i] - 1;
            int L = b - a + 1;
            int l = a;
            int r = n - 1 - b;

            int mn = min(l, r);
            if (mn <= mc && L + 2 * mn <= n) {
                if (upmax(ans, L + 2 * mn)) {
                    pos = mp(i, 1);
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (d2[i]) {
                int a = i - d2[i], b = i + d2[i] - 1;
                int L = b - a + 1;
                int l = a;
                int r = n - 1 - b;
                
                int mn = min(l, r);
                if (mn <= mc && L + 2 * mn <= n) {
                    if (upmax(ans, L + 2 * mn)) {
                        pos = mp(i, 2);
                    }
                }
            }
        }
        
        if (pos.second == 1) {
            int i = pos.first;

            int a = i - d1[i] + 1, b = i + d1[i] - 1;
            int L = b - a + 1;
            int l = a;
            int r = n - 1 - b;

            int mn = min(l, r);

            string p, q;
            for (int i = a; i <= b; i++) {
                p += s[i];
            }
            cout << s.substr(0, mn) << p << s.substr(n - mn) << "\n";
        } else {
            int i = pos.first;
            
            int a = i - d2[i], b = i + d2[i] - 1;
            int L = b - a + 1;
            int l = a;
            int r = n - 1 - b;
            
            int mn = min(l, r);

            string p, q;
            for (int i = a; i <= b; i++) {
                p += s[i];
            }
            cout << s.substr(0, mn) << p << s.substr(n - mn) << "\n";
        }
    }
    return 0;
}