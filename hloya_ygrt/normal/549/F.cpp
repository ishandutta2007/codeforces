// hloya template v24


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

 const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 1e6 + 12, base = (int)1e9 + 7;
const ll llinf = 1e18;

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

// dp[i][j] = min(dp[h][j - 1] + f(h + 1, i))
int n, k;
int a[maxn];
ll ans;

ll lsum[maxn], rsum[maxn];
int lmax[maxn], rmax[maxn];

int cnt[maxn];
vector<int> cur;

void add(ll a) {
    a %= k;
    if (a < 0)
        a += k;
    cnt[a] ++;
    cur.pb(a);
}

int get(ll a) {
    a %= k;
    if (a < 0)
        a += k;
    return cnt[a];
}

void clear() {
    for (int i : cur) cnt[i]--;
    cur.clear();
}

void solve(int l, int r) {
    if (l == r) {
        // ans++;
        return;
    }
    int m = (l + r) >> 1;
    for (int i = m; i >= l; i--) {
        lsum[i] = a[i];
        lmax[i] = a[i];

        if (i + 1 <= m) {
            lsum[i] += lsum[i + 1];
            amax(lmax[i],  lmax[i + 1]);
        }
    }
    for (int i = m + 1; i <= r; i++) {
        rsum[i] = a[i];
        rmax[i] = a[i];

        if (i - 1 >= m + 1) {
            rsum[i] += rsum[i - 1];
            amax(rmax[i], rmax[i - 1]);
        }
    }

    for (int i = m, j = m; i >= l; i--) {
        while (j < r && lmax[i] >= rmax[j + 1]) j++, add(rsum[j]);
        ans += get((ll)lmax[i] - lsum[i]);
    }
    clear();
    for (int i = m + 1, j = m + 1; j <= r; j++) {
        while (i > l && rmax[j] > lmax[i - 1]) i--, add(lsum[i]);
        ans += get((ll)rmax[j] - rsum[j]);
    }
    clear();
    solve(l, m);
    solve(m + 1, r);
}

int main() {
    // files1;
    read(n, k);
    for (int i = 0; i < n; i++) read(a[i]);

    solve(0, n - 1);
    cout << ans << "\n";
    return 0;
}