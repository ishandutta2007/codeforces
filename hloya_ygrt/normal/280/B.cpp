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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

struct trie {
    vector<int> sz, mxSub, numbers;
    vector<pair<int, int> > to;
    trie() {
        sz.pb(0);
        mxSub.pb(0);
        to.pb(mp(0, 0));   
    }
    int node() {
        sz.pb(0);
        mxSub.pb(0);
        to.pb(mp(0, 0));
        return to.size() - 1;
    }
    void recalc(int v) {
        int mx = 0;
        if (to[v].f && sz[to[v].f])
            mx = max(mx, mxSub[to[v].f]);
        if (to[v].s && sz[to[v].s])
            mx = max(mx, mxSub[to[v].s]);
        mxSub[v] = mx;
    }
    void add(ll x, int y = 1) {
        if (y == 1) {
            numbers.pb(x);
        } else {
            numbers.pop_back();
        }

        vector<int> used;
        int v = 0;
        for (int i = 30; i >= 0; i--) {
            used.pb(v);
            if (x & (1 << i)) {
                if (!to[v].s) {
                    int y = node();
                    to[v].s = y;
                }
                v = to[v].s;
            } else {
                if (!to[v].f) {
                    int y = node();
                    to[v].f = y;
                }
                v = to[v].f;
            }
            sz[v] += y;
        }
        mxSub[v] = numbers.size() - 1;
        for (int i = used.size() - 1; i >= 0; i--) {
            recalc(used[i]);
        }
    }
    void erase(ll x) {
        add(x, -1);
    }

    ll get(int v) {
        assert(mxSub[v] < numbers.size());
        return numbers[mxSub[v]];
    }

    ll query(ll x) {
        int v = 0;
        ll ans = 0;

        for (int i = 30; i >= 0; i--) {
            if (x & (1 << i)) {
                if (to[v].f && sz[to[v].f] && get(to[v].f) < x) {
                    v = to[v].f;
                    ans += 1<<i;
                }else
                    v = to[v].s;
            } else {
                if (to[v].s && sz[to[v].s] && get(to[v].s) < x) {
                    v = to[v].s;
                    ans += 1<<i;
                } else
                    v = to[v].f;
            }
        }

        return ans;
    }
} bor;

ll solve(int n) {
    bor = trie();
    vector<pair<int, int> > st;
    st.pb(mp(inf, -1));
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (i && a[i - 1] < a[i]) {
            ans = max(ans, bor.query(a[i]));
            // if (ans == 133322863) {
            //     cout << i << endl;
            //     return 0;
            // }
        }

        while (st.back().f < a[i]) {
            bor.erase(st.back().f);
            st.pop_back();
        }

        bor.add(a[i]);
        st.pb(mp(a[i], i));
    }

    return ans;
}

int main() {
    //files1;
    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
    }
    
    ll x = solve(n);
    reverse(a, a + n);
    // // dbg = 1;
    x = max(x, solve(n));
    // return 0;
    cout << x;
    return 0;
}