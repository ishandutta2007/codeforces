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
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 1e3 + 12, base = 1e9 + 7;
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

bool a[maxn][maxn];
bool dp[maxn][maxn][4][3];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    // files1;
    read(n, m);

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c = endl;
            while (c == endl)
                c = getchar();
            if (c == 'S') {
                sx = i, sy = j;
            }
            if (c == 'T') {
                tx = i, ty = j;
                a[i][j] = 1;
            }
            if (c == '.') {
                a[i][j] = 1;
            }
        }
    queue<pair<pii, pii> > q;
    for (int i = 0; i < 4; i++) {
        q.push(mp(mp(sx, sy), mp(i, 0)));
        dp[sx][sy][i][0] = 1;
    }

    while (!q.empty()) {
        int x = q.front().f.f, y = q.front().f.s, dir = q.front().s.f, cnt = q.front().s.s;
        q.pop();

        // cout << x << ' ' << y << ' ' << dir << ' ' << cnt << endl;

        if (x == tx && y == ty) {
            bad("YES");
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            int ncnt = cnt;
            if (i != dir)
                ncnt++;

            if (ncnt < 3 && nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] &&
                (!dp[nx][ny][i][ncnt])) {
                dp[nx][ny][i][ncnt] = 1;
                q.push(mp(mp(nx, ny), mp(i, ncnt)));
            }
        }
        // exit(0);
    }
    puts("NO");
    return 0;
}