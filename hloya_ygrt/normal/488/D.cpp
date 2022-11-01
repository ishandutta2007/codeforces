// hloya template v23

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

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
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

int a[maxn];

int tree[4 * maxn];
void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) tree[v] = val;
    else {
        int m = (tl+tr)>>1; 
        if (pos <= m) update(v<<1, tl, m, pos, val); else update(v<<1|1, m + 1, tr, pos, val);
        tree[v] = min(tree[v<<1], tree[v<<1|1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return inf;
    if (tl == l && tr == r) return tree[v];
    int m = (tl+tr)>>1;
    return min(get(v<<1, tl, m, l, min(r, m)), get(v<<1|1, m + 1, tr, max(l, m + 1), r));
}

multiset<int> st;
int cur() {
    if (st.empty()) return -1;
    return *st.rbegin() - *st.begin();
}

int main() {
    int n, s, l;
    read(n, s, l);

    for (int i = 0; i < n; i++) {
        read(a[i]);
    }

    if (l > n) bad(-1);
    for (int i = 0; i + 1 < l; i++) {
        st.insert(a[i]);
        update(1, 0, n - 1, i, inf);
    }

    if (cur() > s) bad(-1);

    int L = 0;
    for (int i = l - 1; i < n; i++) {
        st.insert(a[i]);
        while (cur() > s) {
            st.erase(st.find(a[L]));
            L++;
        }
        if (i - l < L - 1) {
            update(1, 0, n - 1, i, inf);
            continue;
        }
        if (L == 0) {
            // cout << "kek";
            update(1, 0, n - 1, i, 1);
            continue;
        }
        // cout << L - 1 << ' ' << i - l << endl;
        int cur = get(1, 0, n - 1, L - 1, i - l) + 1;
        // cout << i << ' ' << cur
        update(1, 0, n - 1, i, cur);
    }
    int ans = get(1, 0, n - 1, n - 1, n - 1);
    if (ans == inf) ans = -1;
    cout << ans;
    return 0;
}