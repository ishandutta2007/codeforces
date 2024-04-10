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

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
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
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
// #define int long long

inline void sadd(int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

inline void smul(int &a, int b){
    a = 1ll * a * b % mod;
}

int dp1[55][2525], n, T;
int dp23[55][55][2525];
int tot[5], cnt[5]; 


int way[55][55][55][5];
int ways[55][55][55], fact[55];

void __calc_way__(){
    way[0][0][0][0] = 1;
    for (int i = 0; i <= cnt[1]; i++)
        for (int j = 0; j <= cnt[2]; j++)
            for (int k = 0; k <= cnt[3]; k++){
                
                for (int l = 0; l <= 3; l++){
                    if (!way[i][j][k][l]) continue ;

                    for (int c = 1; c <= 3; c++) if (c != l){
                        int ni = i + (c == 1), nj = j + (c == 2), nk = k + (c == 3);
                        if (ni > cnt[1] || nj > cnt[2] || nk > cnt[3]) continue;

                        sadd(way[ni][nj][nk][c], way[i][j][k][l]);
                    }
                }

                if (i) sadd(ways[i][j][k], way[i][j][k][1]);
                if (j) sadd(ways[i][j][k], way[i][j][k][2]);
                if (k) sadd(ways[i][j][k], way[i][j][k][3]);   
            }
    fact[0] = 1;
    for (int i = 1; i <= n; i++){
        fact[i] = mul(i, fact[i - 1]);
    }
}

void Hollwo_Pelw() {
    cin >> n >> T;
    dp1[0][0] = dp23[0][0][0] = 1;
    for (int i = 1, d, t; i <= n; i++){
        cin >> d >> t;
        if (t == 1){
            for (int i = cnt[1]; i >= 0; i--){
                for (int j = 0; j <= tot[1]; j++){
                    sadd(dp1[i + 1][j + d], dp1[i][j]);
                }
            }
        }else{
            for (int i = cnt[2]; i >= 0; i--){
                for (int j = cnt[3]; j >= 0; j--){
                    for (int k = 0; k <= tot[2] + tot[3]; k++){
                        sadd(dp23[i + (t == 2)][j + (t == 3)][k + d], dp23[i][j][k]);
                    }
                }
            }
        }
        cnt[t] ++;
        tot[t] += d;
    }
    __calc_way__();
    
    int res = 0;
    for (int i = 0; i <= cnt[1]; i++){
        for (int d1 = 0; d1 <= min(T, tot[1]); d1++){
            for (int j = 0; j <= cnt[2]; j++){
                for (int k = 0; k <= cnt[3]; k++){
                    int way_suf = mul(dp1[i][d1], dp23[j][k][T - d1]);
                    if (!way_suf) continue ;
                    // cout << i << " -> " << d1 << ", (" << j << ", " << k << ") -> " << T - d1 << "\n";
                    // cout << way_suf << "\n";
                    smul(way_suf, fact[i]), smul(way_suf, fact[j]), smul(way_suf, fact[k]);
                    // cout << way_suf << "\n";
                    sadd(res, mul(way_suf, ways[i][j][k]));
                }
            }
        }
    }
    cout << res;
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