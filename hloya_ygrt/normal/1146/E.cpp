#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v26

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
using namespace std;

bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))


#define ull unsigned long long
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
  
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
 int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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

#define abs(x) (x)>0?(x):-(x)

ull kek = 0;

struct sset {
    ull data[1570];

    sset() {
        memset(data, 0, sizeof(data));
    }

    void set(int pos, int val) {
        // assert(pos >= 0);
        if (val) {
            data[pos / 64] |= 1ULL << (pos % 64);
        }
    }

    int get(int pos) {
        // assert(pos >= 0);
        ull mda = data[pos / 64] & (1ULL << (pos % 64));
        if (mda)
            return 1;
        return 0;
    }

    void flipsingle(int b, int l, int r) {
        // assert(l <= r);
        // assert(l >= 0);
        // assert(r < 64);
        // cout << b << ' ' << l << ' ' << r << endl;

        int len = r - l + 1;
        ull mda = (1ULL << len) - 1ULL;

        if (len == 64)
            mda = kek;

        mda = mda << l;
        data[b] ^= mda;
    }

    void setsingle(int b, int l, int r, int val) {
        // assert(l <= r);
        // assert(l >= 0);
        // assert(r < 64);
        // cout << b << ' ' << l << ' ' << r << ' ' << val << endl;
        int len = r - l + 1;

        ull mda = (1ULL << len) - 1ULL;

        if (len == 64)
            mda = kek;

        mda = mda << l;
        // cout << mda << endl;

        if (val == 0) {
            mda ^= kek;
            data[b] &= mda;
        } else {
            data[b] |= mda;
        }
    }

    void flip(int l, int r) {
        // assert(l <= r);
        // assert(l >= 0);
        int lb = l / 64;
        int rb = r / 64;
        // assert(lb <= rb);
        if (lb == rb) {
            flipsingle(lb, l % 64, r % 64);
        } else {
            flipsingle(lb, l % 64, 63);
            flipsingle(rb, 0, r % 64);
            for (int i = lb + 1; i < rb; i++) {
                // cout << "mda" << endl;
                data[i] ^= kek;
            }
        }
    }

    void upd(int l, int r, int val) {
        // assert(l <= r);
        // assert(l >= 0);
        int lb = l / 64;
        int rb = r / 64;
        if (lb == rb) {
            setsingle(lb, l % 64, r % 64, val);
        } else {
            setsingle(lb, l % 64, 63, val);
            setsingle(rb, 0, r % 64, val);
            for (int i = lb + 1; i < rb; i++) {
                if (val)
                    data[i] = kek;
                else
                    data[i] = 0;
            }
        }
    }
};

int ans[maxn];

int main() {
    kek -= 1;

    // files1;
    fast_io;

    int n, q;
    cin >> n >> q;  

    vector<tuple<int, int, int> > e;
    vector<int> a;

    e.reserve(n);
    a.reserve(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            a.pb(abs(x));
            e.pb(mt(abs(x), (x > 0) ? 0 : 1, i));
        }
    }

    sort(all(e));
    sort(all(a));

    sset bs;

    for (int i = 0; i < e.size(); i++) {
        bs.set(i, get<1>(e[i]));
        // cerr << get<1>(e[i]) << ' ';
    }

    // cerr << endl;
    // for (auto e : a)
    //     cerr << e << ' ';
    // cerr << endl;

    if (a.size())
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;

        int z = x > 0 ? 0 : 1;

        int y = abs(x);
        int it = lower_bound(all(a), y) - a.begin();
        it--;
        // [0, it]
        // cerr << i << endl;

        if ((z == 0 && c == '<') || (z == 1 && c == '>')) {
            if (it >= 0) {
                // cerr << "flip " << 0 << ' ' << it << endl;
                bs.flip(0, it);
            }
        }

        int it2 = upper_bound(all(a), y) - a.begin();
        
        it2--;
        it++;

        // [it, it2]
        if (it <= it2) {
            if ((z == 0 && c == '<') || (z == 1 && c == '>')) {
                // cerr << "set " << it << ' ' << it2 << ' ' << z << endl;
                bs.upd(it, it2, z);
            }
        }

        if (c == '<') {
            if (it2 + 1 < e.size()) {
                // cerr << "set " << it2 + 1 << ' ' << e.size() - 1 << ' ' << 0 << endl;
                bs.upd(it2 + 1, (int)e.size() - 1, 0);
            }
        } else {
            if (it2 + 1 < e.size()) {
                // cerr << "set " << it2 + 1 << ' ' << e.size() - 1 << ' ' << 1 << endl;
                bs.upd(it2 + 1, (int)e.size() - 1, 1);
            }
        }
    }


    for (int i = 0; i < e.size(); i++) {
        int x, t, j;
        tie(x, t, j) = e[i];


        ans[j] = bs.get(i);
        // cout << ans[j] << ' ';
        if (ans[j] == 0)
            ans[j] = x;
        else
            ans[j] = -x;
    }
    // cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}