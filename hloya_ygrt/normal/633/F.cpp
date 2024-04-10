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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

vector<int> g[maxn];
int a[maxn];

ll ans = 0;

ll mxDown[maxn], mxIn[maxn];

template<typename T>
void amax(T & x, T y) {
    x = max(x, y);
}

void dfs1(int v, int p = -1) {
    mxIn[v] = mxDown[v] = a[v];

    vector<ll> best;

    for (int to:g[v]) {
        if (to != p) {
            dfs1(to, v);
            amax(mxDown[v], mxDown[to] + a[v]);
            amax(mxIn[v], mxIn[to]);

            best.pb(mxDown[to]);
            
            sort(all(best));
            reverse(all(best));

            if (best.size() == 3)
                best.pop_back();
        }
    }

    ll s = 0;
    if (best.size() == 1)
        s = best[0];
    if (best.size() == 2)
        s = best[0] + best[1];
    amax(mxIn[v], s + a[v]);
}

void dfs2(int v, int p = -1, ll mxInP = 0, ll fromP = 0) {
    multiset<ll> nb, nb2;
    for (int to:g[v])
        if (to != p) {
            nb.insert(mxDown[to]);
            nb2.insert(mxIn[to]);
        }
    for (int to:g[v]) {
        if (to != p) {
            nb.erase(nb.find(mxDown[to]));
            nb2.erase(nb2.find(mxIn[to]));
            
            ll newFromP = fromP + a[v];
            if (nb.size()) {
                amax(newFromP, *(--nb.end()) + a[v]);
            }

            ll newInP = mxInP;
            newInP = max(newInP, fromP + a[v]);
            if (nb.size()) {
                amax(newInP, *(--nb.end()) + a[v] + fromP);
            }

            if (nb.size() > 1) {
                amax(newInP, (*(--nb.end())) + (*(--(--nb.end()))) + a[v]);
            }

            if (nb2.size()) {
                amax(newInP, *(--nb2.end()));
            }

            amax(ans, newInP + mxIn[to]);
            dfs2(to, v, newInP, newFromP);

            nb.insert(mxDown[to]);
            nb2.insert(mxIn[to]);
        }
    }
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++)
        read(a[i]);

    for (int i = 0; i + 1 < n; i++) {
        int f, t;
        read(f, t);
        f--, t--;
        g[f] . pb(t);
        g[t] . pb(f);
    }
    dfs1(0);
    // cout << mxIn[7] << endl;
    dfs2(0);
    cout << ans;
    return 0;
}