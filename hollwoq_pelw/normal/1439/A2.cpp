/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}
#define debug(x) cout << #x << " : " << endl << x << endl;
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 3e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// rand
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int n, m, a[202][202];
vector<vector<pii>> ans;

void add(int i, int j, int x, int y){
    vector<pii> lol;
    for (int x1 = x; x1 < x + 2; x1 ++){
        for (int y1 = y; y1 < y + 2; y1 ++){
            if (x1 != i || y1 != j){
                lol.pb({x1, y1});
                a[x1][y1] ^= 1;
            }
        }
    }
    ans.pb(lol);
}
void add2(int x, int y, int i1, int j1, int i2, int j2){
    add(i1, j1, x, y);
    add(i2, j2, x, y);
}

void Solve() {
    cin >> n >> m;
    ans.clear();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (i < n - 1 && j < m - 1){
                if (a[i][j]){
                    add(i + 1, j, i, j);
                }
            }else if (i == n - 1 && j < m - 1){
                if (!a[i][j] && !a[i + 1][j]){
                
                }else if (a[i][j] && a[i + 1][j]){
                    add(i + 1, j + 1, i, j);
                }else if (!a[i][j]){
                    add(i, j, i, j);
                }else if (!a[i + 1][j]){
                    add(i + 1, j, i, j);
                }
            }else if (i < n - 1 && j == m - 1){
                if (!a[i][j] && !a[i][j + 1]){
                
                }else if (a[i][j] && a[i][j + 1]){
                    add(i + 1, j + 1, i, j);
                }else if (!a[i][j]){
                    add(i, j, i, j);
                }else if (!a[i][j + 1]){
                    add(i, j + 1, i, j);
                }
            }else{
                int cnt = 0;
                for (int x = i; x <= n; x++){
                    for (int y = j; y <= m; y++){
                        cnt += a[x][y];
                    }
                }
                if (cnt == 4){
                    add(i, j, i, j);
                }
                cnt = 0;
                for (int x = i; x <= n; x++){
                    for (int y = j; y <= m; y++){
                        cnt += a[x][y];
                    }
                }
                if (cnt == 1){
                    if (!a[i][j] && !a[i + 1][j]){
                        add2(i, j, i, j, i + 1, j);
                    }else{
                        add2(i, j, i, j + 1, i + 1, j + 1);
                    }
                }
                cnt = 0;
                for (int x = i; x <= n; x++){
                    for (int y = j; y <= m; y++){
                        cnt += a[x][y];
                    }
                }
                if (cnt == 2){
                    int opt = 0;
                    for (int x = i; x <= n; x++){
                        for (int y = j; y <= m; y++){
                            if (a[x][y] && !opt) add(x, y, i, j), opt = 1;
                        }
                    }
                }
                cnt = 0;
                for (int x = i; x <= n; x++){
                    for (int y = j; y <= m; y++){
                        cnt += a[x][y];
                    }
                }
                if (cnt == 3){
                    int opt = 0;
                    for (int x = i; x <= n; x++){
                        for (int y = j; y <= m; y++){
                            if (!a[x][y] && !opt) add(x, y, i, j), opt = 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto v : ans){
        cout << v << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/