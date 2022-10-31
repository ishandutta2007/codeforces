    #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
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

// #include <ext/pb_ds/assoc_container.hpp> //  . 
// #include <ext/pb_ds/tree_policy.hpp> //   tree_order_statistics_node_update

// template<
//   typename Key, //  
//   typename Mapped, //     
//   typename Cmp_Fn = std::less<Key>, //  ,    <
//   typename Tag = rb_tree_tag, // ,   
//   template<
//   typename Const_Node_Iterator,
//   typename Node_Iterator,
//   typename Cmp_Fn_,
//   typename Allocator_>
//   class Node_Update = null_node_update, //   
//   typename Allocator = std::allocator<char> > // 
//   class tree;

bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mpzalupa make_pair
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
const int maxn = (int)2e5 + 1, base = 998244353;
const ll llinf = 2e18 + 5;

#define next asflkasjlf

bool f(int x, int y, int t) {
    int sum = x + y;
    if (sum < t) return false;
    return (sum >= t) && (sum - t) % 4 == 0;
}

ll a[1111][1111], dp[1111][1111], dpRow[1111][1111], dpColumn[1111][1111];
ll W[1000000 + 100];
vector<int> inds[1111][1111];
map<int, int> rows[1111], columns[1111];

void add(int x, int y, int t, int index, int e) {
    if (x + y >= t && (x + y - t) % 4 == 0) {
        a[x][y] += e;
        inds[x][y].push_back(index);
    }
}

int main() {
    // srand(time(0));
    //files1;
    fast_io;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x, y, d, t, e;
        cin >> x >> y >> d >> t >> e;
        W[i] = e;
        add(x, y, t, i, e);
        add(x + d, y - d, t + 1, i, e);
        add(x + d, y, t + 2, i, e);
        add(x, y + d, t + 3, i, e);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = 1e18 + 1e17;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int x : inds[i][j]) {
                if (rows[i].count(x)) {
                    dpRow[i][j] += W[x];
                    dpRow[i][rows[i][x]] -= W[x];
                } else {
                    rows[i][x] = j;
                    dpRow[i][j] += W[x];
                }
                if (columns[j].count(x)) {
                    dpColumn[i][j] += W[x];
                    dpColumn[columns[j][x]][j] -= W[x];
                } else {
                    columns[j][x] = i;
                    dpColumn[i][j] += W[x];
                }
            }
            ll cur = 0;
            for (int length = i; length >= 0; --length) {
                cur += dpColumn[length][j];
                if (dp[length][j] + cur - a[length][j] < dp[i][j]) {
                    dp[i][j] = dp[length][j] + cur - a[length][j];
                }
            }
            cur = 0;
            for (int length = j; length >= 0; --length) {
                cur += dpRow[i][length];
                if (dp[i][length] + cur - a[i][length] < dp[i][j]) {
                    dp[i][j] = dp[i][length] + cur - a[i][length];
                }
            }
        }
    }
    ll ans = dp[n - 1][m - 1];
    cout << ans << endl;
    return 0;
}