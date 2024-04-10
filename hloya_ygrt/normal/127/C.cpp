// hloya template v23

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

// clock_t start_time = clock();
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

const int inf = 2e9 + 20;
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

ll __ceil(ll x, ll y) {
    return (x + y - 1) / y;
}
int t1, t2, x1, x2, t0;

bool cmp(pair<int, ll>& a, pair<int, ll>& b) {
    return 1ll * (1ll * t1 * a.f + 1ll * t2 * a.s) * (b.f + b.s) < 1ll * (1ll * t1 * b.f + 1ll * t2 * b.s) * (a.f + a.s);
}

bool eq(pair<int, ll>& a, pair<int, ll>& b) {
    return 1ll * (1ll * t1 * a.f + 1ll * t2 * a.s) * (b.f + b.s) == 1ll * (1ll * t1 * b.f + 1ll * t2 * b.s) * (a.f + a.s);
}

int main() {
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    if (t1 == t2) {
        cout << x1 << ' ' << x2;
        return 0;
    }
    if (t1 == t0) {
        cout << x1 << ' ' << 0;
        return 0;
    }
    if (t2 == t0) {
        cout << 0 << ' ' << x2;
        return 0;
    }

    bool f1 = 0;
    pair<int, ll> ans;

    for (int y1 = 0; y1 <= x1; y1++) {
        ll y2 = (1ll * t0 * y1  - 1ll * t1 * y1) / (t2 - t0);
        for (ll rly2 = y2; rly2 <= y2 + 5; rly2++) {
            if (rly2 + y1 == 0)
                continue;
            if (rly2 <= x2) {
                if (1ll * t0 * (y1 + rly2) > 1ll * t1 * y1 + 1ll * t2 * rly2)
                    continue;
                if (f1 == 0) {
                    f1 = 1; ans = mp(y1, rly2);
                } else {
                    pair<int, ll> nans = mp(y1, rly2);
                    if (eq(ans, nans) && y1 + rly2 > ans.f + ans.s) {
                        ans = nans;
                    }
                    if (cmp(nans, ans))
                        ans = nans;
                }
            }
        }
    }

    assert(f1);
    cout << ans.f << ' ' << ans.s << endl;
    return 0;
}