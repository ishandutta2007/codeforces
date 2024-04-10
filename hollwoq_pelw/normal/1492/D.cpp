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
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int zer, one, k;
int a[MAXN], b[MAXN];

void Solve() {
    cin >> zer >> one >> k;
    int n = zer + one;
    if (k == 0){
        cout << "Yes" << endl;
        for (int i = 0; i < one; i++) cout << 1;
        for (int i = 0; i < zer; i++) cout << 0;
        cout << endl;
        for (int i = 0; i < one; i++) cout << 1;
        for (int i = 0; i < zer; i++) cout << 0;
        cout << endl;
        return ;
    }
    if (k >= n - 1){
        Ptest("No");
    }
    one --;
    a[0] = b[0] = 1;
    if (!one || !zer){
        Ptest("No");
    }
    one --;
    zer --;
    a[1] = 1;
    b[1] = 0;
    b[1 + k] = 1;
    a[1 + k] = 0;
    for (int i = 1; i < n; i++){
        if (i == 1 || i == 1 + k)
            continue;
        if (zer){
            zer --;
            a[i] = 0;
            b[i] = 0;
        }else{
            one --;
            a[i] = 1;
            b[i] = 1;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) cout << a[i];
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i];
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
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