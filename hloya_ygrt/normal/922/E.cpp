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
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
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
const long double eps = 1e-12;
const int maxn = (int)1e4 + 12, base = 998244353;
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

ll dp[maxn];//, ndp[maxn];

struct rmqueue {
    vector<pair<ll, ll> > left_st, right_st; // global, current
    rmqueue(){}

    void refresh() {
        while (!right_st.empty()) {
            ll x = right_st.back().s;
            right_st.pop_back();
            left_st.pb(mp(max(left_st.empty() ? -llinf : left_st.back().f, x), x));
        }
    }

    ll front() {
        if (left_st.empty())
            return right_st.back().s;
        return left_st.back().s;
    }

    void push(ll x) {
        right_st.pb(mp(max(right_st.empty() ? -llinf : right_st.back().f, x), x));
    }
    void pop() {
        if (left_st.empty()) refresh();
        left_st.pop_back();
    }
    ll get() {
        return max(left_st.empty() ? -llinf : left_st.back().f, 
                   right_st.empty() ? -llinf : right_st.back().f);
    }
    void clear() {
        left_st.clear();
        right_st.clear();
    }
    size_t size() {
        return left_st.size() + right_st.size();
    }
};

int c[maxn], cost[maxn];

int main() {
    int n, W, B, X;
   // files1;
    cin >> n >> W >> B >> X; 

    for (int i = 0; i < maxn; i++) dp[i] = -llinf;
    dp[0] = W;

    rmqueue q;
        
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    int ans = -1;
    for (int i = 0; i < n; i++) {
        // cin >> c[i] >> cost[i];
        ll added = 0;
        q.clear();

        for (int j = 0; j < maxn; j++) {
            // if (i == 1 && j == 2) {
            //     cout << dp[j] - added;;
            //     return 0;
            // }
            q.push((dp[j] != -llinf ? dp[j] : dp[j]) - added);
            dp[j] = -llinf;
            if (q.size() > c[i] + 1) q.pop();
            // if (i == 1 && j == 6) {
            //     cout << q.front();;
            //     return 0;
            // }
            // cout << q.size() << endl;

            dp[j] = q.get();
            // if (j == 6) {
            //     cout << q.get();
            //     return 0;
            // }
            if (dp[j] != -llinf) {
                dp[j] += added;
                if (dp[j] < 0) {
                    dp[j] = -llinf;
                } else {
                    if (i == n - 1) {
                        amax(ans, j);
                    } else {
                        dp[j] += X;
                        dp[j] = min(dp[j], 1ll * j * B + 1ll * W);
                    }
                }
            }

            // if (i == 1) {
            //     cout << dp[j] << endl;
            // }
            added -= cost[i];
        }
        // return 0;
    }
    
    cout << ans;
    // for (int j = 0; j < maxn; j++) {
    //     if (dp[j] >= X)
    //         ans = max(ans, j);
    // }
    // cout << ans;
    return 0;
}