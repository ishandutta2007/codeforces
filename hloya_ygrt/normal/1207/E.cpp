// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v27

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

void bad(string mes = "Impossible") {cout << mes;exit(0);}
void bad(int mes) {cout << mes;exit(0);}

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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
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

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e6 + 228, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

const int mod = 998244353;

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int fact[maxn];

int fnd(vector<int> a) {
    sort(all(a));
    int gs = 1;
    int res = 1;
    for (int i = 1; i <= a.size(); i++) {
        if (i == a.size() || a[i] != a[i - 1]) {
            res = 1ll * res * fact[gs] % mod;
            gs = 1;
        } else gs++;
    }
    return res;
}

int fnd(vector<pii> a) {
    sort(all(a));
    bool ok = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1].s > a[i].s)
            ok = false;
    }
    if (!ok) return 0;
    int gs = 1;
    int res = 1;
    for (int i = 1; i <= a.size(); i++) {
        if (i == a.size() || a[i] != a[i - 1]) {
            res = 1ll * res * fact[gs] % mod;
            gs = 1;
        } else gs++;
    }
    return res;
}

int main() {
    // files1;
    fast_io;

    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << i;
        if (i != 100)
        cout << ' ';
    }
    cout << endl;
    cout.flush();
    int x1;
    cin >> x1;

    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << (i << 7) << ' ';

        if (i != 100)
        cout << ' ';
    }
    cout << endl;
    cout.flush();

    int x2;
    cin >> x2;

    int xx = x1 ^ x2;

    int a = xx % (1 << 7);
    int b = xx / (1 << 7);
    b *= (1 << 7);
    assert((a ^ x1) == (b ^ x2));
    cout << "! " << (a ^ x1) << "\n";
    cout.flush();
    return 0;
}