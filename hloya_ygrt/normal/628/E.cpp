// hloya template v18

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
// #define ld long double
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

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 3e3 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

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

struct tree {
    vector<int> data;
    int sz;

    tree() {}
    tree(int __n) {
        sz = __n;
        data.resize(sz + 1);
    }

    void add(int pos, int val) {
        pos++;
        while (pos <= sz) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int sum(int r) {
        r++;
        int ans = 0;
        while (r) {
            ans += data[r];
            r -= r & -r;
        }
        return ans;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} fnw[maxn + maxn];

int l[maxn][maxn], r[maxn][maxn];
int ld[maxn][maxn], ar[maxn][maxn];

vector<pii> x_s[maxn];

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < n + m; i++)
        fnw[i] = tree(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = getchar();
            ar[i][j] = c == 'z';
        }
        getchar();
    }

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            if (!j)
                l[i][j] = ar[i][j];
            else {
                l[i][j] = l[i][j - 1] + 1;
                if (!ar[i][j])
                l[i][j] = 0;
            }
        }
    for (int j = m - 1; j >= 0; j--)
        for (int i = 0; i < n; i++) {
            if (j == m - 1)
                r[i][j] = ar[i][j];
            else {
                r[i][j] = r[i][j + 1] + 1;
                if (!ar[i][j])
                r[i][j] = 0;
            }
            if (r[i][j])
                x_s[j + r[i][j] - 1].pb(mp(i, j));
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            if (i == n - 1 || j == 0)
                ld[i][j] = ar[i][j];
            else {
                ld[i][j] = ld[i + 1][j - 1] + 1;
                if (!ar[i][j])
                ld[i][j] = 0;
            }
        }

    ll ans = 0;
    for (int j = m - 1; j >= 0; j--) {
        for (pii e:x_s[j]) {
            fnw[e.f + e.s].add(e.s, 1);
        }
        for (int i = 0; i < n; i++) {
            int c = min(l[i][j], ld[i][j]);
            if (!c)
                continue;
            int num = i + j;
            ans += fnw[num].sum(j - c + 1, j);
        }
    }
    cout << ans << endl;
    return 0;
}