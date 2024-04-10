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
const int MAXN = 1e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, m;
string s[1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int i, int j){
    s[i][j] = '.';
    for (int z = 0; z < 4; z++){
        int x = i + dx[z], y = j + dy[z];
        if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '.') continue;
        //cout << x << ' ' << y << endl;
        dfs(x, y);
    }
}

void Solve () {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    int row = 0, col = 0;
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < m; j++){
            if (s[i][j] == '#' && (j == 0 || s[i][j-1] == '.')){
                cnt ++;
            }
        }
        if (cnt > 1){
            cout << -1;
            return;
        }
        if (!cnt) row ++;
    }
    for (int i = 0; i < m; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (s[j][i] == '#' && (j == 0 || s[j-1][i] == '.')){
                cnt ++;
            }
        }
        if (cnt > 1){
            cout << -1;
            return;
        }
        if (!cnt) col ++;
    }
    if ((row > 0) != (col > 0)){
        cout << -1;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == '.') continue;
            //cout << "DNEUNDU: " << i << ' ' << j << endl;
            ans ++; dfs(i, j);
        }
    }
    cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/