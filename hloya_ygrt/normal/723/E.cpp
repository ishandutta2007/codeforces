#include <bits/stdc++.h>
#include <valarray>

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
 
using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
// #include <unordered_map>
// #include <unordered_set>
 
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
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 2e2 + 2, base = 1073676287;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return (1LL * b * b) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

bool g[maxn][maxn];
int d[maxn];
vector<pair<int, int> > res;

void solve() {
    res.clear();
    memset(g, 0, sizeof(g));
    memset(d, 0, sizeof(d));

    int n, m;
    read(n, m);
    for (int i = 0; i < m; i++) {
        int f, t;
        read(f, t);
        f--, t--;
        g[f][t] = g[t][f] = 1;
        d[f]++;
        d[t]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (d[i] % 2 == 0)
            ans++;
    for (int i = 0; i < n; i++)
        if (d[i] % 2)
        {
            for (;d[i]>0;) {
                int v = i;
                for (;;) {
                    int to = -1;
                    for (int j = 0; j < n; j++)
                        if (g[v][j]) {
                            to = j;
                            break;
                        }
                    if (to == -1)
                        break;
                    g[v][to] = 0;
                    g[to][v] = 0;
                    d[v]--;
                    d[to]--;
                    res.pb(mp(v, to));
                    v = to;
                }
            }
        }
  for (int i = 0; i < n; i++) {
        for (;d[i]>0;) {
                int v = i;
                for (;;) {
                    int to = -1;
                    for (int j = 0; j < n; j++)
                        if (g[v][j]) {
                            to = j;
                            break;
                        }
                    if (to == -1)
                        break;
                    g[v][to] = 0;
                    g[to][v] = 0;
                    d[v]--;
                    d[to]--;
                    res.pb(mp(v, to));
                    v = to;
                }
            }
    }

    cout << ans << endl;
    for (auto e:res)
        cout << e.f + 1 << ' ' << e.s + 1 << endl;
}

int main() {
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}