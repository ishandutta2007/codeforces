#include <bits/stdc++.h>

using namespace std;

bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void bad(string mes = "Impossible"){cout << mes;exit(0);}

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


const int inf = 1e9 + 20;
const int maxn = 2e5 + 12, base = 1e9 + 7;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const ll llinf = 2e18 + 5;

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }

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

vector<int> cur;
int used[maxn];

vector<int> g[maxn];

void dfs(int v) {
    cur.pb(v + 1);
    used[v] = 1;

    for (int to:g[v]) {
        if (!used[to]) {
            dfs(to);
            cur.pb(v + 1);
        }
    }
}

int main() {
    int n, m, k;
    fast_io;
//    files1;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);
    vector<int> st;

    int cnt = 0;
    int limit = (2 * n + k - 1) / k;

    for (int i = 0; i < cur.size(); i++) {
        st.pb(cur[i]);
        if (st.size() == limit) {
            cout << st.size() << ' ';
            for (int j : st)
                cout << j << ' ';
            cout << endl;
            cnt++;
            st.clear();
        }
    }

    assert(cnt <= k);

    if (cnt < k) {
        if (st.empty())
            st.pb(1);
        cout << st.size() << ' ';
        for (int j : st)
            cout << j << ' ';
        cout << endl;
        cnt++;
    }
    while (cnt < k) {
        cout << 1 << ' ' << 1 << endl;
        cnt++;
    }
    return 0;
}