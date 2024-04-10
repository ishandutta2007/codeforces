#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

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

#define files1 freopen("decomposable.in","r",stdin)
#define files2 freopen("decomposable.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "NO"){cout << mes;exit(0);}
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

const int inf = 1e9 + 20;
const long double eps = 1e-12;
const ll llinf = 2e18 + 5;
const int maxn = 1e6 + 500;
const int mod = 258280327;

int sz[maxn];
vector<int> g[maxn];

void dfs(int v, int par = -1) {
    sz[v] = 1;
    for (const auto to : g[v]) {
        if (to != par) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int64_t out_ways = 0;

void dfs2(int v, int par, int h = 1) {
    sz[v] = 1;
    out_ways += h;
    for (auto to : g[v]) {
        if (to != par) {
            dfs2(to, v, h + 1);
            sz[v] += sz[to];
        }
    }
}

int maxpow[maxn];
bitset<500001> dp;

int main() {
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    fast_io;

    int n;
    cin >> n;
    // n = 1000000;

    for (int i = 1; i < n; i++) {
        int p;
        // p = i;
        // p = mt_rand() % i + 1;
        // p = 1;
        cin >> p;
        p--;


        g[p].push_back(i);
        g[i].push_back(p);
    }

    dfs(0);

    int cc = 0;
    while (true) {
        int bb;
        int maxson = 0;
        for (auto to : g[cc]) {
            if (to > cc) {
                if (sz[to] > maxson) {
                    bb = to;
                    maxson = sz[to];
                }
            }
        }
        if (maxson > n / 2) {
            cc = bb;
        } else break;
    }

    dfs2(cc, -1);

    std::vector<int> hps;
    for (int to : g[cc]) {
        hps.push_back(sz[to]);
    }

    int BUBEN = (n / 2);
    // dp[0] = 1;
    dp = 0;
    dp[0] = 1;

    vector<int> COUNT(maxn);
    for (auto x : hps) {
        COUNT[x]++;
    }

    for (int i = 2; i < maxn; i++) {
        maxpow[i] = maxpow[i / 2] + 1;
    }

    for (int i = 0; i < maxn; i++) {
        if (COUNT[i] > 0) {
            int count = COUNT[i];
            int x = i;

            while (count > 1) {
                int bb = maxpow[count];
                for (int i = 0; i < bb; i++) {
                    dp = dp | (dp << (x * (1 << i)));
                }
                count = count - (1 << bb) + 1;
            }
            dp = dp | (dp << x);
            // 3 -> 11
        }
    }
    
    // for (auto x : hps) {
    //     dp = dp | (dp << x);
    // }


    int mx = 0;
    for (int i = 0; i <= BUBEN; i++) {
        if (dp[i]) {
            mx = i;
        }
    }

    // assert(mx == BUBEN || mx == BUBEN - 1);

    cout << out_ways + (1ll * mx * (n - 1 - mx)) << endl;
    // cout << current_time;
    return 0;
}