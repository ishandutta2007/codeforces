// hloya template v22

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

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes = -1){cout << mes;exit(0);}

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
const int maxn = 1e6 + 12, base = 1e9 + 7;
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

int dp[2][1<<20][21];

int main() {
    int n;
    string s;
    //files1;
    cin >> n >> s;

    for (int i = 0; i < s.size(); i++)
        s[i] -= '0';

    int ans = 0, nwdig, num, rmask;

    int t = 0;
    int nmxmask = 0, mxmask = 0;

    for (int j = 0; j < n; j++) {
        if (s[j] == 0) {
            dp[t][0][0]++;
            if (dp[t][0][0] >= base)
                dp[t][0][0] -= base;
        } else {
            dp[t][0][1]++;
            if (dp[t][0][1] >= base)
                dp[t][0][1] -= base;
        }
        for (int mask = 0; mask <= mxmask; mask++) {
            for (int last = 0; last <= 20; last++) {
                if (!dp[t][mask][last])
                    continue;
                if (last != 0)
                    rmask = mask | (1 << (last - 1));
                else rmask = 0;

                if (rmask != 0 && (rmask & (rmask + 1)) == 0) {
                    // if (dp[t][mask][last])
                        // cout << i << ' ' << j << ' ' << dp[t][mask][last] << endl;
                    ans += dp[t][mask][last];
                    if (ans >= base)
                        ans -= base;
                }
                if (j == n - 1)
                    continue;

                num = s[j + 1];
                if (last != 0) {
                    dp[t ^ 1][mask | (1 << (last - 1))][num] += dp[t][mask][last];
                    if (dp[t ^ 1][mask | (1 << (last - 1))][num] >= base)
                        dp[t ^ 1][mask | (1 << (last - 1))][num] -= base;
                    nmxmask = max(nmxmask, mask | (1 << (last - 1)));
                }

                num = last * 2 + s[j + 1];
                if (num > 20) {
                    dp[t][mask][last] = 0;
                    continue;
                }
                dp[t^1][mask][num] += dp[t][mask][last];
                if (dp[t ^ 1][mask][num] >= base)
                    dp[t ^ 1][mask][num] -= base;
                dp[t][mask][last] = 0;
            }
        }
        mxmask = nmxmask;
        t^=1;
    }
    
    cout << ans;
    return 0;
}