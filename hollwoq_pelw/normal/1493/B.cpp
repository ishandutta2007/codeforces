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
#define debug(x)            cout << #x << " : " << endl << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
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
const int MAXN = 100 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

int hh, mm, h, m;

pii nt(int a, int b){
    b ++;
    if (b % m == 0) b = 0, a ++;
    if (a % h == 0) a = 0;
    return {a, b};
}

int mr(int x){
    if (x == 0 || x == 8 || x == 1) return x;
    if (x == 2 || x == 5) return 7 - x;
    return -1;
}

int mir(int l){
    int x = mr(l / 10);
    int y = mr(l % 10);
    if (x == -1 || y == -1)
        return -1;
    return y * 10 + x;
}

bool check(){
    int a = mir(mm), b = mir(hh);
    if (a == -1 || b == -1)
        return 0;
    return 0 <= a && a < h && 0 <= b && b < m;
}

void print(int a, int b){
    if (a < 10) cout << 0;
    cout << a << ":";
    if (b < 10) cout << 0;
    cout << b << endl;
}

void Solve() {
    // for (int i = 0; i < 99; i++){
    //     cout << mir(i) << endl;
    // }
    cin >> h >> m;
    string s;
    cin >> s;
    hh = (s[0] - '0') * 10 + s[1] - '0';
    mm = (s[3] - '0') * 10 + s[4] - '0';
    while (true) {
        if (check()) {
            print(hh, mm);
            return ;
        }
        auto nxt = nt(hh, mm);
        if (nxt == pii(0, 0)){
            print(0, 0);
            return ;
        }
        hh = nxt.F;
        mm = nxt.S;
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