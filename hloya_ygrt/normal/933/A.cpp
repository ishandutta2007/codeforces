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
const int maxn = (int)5e4 + 12, base = 1e9 + 7;
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

int a[2001];
int p[2001];
int s[2001];
int dp[2001][2001];
int cnt[2001][2001][2];

int main() {
    int n;
    fast_io;
    // files1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = n - 1; i >= 0; i--) {
        int mx[2] = {0, 0};
        for (int j = i; j >= 0; j--) {
            // dp[i][j] = 
            if (a[j] == 0)
                dp[i][j] = mx[0] + 1;
            if (a[j] == 1)
                dp[i][j] = max(mx[0], mx[1]) + 1;
            amax(mx[a[j]], dp[i][j]);
        }
    }

    int mx[2] = {0, 0};
    for (int j = 0; j < n; j++) {
        if (a[j] == 0)
            p[j] = mx[0] + 1;
        if (a[j] == 1)
            p[j] = max(mx[0], mx[1]) + 1;
        amax(mx[a[j]], p[j]);
    }

    mx[0] = mx[1] = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (a[j] == 1)
            s[j] = mx[1] + 1;
        if (a[j] == 0)
            s[j] = max(mx[0], mx[1]) + 1;
        amax(mx[a[j]], s[j]);
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                cnt[i][j][k] = 0;
                if (j != i)
                    cnt[i][j][k] += cnt[i][j - 1][k];
                if (a[j] == k)
                    cnt[i][j][k]++;
            }
    }

    int ans = p[n - 1];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            amax(ans, (i > 0 ? cnt[0][i - 1][0] : 0) + (j + 1 < n ? cnt[j + 1][n - 1][1] : 0) +
                               dp[j][i]);
        }
    cout << ans;
    return 0;
}