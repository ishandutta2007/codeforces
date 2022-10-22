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
const int MAXN = 1e3 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
// #define int long long

string kak = "LRUDX";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int x[MAXN][MAXN], y[MAXN][MAXN], p[MAXN][MAXN], n;

int opp(int dir){ return dir ^ 1; }
int inb(int r, int c) { return 1 <= min(r, c) && max(r, c) <= n; }

void dfs(int i, int j){
    for (int dir = 0; dir < 4; dir ++){
        int nx = i + dx[dir], ny = j + dy[dir];
        if (inb(nx, ny) && x[nx][ny] == x[i][j] && y[nx][ny] == y[i][j] && !~p[nx][ny]){
            p[nx][ny] = opp(dir);
            dfs(nx, ny);
        }
    }
}

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x[i][j] >> y[i][j];
            p[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (x[i][j] == i && y[i][j] == j){
                p[i][j] = 4;
                dfs(i, j);
            }else if (!~x[i][j]){
                for (int dir = 0; dir < 4; dir ++){
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if (inb(nx, ny) && !~x[nx][ny]){
                        p[i][j] = dir;
                        break ;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!~p[i][j]){
                cout << "INVALID\n";
                return ;
            }
        }
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << kak[p[i][j]];
        cout << endl;
    }
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

+===+===+===+===+===+== INP ==+===+===+===+===+===+


+===+===+===+===+===+== OUT ==+===+===+===+===+===+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/