#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

// #define f first
// #define s second
#define f first.first
#define s first.second
#define t second

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

// void reads(string & s) {
//     string ans = "";
//     char c = endl;
//     while (c == endl || c == ' ')
//         c = getchar();
//     while (c != endl && c != ' ' && c)
//         ans += c, c = getchar();
//     s = ans;
// }

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

template<typename T>
T binpow(T n, T st)
{
    if (st <= 0)
        return 1LL;
    if (st % 2 == 0){
        T b = binpow(n, st / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, st - 1) * n) % base;
    }
}

struct node {
    node * l, * r;
    ll sum;
    int cnt;
    node() {
        l = 0, r = 0, sum = 0;
        cnt = 0;
    }
};

// node * root = new node();

// ll getSum(node * v) {
//     if (!v)
//         return 0;
//     return v->sum;
// }
// int getCnt(node * v) {
//     if (!v)
//         return 0;
//     return v->cnt;
// }

// void add(node * v, ll tl, ll tr, ll pos) {
//     // cerr << tl << ' ' << tr << endl;
//     // cerr << pos << endl;
//     if (tl == tr) {
//         v -> cnt++;
//         v -> sum += pos;
//         v -> sum = min(v -> sum, llinf);
//         return;
//     }
//     ll tm = (tl + tr) >> 1LL;
//     if (pos <= tm) {
//         if (v -> l == 0)
//             v -> l = new node();
//         add(v -> l, tl, tm, pos);
//     } else {
//         if (v -> r == 0)
//             v -> r = new node();
//         add(v -> r, tm + 1, tr, pos);     
//     }

//     v -> sum = min(getSum(v->l)+ getSum(v->r), llinf);
//     v -> cnt = getCnt(v->l) + getCnt(v->r);
// }

// pair<ll, int> cmb(pair<ll, int> a, pair<ll, int> b) {
//     pair<ll, int> c;
//     c.f = min(llinf, a.f + b.f);
//     c.s = a.s + b.s;
//     return c;
// }

// pair<ll, int> query(node * v, ll tl, ll tr, ll l, ll r) {
//     if (l > r || v == 0)
//         return mp(0, 0);
//     if (tl == l && tr == r) {
//         return mp(v -> sum, v -> cnt);
//     }
//     ll tm = (tl + tr) >> 1;
//     return cmb(
//             query(v->l, tl, tm, l, min(r, tm)),
//             query(v->r, tm + 1, tr, max(l, tm + 1), r)
//         );
// }


ll tree1[maxn];
int tree2[maxn];

void add(int pos, ll val) {
    pos++;

    while (pos < maxn) {
        tree2[pos]++;
        tree1[pos] += val;
        tree1[pos] = min(tree1[pos], llinf);

        pos += pos & (-pos);
    }
}

pair<ll, int> query(int r) {
    r++;

    pair<ll, int> ans = mp(0, 0);
    while (r > 0) {
        ans.first += tree1[r];
        ans.first = min(ans.first, llinf);
        ans.second += tree2[r];

        r -= r & (-r);
    }

    return ans;
}
int cnt = 0;

int find(ll got) {
    int l = 0, r = cnt - 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (query(m).first <= got)
            l = m;
        else
            r = m;
    }
    auto e = query(r);
    if (e.first <= got)
        return e.second;
    e = query(l);
    if (e.first <= got)
        return e.second;
    return 0;
}

int main() {
    int n;
//    files1;
    read(n);

    ll my_t, my_w;
    read(my_t, my_w);
    n--;

    vector<pair<ll, int> > tmp;
    // return 0;

    vector<pair<pair<ll, ll>, int> > g;
    for (int i = 0; i < n; i++) {
        ll t, w;
        read(t, w);
        g.pb(mp(mp(t, w), i));
        tmp.pb(mp(w - t + 1, i));
    }
    sort(all(tmp));

    map<pair<ll, int>, int> sot;

    for (int i = 0; i < tmp.size(); i++) {
        sot[tmp[i]] = cnt++;
    }

    sort(all(g));
    reverse(all(g));

    vector<ll> value;
    for (int i = 0; i < n; i++) {
        value.pb(g[i].f);
        if (g[i].f > 0)
            value.pb(g[i].f - 1);
    }
    value.pb(my_t);
    value.pb(0);

    sort(all(value));
    reverse(all(value));

    int j = 0;
    int ans = inf;

    for (int i = 0; i < value.size(); i++) {

        while (j < g.size() && g[j].f > value[i]) {
            add(sot[mp(g[j].s - g[j].f + 1, g[j].t)], g[j].s - g[j].f + 1);
            j++;
        }
        if (value[i] > my_t)
            continue;
        ll free___ = my_t - value[i];
        int cnt = find(free___);
        int place = j - cnt + 1;
        ans = min(ans, place);
    }
    cout << ans;
    return 0;
}