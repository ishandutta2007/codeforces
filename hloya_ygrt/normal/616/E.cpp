// hloya template v18

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
// #define ld long double
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
const double eps = 1e-9;
const int maxn = 5e2 + 10, base = 1e9 + 7;
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

ll inv2 = binpow<ll>(2, base - 2);

ll sum(ll r) {
    if (r <= 0)
        return 0LL;
    return ((r % base) * ((r + 1) % base) % base) * inv2 % base;
}

ll sum(ll l, ll r) {
    return (sum(r) - sum(l - 1) + base) % base;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll f = (n % base) * (m % base) % base, s = 0;

    ll banana = sqrt(n);

    for (ll i = 1; i <= min(m, banana); i++) {
        s += i * (n / i) % base;
        if (s >= base)
            s -= base;
    }

    ll mnkek = llinf;

    for (ll i = 1; i <= banana; i++) {
        ll L = n / (i + 1) + 1, R = n / i;
        R = min(R, m);
        L = max(L, banana + 1);
        if (L > R)
            continue;
        mnkek = min(mnkek, L);

        ll e = sum(L, R);
        e = (e * i) % base;

        s += e;
        if (s >= base)
            s -= base;
    }
    // cerr << banana << ' ' << mnkek << endl;
    // files2;
    // cout << s << endl;
    cout << (f - s + base) % base << endl;
    return 0;
}