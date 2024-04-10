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
const int maxn = 3e3 + 10, base = 1e9 + 7;
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

vector<int> g[maxn];
int d[maxn][maxn], p[maxn][maxn];
set<pair<pii, int> > bd;

#define end fsajsf
#define begin saf

pii Q[maxn * maxn];
int begin, end;

inline void push(pii x) {
    Q[end++] = x;
}
inline pii pop() {
    return Q[begin++];
}
inline bool empty() {
    return begin == end;
}

int main() {
    //files1;
    int n, m, k;
    read(n, m, k);

    for (int i = 0; i < m; i++) {
        int f, t;
        read(f, t);

        g[f].pb(t);
        g[t].pb(f);
    }

    for (int i = 0; i < k; i++) {
        int f, t, s;
        read(f, t, s);

        bd.insert(mp(mp(f, t), s));
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            d[i][j] = inf;
        }
    d[0][1] = 0;
    push(mp(0, 1));
    pii tmp;

    while (!empty()) {
        tmp = pop();
        int a = tmp.f, b = tmp.s;

        for (int i = 0; i < g[b].size(); i++) {
            int to = g[b][i];
            if (!bd.count(mp(mp(a, b), to)) && d[b][to] > d[a][b] + 1) {
                d[b][to] = d[a][b] + 1;
                p[b][to] = a;
                push(mp(b, to));
            }
        }
    }

    int ans = inf;
    int b, c = n;

    for (int i = 0; i <= n; i++)
        if (d[i][n] < ans) {
            ans = d[i][n];
            b = i;
        }
    if (ans == inf)
        bad("-1");

    vector<int> res;
    res.pb(n);

    while (b != 0) {
        res.pb(b);
        int a = p[b][c];
        c = b;
        b = a;
    }

    printf("%d\n", ans);
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d ", res[i]);
    return 0;
}