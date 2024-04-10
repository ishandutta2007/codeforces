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

bool isp(int n){
    if (n == 2 || n == 3) return true;
    for (int i = 5; i * i <= n; i += 6){
        if (n % (i + 2) == 0 || n % i == 0)
            return false;
    }
    return true;
}

vector<int> d, pr;

void factorize(int n){
    d.clear();
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            d.pb(i);
            if (i * i != n){
                d.pb(n / i);
            }
        }
    }
    d.pb(n);
    sort(all(d));
}

void getprime(int n){
    pr.clear();
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            pr.pb(i);
            while(n % i == 0) n /= i;
        }
    }
    if (n > 1) pr.pb(n);
}

void Solve () {
    int n; cin >> n;
    factorize(n);
    if (d.size() == 3 && isp(d[0]) && isp(d[1])){
        cout << d << endl << 1 << endl;
        return ;
    }
    map<int, bool> used;
    getprime(n);
    vector<int> cn(pr.size());
    for (int i = 0; i < pr.size(); ++i) {
        int p = pr[i], q = pr[(i + 1) % pr.size()];
        for (auto j : d) {
            if (!used[j] && j % p == 0 && j % q == 0) {
                used[j] = true; 
                cn[i] = j;
                break;
            }
        }
    }
    int i = 0;
    for (auto p : pr) {
        used[p] = true;
        cout << p << ' ';
        for (auto j : d) {
            if (!used[j] && j % p == 0) {
                used[j] = true;
                cout << j << ' ';
            }
        }
        if (pr.size() > 1) {
            cout << cn[i++] << ' ';
        }
    }
    cout << endl << 0 << endl;
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