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

deque<int> q[maxn];

struct node {
    int l, r, sum;
    node() {
        l = 0, r = 0, sum = 0;
    }
};

vector<int> roots;
vector<node> tree;

int make_node(int v) {
    tree.pb(tree[v]);
    int ans = tree.size() - 1;
    if (ans == 0) {
        cout << v;
        exit(v);
    }
    return ans;
}

int make_root() {
    int v = make_node(roots.back());
    roots.pb(v);
    return v;
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v].sum = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        int x = tree[v].l;
        int v2 = make_node(x);
        tree[v].l = v2;
        assert(tree[v].l != 0);
        upd(tree[v].l, tl, tm, pos, val);
    } else {
        int x = tree[v].r;
        int v2 = make_node(x);
        tree[v].r = v2;
        assert(tree[v].r != 0);
        upd(tree[v].r, tm + 1, tr, pos, val);
    }
    tree[v].sum = tree[tree[v].l].sum + tree[tree[v].r].sum;
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r || v == 0)
        return 0;
    if (tl == l && tr == r)
        return tree[v].sum;
    int tm = (tl + tr) >> 1;
    return get(tree[v].l, tl, tm, l, min(r, tm)) +
           get(tree[v].r, tm + 1, tr, max(l, tm + 1), r);
}

void print(int v, int tl, int tr) {
    cout << v << ' ' << tl << ' ' << tr << ' ' << tree[v].sum << endl;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    print(tree[v].l, tl, tm);
    print(tree[v].r, tm + 1, tr);
}

int main() {
    // files1;
    tree.pb(node());
    tree.pb(node());
    roots.pb(1);

    int n, k;
    read(n, k);

    for (int i = 0; i < n; i++) {
        int x;
        read(x);

        int root = make_root();
        if (q[x].size() == k) {
            int p = q[x].front();
            q[x].pop_front();
            upd(root, 0, n - 1, p, 0);
        }
        upd(root, 0, n - 1, i, 1);
        q[x].pb(i);
    }

    int q;
    read(q);

    int last = 0;
    while (q--) {
        int x, y;
        read(x, y);
        int l = (x + last) % n;
        int r = (y + last) % n;
        if (l > r) swap(l, r);
        // cout << l << ' ' << r << endl;

        int ans = get(roots[r + 1], 0, n - 1, l, r);
        last = ans;
        printf("%d\n", ans);
    }
    return 0;
}