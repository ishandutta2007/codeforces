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
const int maxn = 1e3 + 12, base = 1e9 + 7;
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

bitset<501> dp[501][62][2];

int main() {
    int n, m;
    fast_io;
//    files1;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        dp[u][0][t][v] = 1;
    }

    for (int i = 1; i <= 60; i++) {
        for (int v = 0; v < n; v++) {
            for (int f = 0; f < 2; f++) {
                for (int s = 0; s < n; s++)
                    if (dp[v][i - 1][f][s]) {
                        dp[v][i][f] |= dp[s][i - 1][f^1];
                    }
            }
        }
    }

//    cout << dp[0][1][0] << endl;
    for (int i = 0; i < n; i++)
        if (dp[0][60][0][i])
            bad("-1");
    bitset<501> curKek, newCurKek;

    int curFlag = 0;
    ll ans = 0;
    curKek[0] = 1;

    for (int i = 60; i >= 0; i--) {
        newCurKek = 0;
        for (int j = 0; j < n; j++)
            if (curKek[j]) {
                newCurKek |= dp[j][i][curFlag];
            }
        if (newCurKek.count() != 0) {
            ans |= 1ll << i;
            curKek = newCurKek;
            curFlag ^= 1;
        }
    }
    if (ans > (ll)1e18) {
        bad("-1");
    }
    cout << ans;
    return 0;
}