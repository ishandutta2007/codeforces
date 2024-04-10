// hloya template v20

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
const int maxn = 5e2 + 12, base = 1e9 + 7;
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

void amax(int& x, int y) {
    x = max(x, y);
}

void amin(int& x, int y) {
    x = min(x, y);
}

vector<pair<pair<pii, int>, pii> > answers;

int a[maxn][maxn];
pair<pii, pii> query[(int)6e5 + 100];

pii dp[maxn][maxn][2];
bool dp2[maxn][maxn][maxn], need[maxn][maxn][maxn];

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c = endl;
            while (c == endl)
                c = getchar();
            a[i][j] = c == '.';
        }
    int q;
    read(q);

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        read(x1, y1, x2, y2);
        x1--, y1--, x2--, y2--;
        query[i] = mp(mp(x1, y1), mp(x2, y2));
        need[x1][y1][y2] = 1;
        need[x2][y2][x1] = 1;
    }

    int t = 0;
    // row col_to sloj

    for (int j = m - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0; i--)
            for (int k = j; k < m; k++) {
                dp[i][k][t] = mp(inf, -inf);
                if (!a[i][j])
                    continue;
                if (k == j) {
                    dp[i][k][t] = mp(i, i);
                    amax(dp[i][k][t].s, dp[i + 1][k][t].s);    
                    if (need[i][j][k])
                        answers.pb(mp(mp(mp(i, j), k), dp[i][k][t]));
                    continue;
                }
                if (a[i][j + 1]) {
                    amin(dp[i][k][t].f, dp[i][k][t^1].f);
                    amax(dp[i][k][t].s, dp[i][k][t^1].s);
                }
                if (a[i + 1][j]) {
                    amin(dp[i][k][t].f, dp[i + 1][k][t].f);
                    amax(dp[i][k][t].s, dp[i + 1][k][t].s);
                }

                if (need[i][j][k])
                    answers.pb(mp(mp(mp(i, j), k), dp[i][k][t]));
            }
        t ^= 1;
    }
    sort(all(answers));
    
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            for (int k = 0; k <= j; k++) {
                if (!a[i][j])
                    continue;
                if (k == j) {
                    dp2[i][j][k] = 1;
                    continue;
                }
                if (j && a[i][j - 1])
                    dp2[i][j][k] |= dp2[i][j - 1][k];
                if (i && a[i - 1][j])
                    dp2[i][j][k] |= dp2[i - 1][j][k];
            }
    for (int i = 0; i < q; i++) {
        int x1 = query[i].f.f, y1 = query[i].f.s, x2 = query[i].s.f, y2 = query[i].s.s;
        int pos = lower_bound(all(answers), mp(mp(mp(x1, y1), y2), mp(-inf, -inf))) - answers.begin();
        pii range = answers[pos].s;

        if (range.f <= x2 && x2 <= range.s && dp2[x2][y2][y1]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}