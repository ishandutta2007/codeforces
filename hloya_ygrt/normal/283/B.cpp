// hloya template v22

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

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes = -1){cout << mes;exit(0);}

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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 3e5 + 12, base = 1e9 + 7;
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

bool cycle[maxn][2], depends[maxn][2];
int used[maxn][2];
ll y[maxn][2];
int a[maxn];
int n;

ll dfs(int v, int type) {
    used[v][type] = 2;
    int to;
    if (type == 0) {
        if (v + a[v] >= n) {
            cycle[v][type] = 0;
            depends[v][type] = 0;
            y[v][type] = a[v];
        }
        to = v + a[v];
    } else {
        if (v == 0)
            depends[v][type] = 1;
        if (v - a[v] < 0) {
            cycle[v][type] = 0;
            y[v][type] = a[v];
        }
        to = v - a[v];
    }

    if (to >= 0 && to < n) {
        if (used[to][type^1] == 2) {
            cycle[v][type] = 1;
            depends[v][type] = 0;
        } else {
            if (!used[to][type^1])
                dfs(to, type^1);
            cycle[v][type] = cycle[to][type^1];
            depends[v][type] = depends[to][type^1];
            y[v][type] = y[to][type^1] + a[v];
        }
    }

    used[v][type] = 1;
    return y[v][type];
}

int main() {
    read(n);

    for (int i = 1; i < n; i++)
        read(a[i]);
    for (int i = 1; i < n; i++) {
        dfs(i, 1);
        if (cycle[i][1])
            cout << -1 << endl;
        else {
            ll res = i + y[i][1];
            if (depends[i][1])
                res += i;
            cout << res << endl;
        }
    }
    return 0;
}