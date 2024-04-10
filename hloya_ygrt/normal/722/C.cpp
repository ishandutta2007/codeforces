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
const int maxn = 1e5 + 12, base = 1e9 + 7;
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

int a[maxn];
ll p[maxn];

ll get(int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    set<pair<ll, int> > best;
    set<pii> segments;

    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
        p[i] = a[i];
        if (i > 0)
            p[i] += p[i - 1];
    }
    
    segments.insert(mp(n - 1, 0));
    best.insert(mp(get(0, n - 1), 0));

    for (int i = 0; i < n; i++) {
        int pos;
        read(pos);
        pos--;

        auto e = segments.lower_bound(mp(pos, -inf));

        int l = e->s, r = e->f;

        segments.erase(mp(r, l));
        best.erase(mp(get(l, r), l));

        if (l <= pos - 1) {
            segments.insert(mp(pos - 1, l));
            best.insert(mp(get(l, pos - 1), l));
        }
        if (pos + 1 <= r) {
            segments.insert(mp(r, pos + 1));
            best.insert(mp(get(pos + 1, r), pos + 1));
        }

        if (best.empty()) {
            cout << 0 << endl;
            return 0;
        }
        ll ans = (--best.end()) -> f;
        cout << ans << endl;
    }
    return 0;
}