/*
 /+===================================================+\
//+---------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\\+---------------------------------------------------+//
 \+===================================================+/
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
// I/O
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;
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

void FAST_IO(string filein, string fileout);
void Hollwo_Pelw();

signed main(){
    FAST_IO("input.inp", "output.out");
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n;
pii chk[(int) 5e6 + 5];
pii a[MAXN];
void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].F; a[i].S = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++){
        if (chk[a[i + 1].F - a[i].F] == pii(0, 0))
            chk[a[i + 1].F - a[i].F] = {a[i + 1].S, a[i].S};
        else{
            if (chk[a[i + 1].F - a[i].F].F == a[i].S) continue;
            if (chk[a[i + 1].F - a[i].F].F == a[i + 1].S) continue;
            if (chk[a[i + 1].F - a[i].F].S == a[i].S) continue;
            if (chk[a[i + 1].F - a[i].F].S == a[i + 1].S) continue;
            cout << "YES\n";
            cout << a[i + 1].S << ' ' << chk[a[i + 1].F - a[i].F].S << ' ' << chk[a[i + 1].F - a[i].F].F << ' ' << a[i].S;
            return ;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (chk[a[j].F - a[i].F] == pii(0, 0))
                chk[a[j].F - a[i].F] = {a[j].S, a[i].S};
            else {
                if (chk[a[j].F - a[i].F].F == a[i].S) continue;
                if (chk[a[j].F - a[i].F].F == a[j].S) continue;
                if (chk[a[j].F - a[i].F].S == a[i].S) continue;
                if (chk[a[j].F - a[i].F].S == a[j].S) continue;
                cout << "YES\n";
                cout << a[j].S << ' ' << chk[a[j].F - a[i].F].S << ' ' << chk[a[j].F - a[i].F].F << ' ' << a[i].S;
                return ;
            }
        }
    }
    cout << "NO\n";
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