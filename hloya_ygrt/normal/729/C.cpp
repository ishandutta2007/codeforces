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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 5e5 + 10, base = 1e9 + 7;
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

int c[maxn], v[maxn];
int n, k, s, t;
vector<int> l;
vector<pii> crs;

bool can(int m) {
    int v = crs[m].f;
    ll curT = 0;

    for (int i = 0; i < l.size(); i++) {
        if (v < l[i])
            return 0;
        if (v >= 2 * l[i]) {
            curT += l[i];
            continue;
        }
        // cout << a << ' ' << b << endl;

        curT += 2 * (l[i] - (v - l[i])) + (v - l[i]);
    }

    if (curT <= (ll)t) {
        return 1;
    }
    return 0;
}

int main() {
    // files1;
    read(n, k, s, t);

    for (int i = 0; i < n; i++) {
        read(c[i], v[i]);
    }

    vector<int> p;
    for (int i = 0; i < k; i++) {
        int x;
        read(x);
        p.pb(x);
    }
    p.pb(0);
    p.pb(s);
    sort(all(p));
    for (int i = 0; i + 1 < p.size(); i++)
        l.pb(p[i + 1] - p[i]);
    vector<pair<int, int> > tmp(n);

    for (int i = 0; i < n; i++)
        tmp[i] = mp(v[i], c[i]);
    sort(all(tmp));
    for (int i = n - 1; i >= 0; i--) {
        if (crs.empty()) {
            crs.pb(tmp[i]);
            continue;
        }
        if (crs.back().s < tmp[i].s) {
            continue;
        }
        crs.pb(tmp[i]);
    }
    reverse(all(crs));
    // can(1);
    // return 0;
    int l = 0, r = crs.size() - 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (can(m))
            r = m;
        else
            l = m;
    }
    if (can(l))
        cout << crs[l].s;
    else if (can(r))
        cout << crs[r].s;
    else
        cout << -1;
    return 0;
}