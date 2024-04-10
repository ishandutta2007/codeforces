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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

int a[maxn], n;

struct interval {
    int pref, suff, sum, mx;
    int posPr, posSuff;
    int Lmx, Rmx;

    void set(int x, int pos) {
        sum = x;
        pref = x, suff = x, mx = x;
        Lmx = pos, Rmx = pos, posPr = pos, posSuff = pos;
    }
};

struct node {
    interval data[2];
    int push;
} tree[4 * maxn];

inline void push(int v) {
    if (tree[v].push) {
        swap(tree[v].data[0], tree[v].data[1]);
        if ((v<<1|1) < 4 * maxn) {
            tree[v<<1].push ^= 1, tree[v<<1|1].push ^= 1;
        }
        tree[v].push = 0;
    }
}

interval merge(interval a, interval b) {
    interval res;
    res.sum = a.sum + b.sum;

    int cnd1 = a.mx, cnd2 = b.mx, cnd3 = a.suff+b.pref;
    if (cnd1 >= cnd2 && cnd1 >= cnd3) {
        res.Lmx = a.Lmx, res.Rmx = a.Rmx;
        res.mx = cnd1;
    } else if (cnd2 >= cnd3 && cnd2 >= cnd1) {
        res.Lmx = b.Lmx, res.Rmx = b.Rmx;
        res.mx = cnd2;    
    } else {
        res.Lmx = a.posSuff, res.Rmx = b.posPr;
        res.mx = cnd3;
    }

    if (a.pref > a.sum + b.pref) {
        res.pref = a.pref;
        res.posPr = a.posPr;
    } else {
        res.pref = a.sum + b.pref;
        res.posPr = b.posPr;
    }

    if (b.suff > b.sum + a.suff) {
        res.suff = b.suff;
        res.posSuff = b.posSuff;
    } else {
        res.suff = b.sum + a.suff;
        res.posSuff = a.posSuff;
    }
    return res;
}

void upd(int pos, int val, int v = 1, int tl = 0, int tr = n - 1) {
    push(v);
    if (tl == tr) {
        tree[v].data[0].set(val, tl);
        tree[v].data[1].set(-val, tl);
        return;
    }
    int tm = (tl+tr)>>1;
    if (pos <= tm)
        upd(pos, val, v<<1, tl, tm);
    else
        upd(pos, val, v<<1|1, tm + 1, tr);
    push(v<<1);
    push(v<<1|1);
    tree[v].data[0] = merge(tree[v<<1].data[0], tree[v<<1|1].data[0]);
    tree[v].data[1] = merge(tree[v<<1].data[1], tree[v<<1|1].data[1]);
}

void modify(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return;
    push(v);
    if (tl == l && tr == r) {
        tree[v].push = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(l, min(r, tm), v<<1, tl, tm);
    modify(max(l, tm + 1), r, v<<1|1, tm + 1, tr);
    push(v<<1), push(v<<1|1);
    tree[v].data[0] = merge(tree[v<<1].data[0], tree[v<<1|1].data[0]);
    tree[v].data[1] = merge(tree[v<<1].data[1], tree[v<<1|1].data[1]);    
}

interval get(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    push(v);
    if (tl == l && tr == r)
        return tree[v].data[0];
    int tm = (tl + tr) >> 1;
    if (tm + 1 > r) {
        return get(l, r, v<<1, tl, tm);
    }
    if (l > tm) {
        return get(l, r, v<<1|1, tm + 1, tr);
    }
    return merge(
            get(l, tm, v<<1, tl, tm),
            get(tm + 1, r, v<<1|1, tm + 1, tr)
        );
}

vector<pair<int, node> > spolied;

void saveNodes(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    spolied.pb(mp(v, tree[v]));        if (tl != tr) {
            spolied.pb(mp(v<<1, tree[v<<1]));
            spolied.pb(mp(v<<1|1, tree[v<<1|1]));
        }
    if (l > r)
        return;
    if (tl == l && tr == r) {

        return;
    }
    int tm = (tl + tr) >> 1;
    saveNodes(l, min(r, tm), v << 1, tl, tm);
    saveNodes(max(l, tm + 1), r, v << 1|1, tm + 1, tr);
}

int main() {
    //files1;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
        upd(i, a[i]);
    }

    int m;
    read(m);
    
    for (int i = 0; i < m; i++) {
        int type;
        read(type);

        if (type == 0) {
            int pos, val;
            read(pos, val);
            upd(pos - 1, val);
        } else {
            int l, r, k;
            ll res = 0;
            read(l, r, k);
            l--, r--;

            spolied.clear();
            // if (i == 1)
            //     dbg = 1;
            saveNodes(l, r);
            // if (dbg)
            //     cout << l << ' ' << r << endl;

            for (int i = 0; i < k; i++) {
                interval ans = get(l, r);
                if (ans.mx >= 0) {
                    // if (dbg)
                    //     cout << ans.Lmx << ' ' << ans.Rmx << endl;
                    saveNodes(ans.Lmx, ans.Rmx);
                    modify(ans.Lmx, ans.Rmx);
                    res += ans.mx;
                } else break;
            }


            for (int j = spolied.size() - 1; j >= 0; j--) {
                tree[spolied[j].f] = spolied[j].s;
                // if (i == 1) {
                //     cout << spolied[j].f << endl;
                // }
            }
            // if (i == 1) {
            //     return 0;
            // }

            // for (int i = 1; i < 4 * maxn; i++)
            //     if (tree[i].push) {
            //         cout << i << endl;
            //         assert(0);
            //     }

            cout << res << endl;
        }
    }
    return 0;
}