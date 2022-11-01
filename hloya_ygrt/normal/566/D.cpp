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
const int maxn = 2e5 + 12, base = (int)1e9 + 13;
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

vector<int> setik[maxn];
int dsu[maxn];

const int p = (int)2e5 + 107;

// struct H {
//     vector<int> h, base;
//     int n;
//     H() {}

//     H(vector<int> b) {
//         base = b;
//         n = base.size();
//         h.resize(n);
//         for (int i = 0; i < n; i++)
//             h[i] = 0;
//     }
//     void mult(int x) {
//         for (int i = 0; i < n; i++) {
//             h[i] = 1ll * h[i] * x % base[i];
//             if (h[i] < 0)
//                 h[i] += base[i];
//         }
//     }
//     void mulp() {
//         for (int i = 0; i < n; i++) {
//             h[i] = 1ll * h[i] * p % base[i];
//         }
//     }
//     void add(int x) {
//         for (int i = 0; i < n; i++) {
//             h[i] = h[i] + x;
//             if (h[i] >= base[i])
//                 h[i] -= base[i];
//             if (h[i] < 0)
//                 h[i] += base[i];
//         }
//     }
// };

// void mul(H& a, H b) {
//     int n = a.n;
//     for (int i = 0; i < n; i++) {
//         a.h[i] = 1ll * a.h[i] * b.h[i] % a.base[i];
//         if (a.h[i] < 0)
//             a.h[i] += a.base[i];
//     }
// }

// void add(H& a, H b) {
//     int n = a.n;
//     for (int i = 0; i < n; i++) {
//         a.h[i] += b.h[i];
//         if (a.h[i] >= a.base[i])
//             a.h[i] -= a.base[i];
//         if (a.h[i] < 0)
//             a.h[i] += a.base[i];
//     }
// }

// H tmp({(int)1e9 + 13});
int tmp = 0;
int d[maxn], dsum[maxn];

int tree[maxn];

int n;

void add(int& h, int h2) {
    h += h2;
    if (h < 0)
        h += base;
    if (h >= base)
        h -= base;
}

void mult(int& h, int h2) {
    h = 1ll * h * h2 % base;
    if (h < 0)
        h += base;
    if (h >= base)
        h -= base;
}


void fnw_add(int pos, int val) {
    pos++;
    while (pos <= n) {
        add(tree[pos], val);
        pos += pos & -pos;
    }
}

inline int get_sum(int r) {
    r++;
    int ans = tmp;
    while (r > 0) {
        add(ans, tree[r]);
        r -= r & -r;
    }
    return ans;
}

int cur, cur2, need;
void setLet(int pos, int val) {
    cur = d[pos];
    mult(cur, val);
    fnw_add(pos, cur);
    dsu[pos] = val;
}

void delLet(int pos) {
    int x = dsu[pos];
    cur = d[pos];
    mult(cur, -x);
    fnw_add(pos, cur);
}

bool eq(int l, int r) {
    cur = get_sum(r);

    if (l) {
        cur2 = get_sum(l - 1);
        mult(cur2, -1);
        add(cur, cur2);
    }
    need = dsum[r];
    if (l) {
        cur2 = dsum[l - 1];
        mult(cur2, -1);
        add(need, cur2);
    }
    mult(need, dsu[l]);
    if (need == cur) 
        return 1;
    return 0;
}

void merge(int a, int b) {
    if (a == b)
        return;
    if (setik[a].size() > setik[b].size())
        swap(a, b);
    for (int i = 0; i < setik[a].size(); i++) {
        int pos = setik[a][i];
        delLet(pos);
        setLet(pos, b);
        setik[b].pb(pos);
    }
    setik[a].clear();
}

int main() {
    d[0] = tmp;
    add(d[0], 1);

    for (int i = 1; i < maxn; i++) {
        d[i] = d[i - 1];
        mult(d[i], p);
    }

    dsum[0] = d[0];
    for (int i = 1; i < maxn; i++) {
        dsum[i] = dsum[i - 1];
        add(dsum[i], d[i]);
    }

    // for (int i = 0; i < maxn; i++)
    //     tree[i] = tmp;

    int q;
    read(n, q);


    for (int i = 0; i < n; i++) {
        setik[i].pb(i);
        setLet(i, i);
    }
    // merge(0, 1);

    for (int i = 0; i < q; i++) {
        int t;
        read(t);

        if (t == 1) {
            int x, y;
            read(x, y);
            x--, y--;

            merge(dsu[x], dsu[y]);
        }
        if (t == 2) {
            int x, y;
            read(x, y);
            x--, y--;

            int prev = x;
            while (1) {
                int l = prev + 1, r = y;
                if (l > r)
                    break;
                while (r - l > 0) {
                    int m = (l + r) >> 1;
                    if (eq(x, m))
                        l = m + 1;
                    else
                        r = m;
                }
                if (dsu[l] != dsu[x]) {
                    merge(dsu[l], dsu[x]);
                    prev = l;
                } else break;
            }
        }
        if (t == 3) {
            int x, y;
            read(x, y);
            x--, y--;
            if (dsu[x] == dsu[y]) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}