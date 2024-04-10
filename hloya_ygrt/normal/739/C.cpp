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
const int maxn = 3e5 + 10, base = 1e9 + 7;
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

struct node {
    int l_seg, r_seg, mx;
    // node() {
    //     l_seg = 0, r_seg = 0, mx = 0;
    // }
};

node tree[8 * maxn];
ll a[maxn];

void merge(int v, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    if (a[tm] == 0 || a[tm + 1] == 0 || (a[tm] < 0 && a[tm + 1] > 0)) {
        // cout << "kek";
        tree[v].l_seg = tree[v<<1].l_seg;
        tree[v].r_seg = tree[v<<1|1].r_seg;
        tree[v].mx = max(tree[v<<1].mx, tree[v<<1|1].mx);
        return;
    }

    tree[v].mx = max(max(tree[v<<1].mx, tree[v<<1|1].mx), tree[v<<1].r_seg + tree[v<<1|1].l_seg);
    
    tree[v].l_seg = tree[v<<1].l_seg;
    if (tree[v<<1].mx == tm - tl + 1) {
        tree[v].l_seg += tree[v<<1|1].l_seg;
    }

    tree[v].r_seg = tree[v<<1|1].r_seg;
    if (tree[v<<1|1].mx == tr - tm) {
        tree[v].r_seg += tree[v<<1].r_seg;
    }
}

void build (int v, int tl, int tr) {
    if (tl == tr) {
        int cur = a[tl] != 0;
        tree[v].l_seg = tree[v].r_seg = tree[v].mx = cur;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm + 1, tr);
    merge(v, tl, tr);
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        a[tl] += val;
        int cur = a[tl] != 0;
        tree[v].l_seg = tree[v].r_seg = tree[v].mx = cur;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        upd(v<<1, tl, tm, pos, val);
    else
        upd(v<<1|1, tm + 1, tr, pos, val);
    merge(v, tl, tr);
}

void print(int v, int tl, int tr) {
    cout << v << ' ' << tl << ' ' << tr << endl;
    cout << tree[v].l_seg << ' ' << tree[v].r_seg << ' ' << tree[v].mx << endl;
    cout << endl;
    if (tl == tr)
        return;
    print(v<<1,tl,(tl+tr)>>1);
    print(v<<1|1,((tl+tr)>>1)+1, tr);
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
    }
    for (int i = 0; i + 1 < n; i++) {
        a[i] = a[i + 1] - a[i];
    }
    // n--;

    if (n != 1) {
        build(1, 0, n - 2);
    }
    int m;
    read(m);
    
    for (int i = 0; i < m; i++) {
        int l, r, d;
        read(l, r, d);

        if (dbg&&i <= 18) {
            cout << l << ' ' << r << ' ' << d << endl;
        }
        if (n == 1) {
            puts("1");
        } else {
            if (l!=1)
                upd(1, 0, n - 2, l - 2, d);
            if (r!=n)
                upd(1, 0, n - 2, r - 1, -d);
            cout << tree[1].mx + 1 << endl;
        }
        // if (i == m - 1)
        //     print(1, 0, n - 2);   
        //     for (int i = 0; i + 1 < n ;i++)
        //         cout << a[i] << ' ';
    }
    return 0;
}