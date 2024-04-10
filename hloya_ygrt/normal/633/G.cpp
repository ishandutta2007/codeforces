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

int a[maxn];

vector<int> g[maxn];
int b[maxn], sz;
int l[maxn], r[maxn];

void dfs(int v, int p = -1) {
    b[sz++] = v;
    l[v] = sz - 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v);
        }
    }
    r[v] = sz - 1;
}

int delta[8 * maxn];
int m;

bitset<1000> tree[8 * maxn];

template<size_t N>
inline void rotate(bitset<N> & b, int k) {
    b = b << k | b >> (m - k);
}

void add(int & x, int y) {
    x += y;
    if (x >= m)
        x -= m;
}

void push(int v) {
    if (delta[v]) {
        add(delta[v << 1], delta[v]);
        add(delta[v << 1|1], delta[v]);
        assert(delta[v] < m);
        rotate(tree[v], delta[v]);
        delta[v] = 0;
    }
}

bitset<1000> get(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return bitset<1000>(0);
    push(v);
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm)) | 
           get(v<<1|1, tm + 1, tr, max(l, tm + 1), r);
}

void mod(int v, int tl, int tr, int l, int r, int f) {
    if (l > r)
        return;
    push(v);
    if (tl == l && tr == r) {
        add(delta[v], f);
        return;
    }
    int tm = (tl + tr) >> 1;

    mod(v << 1, tl, tm, l, min(r, tm), f);
    mod(v<<1|1, tm + 1, tr, max(l, tm + 1), r, f);

    push(v<<1), push(v<<1|1);

    tree[v] = tree[v << 1] | tree[v << 1|1];
}


void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v][b[tl]] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    build (v << 1, tl, tm);
    build (v<<1|1, tm + 1, tr);
    tree[v] = tree[v << 1] | tree[v << 1|1];
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main() {
    int n;
    read(n, m);
    
    for (int i = 0; i < n; i++)
        read(a[i]);

    for (int i = 0; i + 1 < n; i++) {
        int f, t;
        read(f, t);
        f--, t--;

        g[f].pb(t);
        g[t].pb(f);
    }

    dfs(0);
    for (int i = 0; i < n; i++) {
        b[i] = a[b[i]] % m;
    }

    build(1, 0, n - 1);

    bitset<1000> primes(0);

    for (int i = 2; i < m; i++)
        if (is_prime(i))
            primes[i] = 1;

    int q;
    read(q);

    while (q--) {
        int type;
        read(type);

        if (type == 1) {
            int v, x;
            read(v, x);
            v--, x %= m;
            mod(1, 0, n - 1, l[v], r[v], x);
        }
        if (type == 2) {
            int v;
            read(v);
            v--;
            bitset<1000> cur = get(1, 0, n - 1, l[v], r[v]);
            cur &= primes;
            printf("%d\n", (int)cur.count());
        }
    }
    return 0;
}