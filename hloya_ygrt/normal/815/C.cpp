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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
}
  
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
const int maxn = 5e3 + 12, base = 1e9 + 7;
const ll llinf = 1e18 + 5;
  
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

vector<int> g[maxn];
ll dp[maxn][maxn][2], ndp[maxn][2];
int sz[maxn];

int c[maxn], d[maxn];

void dfs(int v) {
    sz[v] = 1;

    dp[v][0][0] = 0;
    dp[v][1][0] = c[v];
    dp[v][1][1] = c[v] - d[v];

    for (int to : g[v]) {
        dfs(to);

        for (int i = 0; i <= sz[v] + sz[to]; i++)
            ndp[i][0] = ndp[i][1] = llinf;

        for (int sz1 = 0; sz1 <= sz[v]; sz1++) {
            for (int sz2 = 0; sz2 <= sz[to]; sz2++)
                for (int flag1 = 0; flag1 < 2; flag1++)
                    for (int flag2 = 0; flag2 < 2; flag2++) {
                        int cnt = sz1 + sz2;
                        ll sum = dp[v][sz1][flag1] + dp[to][sz2][flag2];
                        if (dp[v][sz1][flag1] == llinf || dp[to][sz2][flag2] == llinf)
                            continue;
                        if ((!flag1) && flag2)
                            continue;
                        amin(ndp[cnt][flag1], sum);
                    }
        }

        for (int i = 0; i <= sz[v] + sz[to]; i++)
            dp[v][i][0] = ndp[i][0], dp[v][i][1] = ndp[i][1];

        sz[v] += sz[to];

     //       if (v == 0) {
     //    puts("----");
     //    for (int i = 0; i <= sz[v]; i++)
     //        cout << dp[v][i][0] << ' ' << dp[v][i][1] << endl;
     // }

    }
        // cout << v << endl;
     
}

void gen() {
    int n = 5, b = rand() % 20 + 1;
    ofstream cout("input.txt");
    cout << n << ' ' << b << endl;
    for (int i = 0; i < n; i++) {
        int c = rand() % 10 + 2;
        int d = rand() % (c-1) + 1;
        cout << c << ' ' << d << ' ';
        if (i != 0) {
            int p = rand() % i;
            cout << p + 1;
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    // gen();

    int n, b;
    // files1;
    read(n, b);

    for (int i = 0; i < n; i++) {
        read(c[i], d[i]);
        if (i > 0) {
            int p;
            read(p);
            p--;
            g[p].pb(i);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) {
            dp[i][j][0] = dp[i][j][1] = llinf;
        }

    dfs(0);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[0][i][0] <= b || dp[0][i][1] <= b) {
            amax(ans, i);
        }
    }
    cout << ans;
    return 0;  
}