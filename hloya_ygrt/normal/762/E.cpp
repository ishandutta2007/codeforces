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

struct query {
    int r, z;
    pii x;
    
    query() {}
    query(int r, pii x, int z):r(r), x(x), z(z) {}

    bool operator < (const query & T) const {
        return r < T.r;
    }
};

int r[maxn], f[maxn], x[maxn];

vector<query> q;
vector<pair<pair<int, int>, pii> > pt;
vector<pii> pzh;

int szh(pii y) {
    int pos = lower_bound(all(pzh), y) - pzh.begin() + 1;
    return pos;
}

int tree[maxn];

int sum(int r) {
    int res = 0;
    while (r > 0) {
        res += tree[r];
        r -= r & -r;
    }
    return res;
}

void add(int pos) {
    while (pos < maxn) {
        tree[pos]++;
        pos += pos & -pos;
    }
}

int main()
{
    int n, k;
    read(n, k);


    for (int i = 0; i < n; i++) {
        read(x[i], r[i], f[i]);
        pzh.pb(mp(r[i], i));
        pt.pb(mp(mp(f[i], x[i]), mp(r[i], i)));
    }

    sort(all(pzh));
    sort(all(pt));

    for (int i = 0; i < n; i++) {
        int L = x[i] - r[i], R = x[i] + r[i];

        for (int j = f[i] - k; j <= f[i] + k; j++) {
            if (j < 1 || j > (int)1e4) continue;
            int l = lower_bound(all(pt), mp(mp(j, L), mp(-inf, -inf))) - pt.begin();
            int r = upper_bound(all(pt), mp(mp(j, R), mp(+inf, inf))) - pt.begin() - 1;
            if (l <= r) {
                q.pb(query(r, mp(::r[i], i), 1));
                if (l != 0) q.pb(query(l - 1, mp(::r[i], i), -1));
            }
        }
    }
    ll ans = 0;
    int cur_r = -1;
    sort(all(q));

    for (int i = 0; i < q.size(); i++) {
        int R = q[i].r;
        while (cur_r < R) {
            cur_r++;
            add(szh(pt[cur_r].s));
        }
        int curQ = sum(szh(q[i].x));
        ans += q[i].z * (cur_r + 1 - curQ);
    }
    cout << ans;
    return 0;
}