#include <bits/stdc++.h>
#include <valarray>
using namespace std;

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
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}

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

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}

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
const int maxn = 2e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

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

int l[maxn], t[maxn];

int main() {
    int n;
    ll r;
    read(n), read(r);

    for (int i = 0; i < n; i++) {
        read(l[i]);
    }
    for (int j = 0; j < n; j++) {
        read(t[j]);
    }

    vector<ll> ans;
    ll res = 0;

    ll T = 0, from_last = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] > t[i])
            bad("-1");
        if (l[i] <= from_last) {
            T += l[i];
            from_last -= l[i];
            continue;
        }
        l[i] -= from_last;
        t[i] -= from_last;

        T += from_last;
        from_last = 0;

        ll f = t[i] - l[i];
        ll s = l[i] - f;
        // cout << f << ' ' << s << endl;

        if (s > 0) {
            res += (s + r - 1) / r;
            from_last = (r - s % r) % r;
            
            ll l = T + 2 * f;
            for (ll i = 0; ans.size() <= (int)1e5 && i < (s + r - 1) / r; i++) {
                ans.pb(l);
                l += r;
            }
            T += t[i];
        } else
            T += 2LL * l[i];

    }

    cout << res << endl;

    if (ans.size() <= (int)1e5)
    for (ll x:ans)
        cout << x << ' ';
    return 0;
}