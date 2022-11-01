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
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
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
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = 1e9 + 7;
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

map<pii, int> edgenum;
pii e[maxn];
int last[maxn];

vector<int> dc[4 * maxn];
void add(int v, int tl, int tr, int l, int r, int num) {
    if (l > r) return;
    if (tl == l && tr == r) {
        dc[v].pb(num);
        return;
    }
    int tm = (tl + tr) >> 1;
    add(v<<1, tl, tm, l, min(r, tm), num);
    add(v<<1|1, tm + 1, tr, max(l, tm + 1), r, num);
}

int timer = 0;
struct otkat_dsu {
    vector<int> p, sz, fr;
    int n;
    vector<pair<int, pii> > ch_p, ch_sz, ch_fr;
    otkat_dsu(int _n = maxn) {
        n = _n;
        p.resize(n + 1);
        sz.resize(n + 1);
        fr.resize(n + 1);
        for (int i = 0; i < n; i++)
            p[i] = i, sz[i] = 1, fr[i] = n;
        sz[n] = 0;
        p[n] = n;
    }
    int get(int v) {
        if (p[v] == v) return v;
        return get(p[v]);
    }
    void merge(int u, int v) {
        if (u == n || v == n)
            return;
        if (sz[u] > sz[v]) swap(u, v);
        ch_sz.pb(mp(timer, mp(v, sz[v])));
        ch_p.pb(mp(timer, mp(u, p[u])));
        p[u] = v;
        sz[v] += sz[u];
    }
    void merge_with_inv(int u, int v, int u1, int v1) {
        if (u1 == n) {
            fr[u] = v;
            ch_fr.pb(mp(timer, mp(u, n)));
        }
        if (v1 == n) {
            fr[v] = u;
            ch_fr.pb(mp(timer, mp(v, n)));
        }
        merge(u, v1);
        merge(v, u1);
    }
    void otkat(int tm) {
        while (!ch_p.empty() && ch_p.back().f >= tm) {
            int i = ch_p.back().s.f, old = ch_p.back().s.s;
            p[i] = old;
            ch_p.pop_back();
        }
        while (!ch_sz.empty() && ch_sz.back().f >= tm) {
            int i = ch_sz.back().s.f, old = ch_sz.back().s.s;
            sz[i] = old;
            ch_sz.pop_back();
        }
        while (!ch_fr.empty() && ch_fr.back().f >= tm) {
            int i = ch_fr.back().s.f, old = ch_fr.back().s.s;
            fr[i] = old;
            ch_fr.pop_back();
        }
    }
    void print() {
        for (int i = 0; i < 5; i++)
            cout << p[i] << ' ' << sz[i] << ' ' << fr[i] << endl;
    }
} dsu;

int ans[maxn];
void solve(int v, int tl, int tr, int bad = 0) {
    int curtime = ++timer;
    if (!bad) {
        // add edges
        for (int num : dc[v]) {
            int u = e[num].f, v = e[num].s;
            int cmp1 = dsu.get(u), cmp2 = dsu.get(v);
            if (cmp1 == cmp2) {
                bad = 1;
                break;
            }
            int cmp3 = dsu.get(dsu.fr[cmp1]), cmp4 = dsu.get(dsu.fr[cmp2]);
            if (cmp1 == cmp3 || cmp2 == cmp4) {
                assert(cmp1 == cmp3 && cmp2 == cmp4);
                continue;
            }
            dsu.merge_with_inv(cmp1, cmp2, cmp3, cmp4);
        }
    }


    if (tl == tr) {
        ans[tl] = bad;
        return;
    }
    int tm = (tl + tr) >> 1;
    solve(v<<1, tl, tm, bad);
    solve(v<<1|1, tm + 1, tr, bad);
    dsu.otkat(curtime);
}

int main() {
    int n, q;
    // files1;
    read(n, q);

    memset(last, -1, sizeof(last));

    for (int i = 0; i < q; i++) {
        int u, v;
        read(u, v);
        u--, v--;

        e[i] = mp(u, v);
        if (!edgenum.count(e[i])) {
            edgenum[e[i]] = i;
        }

        int num = edgenum[e[i]];
        if (last[num] == -1) {
            last[num] = i;
        } else {
            add(1, 0, q - 1, last[num], i - 1, num);
            last[num] = -1;
        }
    }
    for (int i = 0; i < q; i++)
        if (last[i] != -1)
            add(1, 0, q - 1, last[i], q - 1, i);

    solve(1, 0, q - 1);
    for (int i = 0; i < q; i++)
        puts(ans[i] == 0 ? "YES" : "NO");
    return 0;
}