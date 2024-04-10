// hloya template v24
 
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
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 4e5 + 12, base = 1e9 + 7;
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

ll tree[maxn];

void add(int pos, ll val) {
    pos++;
    while (pos < maxn) {
        amax(tree[pos], val);
        pos += pos & -pos;
    }
}

ll sum(int pos) {
    ll ans = 0;
    pos++;
    while (pos > 0) {
        amax(ans, tree[pos]);
        pos -= pos & -pos;
    }
    return ans;
}

int main() {
    //files1;
    int n;
    read(n);

    vector<int> f;
    vector<pair<int, pii> > kek;
    for (int i = 0; i < n; i++) {
        int a, b, h;
        read(a, b, h);
        // a[i]++;
        f.pb(a);
        f.pb(b);

        kek.pb(mp(b, mp(a, h)));
    }
    sort(all(f));
    map<int, int> sot;
    for (int i = 0; i < f.size(); i++)
        sot[f[i]] = i;
    for (int i = 0; i < kek.size(); i++)
        kek[i].f = -sot[kek[i].f], kek[i].s.f = -sot[kek[i].s.f];
    
    sort(all(kek));
    // reverse(all(kek));

    ll ans = 0;
    for (int i = 0; i < kek.size(); i++) {
        kek[i].f = -kek[i].f, kek[i].s.f = -kek[i].s.f;
        int that_a = kek[i].f - 1;
        ll res = sum(that_a) + kek[i].s.s;
        add(kek[i].s.f, res);
        amax(ans, res);
    }
    cout << ans;
    return 0;
}