// hloya template v21

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

//clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}

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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 5e2 + 12, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

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

int dp[2][maxn][maxn];
int a[maxn];

void add(int& x, int y, int mod) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int main() {
    int n, m, b, mod;
    
    read(n, m, b, mod);

    int t = 0;
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++)
        read(a[i]);

    for (int i = 0; i < n; i++) {
        for (int wr = 0; wr <= m; wr++)
            for (int bg = 0; bg <= b; bg++) {
                add(dp[t^1][wr][bg], dp[t][wr][bg], mod);

                if (bg + a[i] <= b && wr != m)
                add(dp[t][wr + 1][bg + a[i]], dp[t][wr][bg], mod);
            }
        for (int wr = 0; wr <= m; wr++)
            for (int bg = 0; bg <= b; bg++) {
                // cout << i << ' ' << wr << ' ' << bg << ' ' << dp[t][wr][bg] << endl;
                dp[t][wr][bg] = 0;
            }
        // cout << endl;
        t^=1;
    }
    int ans = 0;
    for (int bg = 0; bg <= b; bg++) {
        add(ans, dp[t][m][bg], mod);
    }
    cout << ans;
    return 0;
}