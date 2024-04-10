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


void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

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

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 1e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, p[MAXN];
int la[MAXN], ra[MAXN];
int lb[MAXN], rb[MAXN];
int pf[MAXN], sf[MAXN];

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++){
        if (i != 1 && p[i] > p[i - 1])
            la[i] = la[i - 1];
        else 
            la[i] = i;
        if (i != 1 && p[i] < p[i - 1])
            lb[i] = lb[i - 1];
        else 
            lb[i] = i;
    }
    for (int i = n; i >= 1; i--){
        if (i != n && p[i] > p[i + 1])
            ra[i] = ra[i + 1];
        else 
            ra[i] = i;
        if (i != n && p[i] < p[i + 1])
            rb[i] = rb[i + 1];
        else 
            rb[i] = i;
    }
    for (int i = 1; i <= n; i++){
        pf[i] = max({pf[i - 1], i - la[i], i - lb[i]});
    }
    for (int i = n; i >= 1; i--){
        sf[i] = max({sf[i + 1], ra[i] - i, rb[i] - i});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int ll = la[i], rr = ra[i];
        if (ll == i || rr == i) continue;
        int len = max(i - ll, rr - i);
        // cout << len << endl;
        if (len <= max(pf[ll - 1], sf[rr + 1])) continue;
        if (max(i - ll - 1, rr - i) <= ll - lb[ll]) continue;
        if (max(i - ll, rr - i - 1) <= rb[rr] - rr) continue;
        // cout << i << ' ' << i - ll << ' ' << rr - i << endl;
        if (len % 2 != 0) continue;
        int lenl = i - ll;
        if (lenl % 2 == 0) lenl --;
        // cout << lenl << ' ';
        if (lenl >= rr - i) continue;
        int lenr = rr - i;
        if (lenr % 2 == 0) lenr --;
        // cout << lenr << ' ';
        if (lenr >= i - ll) continue;
        ans ++;
        // if (len % 2 == 0) cout << "lol " << i << endl;
    }
    cout << ans;
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