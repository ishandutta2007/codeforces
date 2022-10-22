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
const int MAXN = 1e5 + 5 , MAXM = 1e6 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

const int Bsize = 405, Bnum = 255;
int n, m, a[MAXN];

int point_cnt[MAXN];
int point_res;

int tl[Bnum], tr[Bnum];
int block_cnt[Bnum][MAXN];
int block_res[Bnum];

int res[MAXN];

void add_point(int v, int t){
    point_res -= point_cnt[v] > 0;
    point_cnt[v] += t;
    point_res += point_cnt[v] > 0;
}

void add_block(int b, int v, int t){
    block_res[b] -= block_cnt[b][v] > 0;
    block_cnt[b][v] += t;
    block_res[b] += block_cnt[b][v] > 0;
}

void solve_small(int k){
    int l = 0;
    for (int r = 1; r <= n; r++){
        add_point(a[r], 1);
        add_point(a[r + 1], 1);
        if (point_res > k || r == n){
            // cout << l << ' ' << r << ' ' << point_res << endl;
            for (int j = r; j > l; j--) 
                add_point(a[j], -1);
            l = r, res[k] ++;
        }
        add_point(a[r + 1], -1);
    }
}

void solve_large(int k){
    for (int b = 1; b < Bnum; b++){
        while(tr[b] < n){
            add_block(b, a[tr[b] + 1], 1);
            if (block_res[b] <= k){
                tr[b] ++;
            }else{
                add_block(b, a[tr[b] + 1], -1);
                break;
            }
        }
        if (tr[b] == n){
            res[k] = b;
            return; 
        }else{
            while(tl[b + 1] <= min(n, tr[b])){
                add_block(b + 1, a[tl[b + 1]], -1);
                tl[b + 1] ++;
            }
            while(tr[b + 1] <= min(tl[b + 1] - 1, n)){
                tr[b + 1] ++;
                add_block(b + 1, a[tr[b + 1]], 1);
            }
        }
    }
}

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if (i <= Bsize)
            solve_small(i);
        else
            solve_large(i);
        cout << res[i] << ' ';
    }
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