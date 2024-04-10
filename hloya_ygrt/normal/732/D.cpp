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

int d[maxn], a[maxn], n, m;
int bk[maxn];

bool can(int last) {
    for (int i = 1; i <= m; i++)
        bk[i] = -1;
    for (int i = 0; i <= last; i++)
        bk[d[i]] = i;
    vector<pair<int, int> > mda;
    for (int i = 1; i <= m; i++) {
        if (bk[i] == -1)
            return 0;
        mda.pb(mp(bk[i], i));
    }

    sort(all(mda));
    int cur = 0;

    for (int i = 0; i < m; i++) {
        int pos = mda[i].f, col = mda[i].s;
        if (i)
            cur += pos - mda[i - 1].f - 1;
        else
            cur += pos;
        if (cur >= a[col])
            cur -= a[col];
        else
            return false;
    }
    return true;
}

int main() {
    read(n, m);

    for (int i = 0; i < n; i++)
        read(d[i]);
    for (int i = 1; i <= m; i++)
        read(a[i]);
    int l = 0, r = n - 1;
    while (r - l > 1) {
        int c = (l + r) >> 1;
        if (can(c))
            r = c;
        else
            l = c;
    }
    if (can(l))
        cout << l + 1;
    else if (can(r))
        cout << r + 1;
    else
        cout << -1;
    return 0;
}