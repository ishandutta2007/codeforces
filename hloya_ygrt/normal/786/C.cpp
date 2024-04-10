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
#define files2 freopen("data.out","w",stdout)
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
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = (int)1e9 + 13;
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
int last[maxn];

struct node {
    int l, r;
    int sum;
    node() {
        sum = 0;
        l = 0, r = 0;
    }
} tree[maxn * 64];
vector<int> roots(1, 1);
int sz = 1;

int make_node(int v) {
    tree[++sz] = tree[v];
    return sz;
}

int make_root() {
    int v = make_node(roots.back());
    roots.pb(v);
    return v;
}

void add(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v].sum += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        tree[v].l = make_node(tree[v].l);
        add(tree[v].l, tl, tm, pos, val);
    } else {
        tree[v].r = make_node(tree[v].r);
        add(tree[v].r, tm + 1, tr, pos, val);
    }
    tree[v].sum = tree[tree[v].l].sum + tree[tree[v].r].sum;
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r || !v) return 0;
    if (tl == l && tr == r) return tree[v].sum;
    int tm = (tl + tr) >> 1;
    return sum(tree[v].l, tl, tm, l, min(r, tm)) + sum(tree[v].r, tm + 1, tr, max(l, tm + 1), r);
}

int n;
inline int cnt(int l, int r) {
    int ans = sum(roots[r + 1], 0, n - 1, l, r);
    return ans;
}

int used[maxn];
int cnt_dif = 0;

inline void add(int x) {
    if (used[x] == 0) {
        cnt_dif++;
    }
    used[x] ++;
}

inline void del(int x) {
    used[x] --;
    if (used[x] == 0) {
        cnt_dif--;
    }
}

int main() {
    read(n);

    for (int i = 0; i < n; i++)
        read(a[i]);
    memset(last, -1, sizeof(last));

    roots.reserve(maxn);
    for (int i = 0; i < n; i++) {
        int cur_root = make_root();
        if (last[a[i]] != -1) {
            add(cur_root, 0, n - 1, last[a[i]], -1);
        }
        last[a[i]] = i;
        add(cur_root, 0, n - 1, last[a[i]], 1);
    }

    const int MAGIC = 1501;

    for (int k = 1; k <= n; k++) {
        if (k < MAGIC) {
            int ans = 0;
            for (int l = 0; l < n; ) {
                int r = l;
                while (r < n) {
                    add(a[r]);
                    if (cnt_dif > k) {
                        del(a[r]);
                        break;
                    }
                    r++;
                }

                for (int i = l; i < r; i++)
                    del(a[i]);

                ans++;
                l = r;
            }
            printf("%d ", ans);
            continue;
        }
        int sum = 0;
        for (int i = 0; i < n;) {
            int l = i, r = n - 1;
            if (cnt(i, r) <= k) {
                sum++;
                break;
            }
            while (r - l > 0) {
                int m = (l + r + 1) >> 1;
                if (cnt(i, m) > k)
                    r = m - 1;
                else
                    l = m;
            }
            sum++;
            i = l + 1;
        }
        printf("%d ", sum);
    }
    return 0;
}