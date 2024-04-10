// hloya template v21

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

//clock_t start_time = clock();
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
const int maxn = 3e3 + 12, base = 1e9 + 7;
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

vector<int> g[maxn];
int dist[maxn][maxn];

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < m; i++) {
        int u, v;
        read(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int s1, t1, l1, s2, t2, l2;
    read(s1, t1, l1);
    read(s2, t2, l2);

    s1--, t1--, s2--, t2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dist[i][j] = inf;
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to:g[v])
                if (dist[i][to] == inf) {
                    dist[i][to] = dist[i][v] + 1;
                    q.push(to);
                }
        }
    }

    int ans = -1;
    if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2)
        ans = m - dist[s1][t1] - dist[s2][t2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            // s1 -> i -> j -> t1
            // s2 -> i -> j -> t2

            int realL1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            int realL2 = dist[s2][i] + dist[i][j] + dist[j][t2];

            if (realL1 <= l1 && realL2 <= l2)
                amax(ans, m - realL1 - dist[s2][i] - dist[j][t2]);

            swap(s2, t2);
            
            realL1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            realL2 = dist[s2][i] + dist[i][j] + dist[j][t2];

            if (realL1 <= l1 && realL2 <= l2)
                amax(ans, m - realL1 - dist[s2][i] - dist[j][t2]);
            swap(s2, t2);            
        }
    cout << (ans);
    return 0;
}