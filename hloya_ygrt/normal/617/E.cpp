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

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e6 + 10, base = 1e9 + 7;
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

const int maxk = (int)1e5 + 500 + 228;

int cnt[maxn], a[maxk];
const int block = 300;

struct Query {
    int l, r, it;
    Query() {}
    Query(int l, int r, int it):l(l), r(r), it(it) {}
    
    bool operator < (const Query & T) const {
        return r < T.r || (r == T.r && it < T.it);
    }
};

vector<Query> query[maxk / block];
ll res[maxk];

int n, m, k;
bool good(int l, int r) {
    int rs = a[r];
    if (l)
        rs ^= a[l - 1];
    return rs == k;
}

int main() {
    read(n, m, k);

    for (int i = 0; i < n; i++) {
        read(a[i]);
        if (i)
        a[i] ^= a[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        read(l, r);
        l--, r--;

        query[l / block] . push_back(Query(l, r, i));
    }

    for (int i = 0; i <= (m - 1) / block; i++) {
        if (query[i].empty())
            continue;
        sort(all(query[i]));

        int L = query[i][0].l, R = query[i][0].r;
        ll ans = 0;

        for (int j = L; j <= R; j++) {
            ans += cnt[a[j] ^ k];
            ans += good(L, j);
            cnt[a[j]]++;
        }
        // return 0;

        for (int j = 0; j < query[i].size(); j++) {
            int l = query[i][j].l, r = query[i][j].r, it = query[i][j].it;
            while (R < r) {
                R++;
                ans += cnt[a[R] ^ k];
                ans += good(L, R);
                cnt[a[R]]++;
            }
            while (L > l) {
                L--;
                int mda = L ? a[L - 1] : 0;
                cnt[a[L]]++;
                ans += cnt[mda ^ k];
                // ans += good(L, R);
                // cout << a[L] << endl;
            }
            while (L < l) {
                int mda = L ? a[L - 1] : 0;
                ans -= cnt[mda ^ k];
                cnt[a[L]]--;
                // ans -= good(L, R);
                L++;
            }

            res[it] = ans;
        }

        for (int j = L; j <= R; j++)
            cnt[a[j]]--;
        // clear up
    }
    // return 0;

    for (int i = 0; i < m; i++)
        printf("%lld\n", res[i]);
    return 0;
}