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

int x[maxn], y[maxn];

ll get_ans(int i1, int i2, int i3) {
    ll mxx = max({x[i1], x[i2], x[i3]});
    ll mnx = min({x[i1], x[i2], x[i3]});
    ll mxy = max({y[i1], y[i2], y[i3]});
    ll mny = min({y[i1], y[i2], y[i3]});
    return 2ll * (mxx - mnx) + 2ll * (mxy - mny);
}

int main() {
    // files1;
    fast_io;

    int n;
    cin >> n;

    int mnx = inf, mxx = -inf, mny = inf, mxy = -inf;

    vector<pii> ax, ay;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        amin(mnx, x[i]);
        amax(mxx, x[i]);
        amin(mny, y[i]);
        amax(mxy, y[i]);
        ax.pb(mp(x[i], i));
        ay.pb(mp(y[i], i));
    }

    sort(all(ax));
    sort(all(ay));

    vector<int> best_pt;
    best_pt.pb(ax[0].s);
    best_pt.pb(ax[1].s);
    best_pt.pb(ax.back().s);
    best_pt.pb(ax[ax.size() - 2].s);
    
    best_pt.pb(ay[0].s);
    best_pt.pb(ay[1].s);
    best_pt.pb(ay.back().s);
    best_pt.pb(ay[ay.size() - 2].s);

    ll all_ans = 2ll * (mxx - mnx) + 2ll * (mxy - mny);

    ll ans3 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++)
            for (int k = j + 1; k < 8; k++) {
                int it1 = i, it2 = best_pt[j], it3 = best_pt[k];
                if (it1 != it2 && it2 != it3 && it1 != it3) {
                    ans3 = max(ans3, get_ans(it1, it2, it3));
                }
            }
    }

    cout << ans3 << ' ';
    for (int i = 4; i <= n; i++)
        cout << all_ans << ' ';
    cout << "\n";
    return 0;
}