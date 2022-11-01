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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

struct data
{
    int l, r;
    int pref, suff, len, sum, inside;
    data() {
        pref = suff = len = sum = inside = 0;
    }
    void set() {
        pref = suff = len = sum = inside = 1;
    }
};

data tree[20 * maxn];
int treeSz;
vector<int> roots;

int vert_copy(int v) {
    data my_new;
    my_new.l = tree[v].l, my_new.r = tree[v].r, my_new.pref = tree[v].pref, my_new.suff = tree[v].suff,
    my_new.sum = tree[v].sum, my_new.inside = tree[v].inside;
    tree[++treeSz] = my_new;
    return treeSz;
}

int make_root() {
    roots.pb(vert_copy(roots.back()));
    return roots.back(); 
}

void build(int v, int tl, int tr) {
    tree[v].len = tr - tl + 1;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(tree[v].l = vert_copy(0), tl, tm);
    build(tree[v].r = vert_copy(0), tm + 1, tr);
}

data combine(data a, data b) {
    data res;
    res.len = a.len + b.len;

    if (a.pref == a.len)
        res.pref = a.len + b.pref;
    else
        res.pref = a.pref;

    if (b.suff == b.len)
        res.suff = a.suff + b.len;
    else
        res.suff = b.suff;

    res.inside = max(max(a.inside, b.inside), a.suff + b.pref);
    return res;
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v].set();
        return;
    }

    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        tree[v].l = vert_copy(tree[v].l);
        update(tree[v].l, tl, tm, pos);
    } else {
        tree[v].r = vert_copy(tree[v].r);
        update(tree[v].r, tm + 1, tr, pos);
    }
    int svL = tree[v].l, svR = tree[v].r;
    tree[v] = combine(tree[tree[v].l], tree[tree[v].r]);
    tree[v].l = svL, tree[v].r = svR;
}

data query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return tree[0];
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return combine(
            query(tree[v].l, tl, tm, l, min(r, tm)),
            query(tree[v].r, tm + 1, tr, max(l, tm + 1), r)
        );
}

int h[maxn];

int main() {
    int n;
    //files1;
    read(n);

    vector<pair<int, int> > order;
    for (int i = 0; i < n; i++) {
        read(h[i]);
        order.pb(mp(h[i], i));
    }
    sort(all(order)), reverse(all(order));

    roots.pb(vert_copy(0));
    build(roots.back(), 0, n - 1);

    for (int i = 0; i < n; i++) {
        int start_v = make_root();
        // if (i == 0)
        //     dbg = 1;
        update(start_v, 0, n - 1, order[i].s);
        // return 0;
    }
    int m;
    read(m);

    while (m--) {
        int L, R, w;
        read(L, R, w);
        L--, R--;

        int l = 1, r = n;
        while (r - l > 1) {
            int c = (l + r) >> 1;
            if (query(roots[c], 0, n - 1, L, R).inside >= w)
                r = c;
            else
                l = c;
        }

        int ans;
        if (query(roots[l], 0, n - 1, L, R).inside >= w)
            ans = l;
        else
            ans = r;
        printf("%d\n", order[ans - 1].f);
    }
    return 0;
}