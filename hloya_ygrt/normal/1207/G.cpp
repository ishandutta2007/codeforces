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
const int maxn = (int)1e6 + 228, base = 1e9 + 7;
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

struct vertex {
	int next[26];
	bool leaf;
	int p;
	char pch;
	int link;
	int go[26];
};

vertex t[maxn+1];
int sz;

void init() {
	t[0].p = t[0].link = -1;
	memset (t[0].next, 255, sizeof t[0].next);
	memset (t[0].go, 255, sizeof t[0].go);
	sz = 1;
}

int add_string (const string & s) {
	int v = 0;
	for (size_t i=0; i<s.length(); ++i) {
		char c = s[i]-'a';
		if (t[v].next[c] == -1) {
			memset (t[sz].next, 255, sizeof t[sz].next);
			memset (t[sz].go, 255, sizeof t[sz].go);
			t[sz].link = -1;
			t[sz].p = v;
			t[sz].pch = c;
			t[v].next[c] = sz++;
		}
		v = t[v].next[c];
	}
	t[v].leaf = true;
    return v;
}

int go (int v, char c);

int get_link (int v) {
	if (t[v].link == -1)
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else{
			t[v].link = go (get_link (t[v].p), t[v].pch);
        }
	return t[v].link;
}

int go (int v, char c) {
	if (t[v].go[c] == -1)
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
	return t[v].go[c];
}

vector<pair<int, int>> q[maxn];
vector<int> g1[maxn], g2[maxn];

int tin[maxn], tout[maxn];
vector<int> order;

void dfs(int v) {
    tin[v] = order.size();
    order.pb(v);
    for (auto e : g1[v]) {
        dfs(e);
    }
    tout[v] = (int)order.size() - 1;
}

int fnw[maxn];

void add(int pos, int val) {
    pos += 1;
    while (pos < maxn) {
        fnw[pos] += val;
        pos += pos & -pos;
    }
}

int get(int r) {
    r++;
    int res = 0;
    while (r > 0) {
        res += fnw[r];
        r -= r & -r;
    }
    return res;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}
char c[maxn];
int p[maxn];

bool used[maxn];
int ans[maxn];

void dfs2(int v, int inb) {
    used[v] = 1;
    inb = go(inb, c[v] - 'a');

    // cout << v << ' ' << inb << endl;

    add(tin[inb], 1);

    for (auto e : g2[v]) {
        dfs2(e, inb);
    }

    for (auto [id, u] : q[v]) {
        ans[id] = get(tin[u], tout[u]);
    }

    add(tin[inb], -1);
}



int main() {
    // files1;
    fast_io;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            cin >> c[i];
            p[i] = -1;
        } else {
            cin >> p[i] >> c[i];
            p[i]--;
            g2[p[i]].pb(i);
        }
    }

    int m;
    cin >> m;

    init();

    for (int i = 0; i < m; i++) {
        int v;
        string s;
        cin >> v >> s;
        v--;
        int mda;
        q[v].eb(i, mda=add_string(s));
    }

    // return 0;

    for (int i = 1; i < sz; i++) {
        int par = get_link(i);
        // cout << par << ' ' << i << endl;
        g1[par].pb(i);
    }

    dfs(0);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs2(i, 0);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}