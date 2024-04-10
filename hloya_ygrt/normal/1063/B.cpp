// hloya template v25
  
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e3 + 12, base = 1e9 + 7;
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

char c[maxn][maxn];
int d[maxn][maxn];
pii p[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int fa[4] = {0, 0, 0, 1};
int fb[4] = {0, 1, 0, 0};

bool used[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;

    int r, c;
    cin >> r >> c;
    r--, c--;

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> ::c[i][j];
            // d[i][j] = mp(inf, inf);
            d[i][j] = inf;
            p[i][j] = mp(inf, inf);
        }
        d[r][c] = 0;
        p[r][c] = mp(0, 0);

    queue<pair<int, int> > q;
    q.push(mp(r, c));

    while (!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            int na = p[i][j].f + fa[k], nb = p[i][j].s + fb[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && ::c[ni][nj] != '*') {
                // d[ni][nj] = min(d[ni][nj], mp(na, nb));
                if (na + nb < d[ni][nj]) {
                    d[ni][nj] = na + nb;
                    p[ni][nj] = mp(na, nb);
                    q.push(mp(ni, nj));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int a = p[i][j].f, b = p[i][j].s;
        if (a <= x && b <= y) ans++;
    }
    cout << ans << endl;
}

int main() {
    // files1;
    fast_io;
    solve();
    return 0;
}