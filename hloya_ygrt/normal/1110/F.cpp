// hloya template v25
  
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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
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

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e6 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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

struct node {
    ll mn;
    ll add;
    node() {
        mn = llinf;
        add = 0;
    }
} tree[4 * maxn];

void push(int v) {
    if (tree[v].add) {
        ll a = tree[v].add;
        tree[v << 1].mn += a;
        tree[v<<1|1].mn += a;
        tree[v << 1].add += a;
        tree[v<<1|1].add += a;
        tree[v].add = 0;
    }
}

void add(int v, int tl, int tr, int l, int r, ll x) {
    if (l > r)
        return;
    if (tl == l && tr == r) {
        tree[v].mn += x;
        tree[v].add += x;
        return;
    }

    push(v);

    int tm = (tl + tr) >> 1;
    add(v<<1, tl, tm, l, min(r, tm), x);
    add(v<<1|1, tm + 1, tr, max(l, tm + 1), r, x);
    tree[v].mn = min(tree[v<<1].mn, tree[v<<1|1].mn);
}

ll getmin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return llinf;
    if (tl == l && tr == r) {
        return tree[v].mn;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    return min( 
        getmin(v<<1, tl, tm, l, min(r, tm)),
        getmin(v<<1|1, tm + 1, tr, max(l, tm + 1), r)
    );
}

int cnt[maxn];
vector<pair<int, ll> > lf;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].mn = lf[tl].second;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm + 1, tr);
    tree[v].mn = min(tree[v<<1].mn, tree[v<<1|1].mn);
}


int l[maxn];
int r[maxn];

vector<pair<int, pair<int, int> > > que[maxn];

ll ans[maxn];
vector<pair<int, int> > g[maxn];

void dfs(int v, ll dist = 0) {
    l[v] = lf.size();

    if (g[v].empty()) {

        lf.pb(mp(v, dist));

        r[v] = lf.size() - 1;

        return;
    }

    for (auto i : g[v]) {
        int to = i.f, len = i.s;
        dfs(to, dist + len);
    }

    r[v] = lf.size() - 1;
}


void dfs2(int v) {
    for (auto e : que[v]) {
        int it = e.f, le = e.s.f, ri = e.s.s;
        ans[it] = getmin(1, 0, lf.size() - 1, le, ri);
    }

    for (auto e : g[v]) {
        int to = e.f, len = e.s;

        add(1, 0, lf.size() - 1, l[to], r[to], -len);
        if (l[to] != 0)
            add(1, 0, lf.size() - 1, 0, l[to] - 1, +len);
        if (r[to] != lf.size() - 1)
            add(1, 0, lf.size() - 1, r[to] + 1, lf.size() - 1, +len);
        
        dfs2(to);

        add(1, 0, lf.size() - 1, l[to], r[to], +len);
        if (l[to] != 0)
            add(1, 0, lf.size() - 1, 0, l[to] - 1, -len);
        if (r[to] != lf.size() - 1)
            add(1, 0, lf.size() - 1, r[to] + 1, lf.size() - 1, -len);
    }
}

int main() {
    // files1;
    fast_io;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        p--;

        // cout << i << ' ' << p << ' ' << w << endl;

        g[p].pb(mp(i, w));
    }

    dfs(0);
    sort(all(lf));

    for (int i = 0; i < q; i++) {
        int v, l, r;
        cin >> v >> l >> r;
        v--, l--, r--;
        int it1 = lower_bound(all(lf), mp(l, -100ll)) - lf.begin();
        int it2 = upper_bound(all(lf), mp(r, llinf)) - lf.begin() - 1;

        que[v].pb(mp(i, mp(it1, it2)));
    }

    build(1, 0, lf.size() - 1);

    // for (auto e : lf) {
    //     cout << e.f << ' ' << e.s << endl;
    // }

    dfs2(0);

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}