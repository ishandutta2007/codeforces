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
const int maxn = 1e6 + 10, base = 1e9 + 7;
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

int v[maxn], c[maxn];

int lg[maxn];

int mnSt[maxn][22];
int n, k;

void buildMn() {
    for (int i = 0; i < n; i++)
        mnSt[i][0] = c[i];
    for (int i = 1; i < 22; i++)
        for (int j = 0; j + (1 << i) <= n; j++) {
            mnSt[j][i] = min(
                mnSt[j][i - 1],
                mnSt[j + (1 << (i - 1))][i - 1]);
        }
}

int mxSt[maxn][22];

void buildMx() {
    for (int i = 0; i < n; i++)
        mxSt[i][0] = v[i];
    for (int i = 1; i < 22; i++)
        for (int j = 0; j + (1 << i) <= n; j++) {
            mxSt[j][i] = max(
                mxSt[j][i - 1],
                mxSt[j + (1 << (i - 1))][i - 1]);
        }
}

int get_min(int l, int r) {
    int j = lg[r - l + 1];
    return min(
        mnSt[l][j],
        mnSt[r - (1 << j) + 1][j]);
}

int get_max(int l, int r) {
    int j = lg[r - l + 1];
    return max(
        mxSt[l][j],
        mxSt[r - (1 << j) + 1][j]);
}

int main() {
    for (int i = 2; i < maxn; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    

    read(n, k);

    for (int i = 0; i < n; i++) 
        read(v[i]), v[i] *= 100;
    for (int i = 0; i < n; i++)
        read(c[i]);

    buildMn();
    buildMx();

    ld res = 0;

    vector<int> mda;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (get_min(i, m) < get_max(i, m))
                r = m;
            else
                l = m;
        }
        int kek = -inf;
        for (int j = max(i, l - 5); j <= min(n - 1, l + 5); j++) {
            kek = max(kek, min(get_min(i, j), get_max(i, j)));
        }
        mda.pb(kek);
    }

    sort(all(mda));

    ld cf = (ld)n / k;
    int f = n - 1;

    for (int i = 0; f >= k - 1; i++, f--) {
        res += (ld)mda[i] / cf;
        cf *= (ld)n - i - 1;
        cf /= (ld)n - k - i;
    }

    cout << fixed << setprecision(20) << res;
    return 0;
}