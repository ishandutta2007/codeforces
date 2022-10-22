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

int n, a[2020][2020];

// int solve_row(int l, int r, int d){
//     int ans = 0;
//     for (int b = l; b <= r; b++){
//         int bl = 1, br = n;
//         while(a[b][bl] != d && bl < n) bl ++;
//         while(a[b][br] != d && br > 1) br --;
//         if (bl > br) continue;
//         int h = max(b - l, r - b);
//         ans = max(ans, (br - bl) * max(n - b, b - 1));
//         ans = max(ans, max(br - 1, n - bl) * h);
//     }
//     return ans;
// }

// int solve_col(int l, int r, int d){
//     int ans = 0;
//     for (int b = l; b <= r; b++){
//         int bl = 1, br = n;
//         while(a[bl][b] != d && bl < n) bl ++;
//         while(a[br][b] != d && br > 1) br --;
//         if (bl > br) continue;
//         int h = max(b - l, r - b);
//         ans = max(ans, (br - bl) * max(n - b, b - 1));
//         ans = max(ans, max(br - 1, n - bl) * h);
//     }
//     return ans;
// }

int calc(int d){
    int cnt = 0;
    int rmn = n, rmx = 1, cmn = n, cmx = 1;
    vector<int> rn(n + 1, n + 1), rm(n + 1, 0);
    vector<int> cn(n + 1, n + 1), cm(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == d){
                rmn = min(rmn, i);
                rmx = max(rmx, i);
                cmn = min(cmn, j);
                cmx = max(cmx, j);
                rn[i] = min(rn[i], j);
                rm[i] = max(rm[i], j);
                cn[j] = min(cn[j], i);
                cm[j] = max(cm[j], i);
                cnt ++;
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << rn[i] << ' ' << rm[i] << endl;
    //     cout << cn[i] << ' ' << cm[i] << endl;
    // }
    if (cnt < 2) return 0;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int mh = max(i - 1, n - i);
        int rh = max(i - rmn, rmx - i);
        int ch = max(i - cmn, cmx - i);
        int br = max(rm[i] - 1, n - rn[i]);
        int bc = max(cm[i] - 1, n - cn[i]);
        // cout << "ds" << i << ' ' << mh << endl;
        // cout << rh << ' ' << ch << endl;
        // cout << br << ' ' << bc << endl;
        ans = max(ans, (rm[i] - rn[i]) * mh);
        ans = max(ans, (cm[i] - cn[i]) * mh);
        ans = max(ans, br * rh);
        ans = max(ans, bc * ch);
        // cout << "dsl " << i << endl;
        // cout << ans << endl;
    }
    return ans;
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int d = 0; d < 10; d++){
        cout << calc(d) << ' ';
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= n; j++){
        //         cout << (a[i][j] == d);
        //     }
        //     cout << endl;
        // }
    }
    cout << endl;
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


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/