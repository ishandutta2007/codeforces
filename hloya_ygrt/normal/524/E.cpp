// hloya template v20

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
const long double eps = 1e-12;
const int maxn = 2e5 + 10, base = 1e9 + 7;
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

#define y1 fasf

pair<int, int> a[maxn];
int x1[maxn], x2[maxn], y1[maxn], y2[maxn];

vector<pair<int, int> > q[maxn];
bool ok[maxn];

int tree[4 * maxn];
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        upd(v<<1, tl, tm, pos, val);
    else
       upd(v<<1|1, tm + 1, tr, pos, val);
    tree[v] = min(tree[v<<1], tree[v<<1|1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return inf;
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return min(get(v<<1, tl, tm, l, min(r, tm)),
               get(v<<1|1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    int n, m, k, q;
    //files1;
    read(n, m, k, q);
    for (int i = 0; i < k; i++) {
        read(a[i].f, a[i].s);
    }

    for (int i = 0; i < q; i++) {
        read(x1[i], y1[i], x2[i], y2[i]);
    }

    // hor
    for (int i = 0; i < k; i++) {
        ::q[a[i].f].pb(mp(i, 0));
    }
    for (int i = 0; i < q; i++) {
        ::q[x2[i]].pb(mp(i, 1));
    }

    memset(tree, -1, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        for (auto e:(::q[i])) {
            if (e.s == 0) {
                int y = a[e.f].s;
                upd(1, 1, m, y, i);
            } else {
                int it = e.f;
                int yl = y1[it], yr = y2[it];
                int mn = get(1, 1, m, yl, yr);

                if (mn >= x1[it]) {
                    ok[it] = 1;
                }
            }
        }
        (::q[i]).clear();
    }
    
    for (int i = 0; i < k; i++)
        swap(a[i].f, a[i].s);
    for (int i = 0; i < q; i++)
        swap(x1[i], y1[i]), swap(x2[i], y2[i]);
    swap(n, m);

    // ver
    for (int i = 0; i < k; i++) {
        ::q[a[i].f].pb(mp(i, 0));
    }
    for (int i = 0; i < q; i++) {
        // if (ok[i])
        ::q[x2[i]].pb(mp(i, 1));
    }

    memset(tree, -1, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        for (auto e:(::q[i])) {
            if (e.s == 0) {
                int y = a[e.f].s;
                upd(1, 1, m, y, i);
            } else {
                int it = e.f;
                int yl = y1[it], yr = y2[it];
                int mn = get(1, 1, m, yl, yr);

                if (mn >= x1[it]) {
                    ok[it] = 1;
                }
            }
        }
        (::q[i]).clear();
    }
    
    for (int i = 0; i < q; i++) {
        puts(ok[i] ? "YES" : "NO");
    }
    return 0;
}