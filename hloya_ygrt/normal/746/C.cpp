// hloya template v20
 
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
 
void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}
 
const int inf = 1e9;
const long double eps = 1e-12;
const int maxn = 2e5 + 10, base = 1e9 + 7;
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

int main() {
    int s, x1, x2;
    fast_io;
    //files1;
    cin >> s >> x1 >> x2;
    int t1, t2;
    cin >> t1 >> t2;
    int p, d;
    
    cin >> p >> d;

    ll ans = (ll) abs(x1 - x2) * t2;
    if (x1 < p) {
        if (d == -1) {
            int dist = p - x1;
            ll res = (ll) dist * t1;

            if (x2 < x1) {
                res += (ll) abs(x1 - x2) * t1;
            } else {
                res += (ll) (x1 + x2) * t1;
            }

            ans = min(ans, res);
        } else {
            int dist = s - p + s - x1;
            ll res = (ll) dist * t1;

            if (x2 < x1) {
                res += (ll) abs(x1 - x2) * t1;
            } else {
                res += (ll) (x1 + x2) * t1;
            }

            ans = min(ans, res);
        }
    } else {
        if (d == -1) {
            int dist = p + x1;

            if (p == x1) {
                ll res = 0;

                if (x2 > x1) {
                    res += (ll) (x1 + x2) * t1;
                } else {
                    res += (ll) abs(x1 - x2) * t1;
                }

                ans = min(ans, res);
                cout << ans;
                return 0;
            }

            ll res = (ll) dist * t1;

            if (x2 < x1) {
                res += (ll) (s - x1 + s - x2) * t1;
            } else {
                res += (ll) abs(x1 - x2) * t1;
            }

            ans = min(ans, res);
        } else {
            int dist = x1 - p;
            ll res = (ll) dist * t1;

            if (x2 < x1) {
                res += (ll) (s - x1 + s - x2) * t1;
            } else {
                res += (ll) abs(x1 - x2) * t1;
            }
            
            ans = min(ans, res);
        }
    }
    cout << ans;
    return 0;
}