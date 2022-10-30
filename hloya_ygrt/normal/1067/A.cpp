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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e5 + 12, base = 1e9 + 7;
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

int a[maxn];

const int mod = 998244353; // toodo
ll dp[2][205][2];

void add(int arr, int l, int r, int flag, ll val) {
    if (l > r) return;
    dp[arr][l][flag] += val;
    dp[arr][r + 1][flag] -= val;
}

int main() {
    int n;
    // files1;
    fast_io;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cur_t = 0;

    dp[cur_t][0][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 201; j++)
            for (int k = 0; k < 2; k++)
                dp[cur_t ^ 1][j][k] = 0;

        for (int pre = 0; pre <= 200; pre++) {
            if (a[i] == -1) {
                // 1 -> [1; pre] -> 1
                add(cur_t^1, 1, pre, 1, dp[cur_t][pre][1]);
                add(cur_t^1, pre + 1, 200, 0, dp[cur_t][pre][1]);

                if (pre != 0)
                    add(cur_t^1, pre, pre, 1, dp[cur_t][pre][0]);
                add(cur_t^1, pre + 1, 200, 0, dp[cur_t][pre][0]);
            } else {
                bool flag = pre >= a[i];
                add(cur_t^1, a[i], a[i], flag, dp[cur_t][pre][1]);

                bool flag2 = a[i] >= pre;
                if (flag2)
                    add(cur_t^1, a[i], a[i], flag, dp[cur_t][pre][0]);
            }
        }

        cur_t ^= 1;
        for (int i = 1; i <= 200; i++) {
            dp[cur_t][i][0] = (dp[cur_t][i][0] + dp[cur_t][i - 1][0]) % mod;
            dp[cur_t][i][1] = (dp[cur_t][i][1] + dp[cur_t][i - 1][1]) % mod;
            if (dp[cur_t][i][0] < 0)
                dp[cur_t][i][0] += mod;
            if (dp[cur_t][i][1] < 0)
                dp[cur_t][i][1] += mod;
            // cout << dp[cur_t][i][0] << ' ' << dp[cur_t][i][1] << endl;
        }
    }

    ll ans = 0;
    for (int last = 1; last <= 200; last++) {
        ans += dp[cur_t][last][1];
        ans %= mod;
        if (ans < 0)
            ans += mod;
    }
    cout << ans << endl;
    return 0;
}