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
  
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <assert.h>
#include <map>
#include <cstring>
#include <queue>
#include <iomanip>
#include <time.h>
// #Include
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-15;
const int maxn = (int)4e5 + 12, base = 1e9 + 7;
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
    int l, r;
    int max;

    node() {
        l = 0, r = 0;
        max = 0;
    }
};

vector<node> tree;
vector<int> roots;

int make_node(int v) {
    node t = tree[v];
    tree.push_back(t);
    return tree.size() - 1;
}

int make_root() {
    int t = make_node(roots.back());
    roots.pb(t);
    return t;
}

int left_v[maxn], right_v[maxn];

int get(int v) {
    if (v == 0) return 0;
    return tree[v].max;
}

void upd(int v) {
    tree[v].max = max(get(tree[v].l), get(tree[v].r));
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v].max = max(tree[v].max, val);
        return;
    }

    int tm = (tl + tr) >> 1;

    if (pos <= tm) {
        int x = make_node(tree[v].l);
        tree[v].l = x;
        upd(tree[v].l, tl, tm, pos, val);
    } else {
        int x = make_node(tree[v].r);
        tree[v].r = x;
        upd(tree[v].r, tm + 1, tr, pos, val);
    }

    upd(v);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r || v == 0) return 0;
    if (tl == l && tr == r) {
        return tree[v].max;
    }
    int tm = (tl + tr) >> 1;
    return max(get(tree[v].l, tl, tm, l, min(r, tm)), 
               get(tree[v].r, tm + 1, tr, max(l, tm + 1), r));
}

int d[maxn];
int lv[maxn], rv[maxn];

int main() {
    tree.push_back(node());
    roots.push_back(0);

    int n, m;
    fast_io;
    // files1;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        d[l]++;
        d[r + 1]--;
    }

    for (int i = 0; i < m; i++) {
        if (i) d[i] += d[i - 1];
        assert(d[i] >= 0);
    }



    for (int i = 0; i < m; i++) {
        int val = get(roots.back(), 0, n, 0, d[i]) + 1;
        left_v[i] = make_root();
        upd(left_v[i], 0, n, d[i], val);
        lv[i] = val;
        // cout << lv[i] << endl;
    }

    tree.clear();
    roots.clear();

    tree.push_back(node());
    roots.push_back(tree.size() - 1);

    for (int i = m - 1; i >= 0; i--) {
        int val = get(roots.back(), 0, n, 0, d[i]) + 1;
        right_v[i] = make_root();
        upd(right_v[i], 0, n, d[i], val);
        rv[i] = val;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        amax(ans, lv[i] + rv[i] - 1);
    }
    cout << ans;
    return 0;
}