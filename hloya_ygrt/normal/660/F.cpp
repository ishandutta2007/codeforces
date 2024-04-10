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

vector<pair<ll, ll> > st;

ll f[maxn], p[maxn];
int a[maxn];

ld intr(pair<ll, ll> a, pair<ll, ll> b) {
    return (ld) (a.s - b.s) / (b.f - a.f);
}

ll vall(pair<ll, ll> a, ll x) {
    return a.f * x + a.s;
}

ll find(ll x) {
    if (st.size() == 1)
        return vall(st[0], x);
    int l = 0, r = st.size() - 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (vall(st[m + 1], x) > vall(st[m], x))
            l = m;
        else
            r = m;
    }
    return max(vall(st[l], x), vall(st[r], x));
}

int main() {
    int n;
    read(n);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        p[i] = p[i - 1] + a[i];
        f[i] = 1LL * a[i] * i + f[i - 1];
        ans = max(ans, f[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            ans = max(ans, find(-p[i]) + f[i]);
        }
        pair<ll, ll> cur = mp(i, 1LL * i * p[i] - f[i]);
        while ((st.size() >= 1 && st.back().f == cur.f && st.back().s <= cur.s) ||
               (st.size() >= 2 && intr(st[st.size() - 2], st.back()) > intr(st.back(), cur)))
            st.pop_back();
        st.pb(cur);
    }

    cout << ans << endl;
    return 0;
}