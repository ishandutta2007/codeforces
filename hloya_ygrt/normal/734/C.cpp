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
#define files2 freopen("magic.out","w",stdout)
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

int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    int n, m, k;
    read(n, m, k);

    int x, s;
    read(x, s);

    for (int i = 0; i < m; i++) {
        read(a[i]);
    }
    for (int i = 0; i < m; i++) {
        read(b[i]);
    }
    a[m] = x;
    b[m] = 0;
    m++;

    set<pair<int, int> > q;
    for (int i = 0; i < k; i++) {
        read(c[i]);
    }
    for (int i = 0; i < k; i++) {
        read(d[i]);
    }

    for (int i = 0; i < k; i++) {
        if (i == k - 1 || d[i + 1] != d[i]) {
            q.insert(mp(-d[i], c[i]));
        }
    }
    q.insert(mp(0, 0));

    ll ans = llinf;
    for (int i = 0; i < m; i++) {
        int l = s - b[i];
        if (l < 0)
            continue;
        auto e = q.lower_bound(mp(-l, -inf));
        assert(e != q.end());

        int f = e->s;
        int y = a[i];

        ans = min(ans, 1LL * (n - f) * y);
    }
    cout << ans;
    return 0;
}