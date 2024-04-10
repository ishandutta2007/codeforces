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
const int MAXN = 1e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

#define Mat vector<vector<int>>

Mat operator * (const Mat &a, const Mat &b){
    Mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b[0].size(); j++){
            for (int k = 0; k < a[0].size(); k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

int n, k;

Mat binpow(Mat a, int x){
    Mat r(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        r[i][i] = 1;
    }
    while(x){
        if (x & 1) r = r * a; 
        x >>= 1;   a = a * a;
    }
    return r;
}

void Solve(){
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Mat a(n, vector<int>(n)), b(1, vector<int>(n, 1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = __builtin_popcountll(arr[i] ^ arr[j]) % 3 == 0;
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }
    b = b * binpow(a, k - 1);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = (ans + b[0][i]) % mod;
    }
    cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
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