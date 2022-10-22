/*
 /+===================================================+\
//+---------------------------------------------------+\
|.|\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\+---------------------------------------------------+//
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
void debug(){
    cout << endl;
}
template <typename H, typename... T>
void debug(H a, T... b){
    cout << a << ' ';
    debug(b...);
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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[0];
const int MAXN = 3e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
// #define int long long

#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr

int n, a[MAXN], lg[MAXN];
int st[MAXN][25];

void build(){
    lg[0] = -1;
    for (int i = 1; i <= n; i++){
        st[i][0] = a[i];
        lg[i] = lg[i / 2] + 1;
    }
    for (int j = 1; j < 25; j++){
        for (int i = 1; i + (1 << j) <= n + 1; i++){
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = lg[r - l + 1];
    return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

set<int> s[MAXN];

void Hollwo_Pelw(){
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    build();
    int mx = 0;
    for (int i = 1; i <= n; i++){
        int ll = 1, lr = i, l = i;
        while(ll <= lr){
            int lm = (ll + lr) >> 1;
            if (query(lm, i) == a[i]){
                l = lm;
                lr = lm - 1;
            }else{
                ll = lm + 1;
            }
        }
        int rl = i, rr = n, r = i;
        while(rl <= rr){
            int rm = (rl + rr) >> 1;
            if (query(i, rm) == a[i]){
                r = rm;
                rl = rm + 1;
            }else{
                rr = rm - 1;
            }
        }
        if (mx < r - l){
            mx = r - l;
            s[mx].insert(l);
        }else if (mx == r - l){
            s[mx].insert(l);
        }
        // cout << l << ' ' << r << endl;
    }
    cout << s[mx].size() << ' ' << mx << "\n";
    for (auto v : s[mx]) cout << v << ' ';
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