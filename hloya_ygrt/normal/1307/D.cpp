// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
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
  
// #define endl '\n'
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
  
// mt19937_64 mt_rand(
//     chrono::system_clock::now().time_since_epoch().count()
// );

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
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e6 + 3, base = (int) 1e9 + 7;
const ll llinf = 2e18 + 5;

vector<int> g[maxn];

void bfs(int s, vector<int>& dist) {
    vector<int> us(dist.size(), 0);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    us[s] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto to : g[v]) {
            if (!us[to] && dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                us[to] = 1;
                q.push(to);
            }
        }
    }
}

int tree[maxn];
void upd(int pos, int val) {
    while (pos < maxn) {
        tree[pos] = max(tree[pos], val);
        pos += pos & -pos;
    }
}

int get(int r) {
    assert(r > 0);
    int ans = -1;
    while (r > 0) {
        ans = max(ans, tree[r]);
        r -= r & -r;
    }
    return ans;
}

int main() {
    // files1; 
    fast_io;
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> d0(n, inf), dn(n, inf);

    bfs(0, d0);
    bfs(n-1, dn);

    int ans = d0[n-1];
    memset(tree, -1, sizeof(tree));

    int ans2 = 0;

    for (int i = 0; i < k; i++) {
        int x = d0[a[i]], y = dn[a[i]];

        int pos = x - y;
        pos += n;

        pos = 2 * n - pos;
        int cc = get(pos);
        if (cc != -1) {
            ans2 = max(ans2, x + cc + 1);
        }
        upd(pos, y);
    }

    memset(tree, -1, sizeof(tree));

    for (int i = k - 1; i >= 0; i--) {
        int x = d0[a[i]], y = dn[a[i]];

        int pos = x - y;
        pos += n;

        pos = 2 * n - pos;
        int cc = get(pos);
        if (cc != -1) {
            ans2 = max(ans2, x + cc + 1);
        }
        upd(pos, y);
    }

    ans = min(ans, ans2);
    cout << ans;
    return 0;
}