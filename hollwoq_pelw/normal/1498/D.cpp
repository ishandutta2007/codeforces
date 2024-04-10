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
    #else
        FAST_IO(".inp", ".out");
    #endif
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

bool cur[MAXN], prv[MAXN], vis[MAXN];
int res[MAXN], nxt[MAXN], n, m,  cnt;

void dosweep(int p, int y, int id){
    cnt = 0;
    queue<int> dq;
    while (p <= m && !vis[p]){
        vis[p] = 1;
        cnt += cur[p];
        dq.push(p);
        if (dq.size() > y + 1){
            cnt -= cur[dq.front()];
            dq.pop();
        }
        prv[p] = cnt > 0;
        if (prv[p] && res[p] == -1)
            res[p] = id;
        p = nxt[p];
    }
}

int gceil(int x, int y){
    return (x + y - 1) / y;
}

void Hollwo_Pelw() {
    cin >> n >> m;
    cur[0] = 1;
    for (int i = 1; i <= m; i++) res[i] = -1;
    for (int i = 1, t, x, y; i <= n; i++){
        cin >> t >> x >> y;
        for (int j = 0; j <= m; j++){
            vis[j] = 0;
            if (t == 1)
                nxt[j] = j + gceil(x, 1e5);
            else
                nxt[j] = gceil(j * x, 1e5);
            // cout << nxt[j] << ' ';
        }
        // cout << endl;
        for (int j = 0; j <= m; j++){
            if (vis[j]) continue;
            dosweep(j, y, i);
        }
        for (int j = 0; j <= m; j++){
            cur[j] = prv[j];
        }
    }
    for (int i = 1; i <= m; i++){
        cout << res[i] << ' ';
    }
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