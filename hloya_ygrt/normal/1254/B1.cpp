// #pragma GCC optimize("unroll-loops")
 
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
const int maxn = (int)1e6 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
 
int binpow(int a, int s) { 
    int res = 1;
    while (s) {
        if (s % 2) {
            res = 1ll * res * a % base;
        }
        a = 1ll * a * a % base;
        s /= 2;
    }
    return res;
}

ll a[maxn], x[maxn];

int main() {
    // files1;
    fast_io;

    int n;
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    if (sum == 1) {
        cout << -1;
        return 0;
    }   

    vector<ll> cand;

    for (ll i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            cand.pb(i);
            while (sum % i == 0) {
                sum /= i;
            }
        }
    }

    ll ans = llinf;
    if (sum != 1) {
        cand.pb(sum);
    }

    for (ll c : cand) {
        ll re = 0;

        // cout << c << endl;

        for (int i = 0; i < n; i++) {
            a[i] = x[i] % c;

            // cout << a[i] << ' ';
        }

        // cout << endl;

        ll cur = 0;
        int lpos = 0;

        for (int i = 0; i < n; i++) {
            ll oldre = re;
            re += a[i];
            if (re >= c) {
                ll old = c - oldre;
                a[i] = old;

                {
                    ll cntle = 0;
                    ll sumposle = 0;
                    ll sum2 = 0;
                    ll need = (c + 1) / 2;

                    // cout << cntle << ' ' << sumposle << ' ' << sum << ' ' << need << endl;

                    for (int j = lpos; j <= i; j++) {
                        assert(j < n && j >= 0);
                        sum2 += a[j];
                        if (sum2 >= need) {
                            ll sumposgre = 0, cntgre = 0;
                            for (int k = j + 1; k <= i; k++) {
                                sumposgre += 1ll * k * a[k];
                                cntgre += a[k];
                            }
                            cur += 1ll * j * cntle - sumposle;
                            cur += sumposgre - 1ll * j * cntgre;
                            break;
                        } else {
                            cntle += a[j];
                            sumposle += 1ll * j * a[j];
                        }
                    }
                }

                re -= c;
                a[i] = re;
                lpos = i;
            }
        }
        upmin(ans, cur);
    }

    cout << ans << endl;
}