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
const int MAXN = 2e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n;
/*
(x^3 + x^2, x^2 + 1);
(x^2 - 1, x);
(x, 1);
(1, 0);

n + 1 -> (ax + b, a);
n -> (a, b);
*/
vector<int> a, b, tmp;

bool chk(vector<int> x, vector<int> y){
    reverse(all(x));
    reverse(all(y));
    for (int i = 0; i < y.size(); i++){
        if (abs(x[i] + y[i]) > 1) return false;
    }
    return true;
}

void g(vector<int> &x, vector<int> y){
    x.pb(0);
    if (chk(x, y)){
        for (int i = y.size() - 1; i >= 0; i--){
            x[i + x.size() - y.size()] += y[i];
        }
    }else{
        for (int i = y.size() - 1; i >= 0; i--){
            x[i + x.size() - y.size()] -= y[i];
        }
    }
}

void build(int n){
    if (n == 0){
        a.assign(1, 1);
        b.assign(1, 0);
        return;
    }
    build(n - 1);
    tmp = a;
    g(a, b);
    b = tmp;
}

void Solve () {
    cin >> n; build(n); 
    reverse(all(a)); reverse(all(b));
    cout << a.size() - 1 << endl << a << endl;
    cout << b.size() - 1 << endl << b << endl;
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




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/