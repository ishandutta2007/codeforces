// hloya template v22

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
void bad(int mes = -1){cout << mes;exit(0);}

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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = 1e9 + 7;
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
    int cnt[26];
    int delta; // to_clr -1

    node() {
        for (int i = 0; i < 26; i++)
            cnt[i] = 0;
        delta = -1;
    }
    int getcnt(int col, int len) {
        if (delta != -1) {
            return (col == delta) ? len : 0;
        }
        return cnt[col];
    }
} tree[4 * maxn];

void push(int v, int len) {
    int oldDelta = tree[v].delta;
    if (oldDelta == -1)
        return;

    memset(tree[v].cnt, 0, sizeof(tree[v].cnt));
    tree[v].cnt[oldDelta] = len;

    tree[v].delta = -1;
    if ((v << 1) >= 4 * maxn)
        return;
    tree[v<<1].delta = oldDelta;
    tree[v<<1|1].delta = oldDelta;
}

int rescnt[26];
void query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return;
    push(v, tr - tl + 1);
    if (tl == l && tr == r) {
        for (int i = 0; i < 26; i++)
            rescnt[i] += tree[v].cnt[i];
        return;
    }
    int tm = (tl + tr) >> 1;
    query(v << 1, tl, tm, l, min(r, tm));
    query(v<<1|1, tm + 1, tr, max(l, tm + 1), r);

    for (int i = 0; i < 26; i++)
        tree[v].cnt[i] = tree[v<<1].getcnt(i, tm - tl + 1) + tree[v<<1|1].getcnt(i, tr - tm);
}

void __set(int v, int tl, int tr, int l, int r, int col) {
    if (l > r)
        return;
    push(v, tr - tl + 1);
    if (tl == l && tr == r) {
        tree[v].delta = col;
        return;
    }

    int tm = (tl + tr) >> 1;
    __set(v << 1, tl, tm, l, min(r, tm), col);
    __set(v<<1|1, tm + 1, tr, max(l, tm + 1), r, col);

    for (int i = 0; i < 26; i++)
        tree[v].cnt[i] = tree[v<<1].getcnt(i, tm - tl + 1) + tree[v<<1|1].getcnt(i, tr - tm);
}

int main() {
    files;
    int n, m;
    read(n, m);
    // getchar();

    for (int i = 0; i < n; i++) {
        char c = getchar();
        // cout << c << endl;/
        __set(1, 0, n - 1, i, i, c - 'a');
    }

    // for (int i = 0; i < n; i++) {
    //     memset(rescnt, 0, sizeof(rescnt));
    //     query(1, 0, n - 1, i, i);
    //     int cur = 0;
    //     // for (int j = 0; j < 26; j++)
    //     //     cout << rescnt[j] << ' ';
    //     // cout << endl;
    //     cout << char(cur + 'a');
    // }
    // cout << endl;
    // return 0;

    for (int i = 0; i < m; i++) {
        int l, r;
        read(l, r);
        l--, r--;

        memset(rescnt, 0, sizeof(rescnt));
        query(1, 0, n - 1, l, r);
        
        int cntodd = 0, anyodd = -1;
        for (int j = 0; j < 26; j++)
            if (rescnt[j]&1) {
                cntodd++;
                anyodd = j;
            }
        if (cntodd > 1)
            continue;
        if (cntodd) {
            rescnt[anyodd]--;
            __set(1, 0, n - 1, (l + r) >> 1, (l + r) >> 1, anyodd);
        }
        for (int j = 0; j < 26; j++) {
            if (rescnt[j] != 0) {
                int al = rescnt[j]>>1;
                __set(1, 0, n - 1, l, l + (al) - 1, j);
                l += al;
                __set(1, 0, n - 1, r - al + 1, r, j);
                r -= al;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        memset(rescnt, 0, sizeof(rescnt));
        query(1, 0, n - 1, i, i);
        int cur = 0;
        for (int j = 0; j < 26; j++)
            if (rescnt[j])
                cur = j;
        cout << char(cur + 'a');
    }
    return 0;
}