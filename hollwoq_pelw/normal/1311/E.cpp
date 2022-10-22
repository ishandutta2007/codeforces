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

int n, d, a[5050];
vector<pii> flr[5050];

void Solve () {
    cin >> n >> d;
    int sum = 0;
    for (int i = 0; i < n; i++){
        a[i] = 1; sum += i;
    }
    if (sum < d){
        cout << "NO\n";
        return;
    }
    int cur = 1;
    for (int i = n - 1; i > cur; i--){
        if (sum == d) break;
        int tmp = sum - d;
        if (i - cur > tmp){
            cur = i - tmp;
            a[i - tmp] ++;
            sum -= tmp;
            a[i] --;
        }else{
            sum -= i - cur;
            a[cur] ++;
            a[i] --;
        }
        if (a[cur] == 2 * a[cur - 1]) cur ++;
    }
    if (sum == d){
        cout << "YES\n";
        int tmp = 1;
        for (int i = 0; i < n; i++){
//            cout << a[i] << ' ';
            flr[i].clear();
            while(flr[i].size() < a[i]){
                flr[i].eb(tmp++, 0);
            }
        }
        for (int i = 1; i < n; i++){
            int j = 0;
            for (auto [v, f] : flr[i]){
                while(j < flr[i - 1].size() && flr[i - 1][j].S == 2) j++;
                if (j < flr[i - 1].size()){
                    flr[i - 1][j].S++;
                    cout << flr[i - 1][j].F << ' ';
                }
            }
        }
        // contruct now
        cout << "\n";
    }else{
        cout << "NO\n";
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

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+




+====================== OUT ======================+




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/