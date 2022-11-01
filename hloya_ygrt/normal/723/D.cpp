#include <bits/stdc++.h>
#include <valarray>

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
 
using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
// #include <unordered_map>
// #include <unordered_set>
 
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
 
template<typename T>
void read(T& a) {
    a = input<T>();
}
 
template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}
 
template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}
 
template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 4e5 + 10, base = 1073676287;
const ll llinf = 1e18 + 1;

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
int n, m, k, kek;
bool a[51][51];
int cmp[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isval(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y];
}

bool good;
int dfs(int x, int y) {
    cmp[x][y] = kek;
    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        good = 0;

    int cur = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isval(nx, ny) && cmp[nx][ny] == 0) {
            cur += dfs(nx, ny);
        }
    }
    return cur;
}

int main() {
    read(n, m, k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c = endl;
            while (c == endl)
                c = getchar();
            a[i][j] = c == '.';
        }
    
    vector<pair<int, int> > sz;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] && cmp[i][j] == 0) {
                kek++;
                good = 1;
                int cur = dfs(i, j);
                if (good) {
                    sz.pb(mp(cur, kek));
                }
            }
        }

    sort(all(sz));
    set<int> to_del;

    int ans = 0;
    for (int i = 0; i < sz.size() - k; i++) {
        to_del.insert(sz[i].s);
        ans += sz[i].f;
    }
    cout << ans << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (to_del.count(cmp[i][j]))
                a[i][j] = 0;
            if (!a[i][j])
                printf("*");
            else
                printf(".");
        }
        puts("");
    }
    return 0;
}