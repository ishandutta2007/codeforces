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
const int MAXN = 1e6 + 6 , MAXM = 1e4 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, lst[MAXN][2], cnt[MAXN][2];
string s;

void Solve(){
    cin >> n >> s;
    lst[0][0] = lst[0][1] = -1;
    for (int i = 0; i < n; i++){
        lst[i+1][0] = lst[i][0];
        lst[i+1][1] = lst[i][1];
        cnt[i+1][0] = cnt[i][0] + (s[i] == '0');
        cnt[i+1][1] = cnt[i][1] + (s[i] == '1');
        if (s[i] != '?') lst[i+1][s[i] - '0'] = i;
    }
//    cout << ":D IDKSODSDOSKD\n";
    for (int d = 1; d <= n; d++){
        int ans = 0, id = 0;
        while(id + d <= n){
            if (cnt[id + d][1] == cnt[id][1]){
                id += d; ans ++;
            }else if (cnt[id + d][0] == cnt[id][0]){
                id += d; ans ++;
            }else{
                id = min(lst[id + d][0], lst[id + d][1]) + 1;
            }
        }
        cout << ans << ' ';
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