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
const int mod = 998244353, mod1 = 1e9 + 7;
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int n, a[26];

int dp1[404][2][2];
int tr1[404][2][2];

void calc_one(){
    dp1[0][0][0] = 25 * 25;
    dp1[1][1][0] = 25;
    dp1[1][0][1] = 25;
    dp1[2][1][1] = 1;

    for (int st = 2; st < n; st++){
        for (int i = 0; i <= n; i ++){
            for (int s1 = 0; s1 < 2; s1++){
                for (int s2 = 0; s2 < 2; s2++){
                    tr1[i][s1][s2] = 0;
                }
            }
        }

        for (int i = 0; i <= n; i++){
            for (int s1 = 0; s1 < 2; s1++){
                for (int s2 = 0; s2 < 2; s2++){
                    for (int s3 = 0; s3 < 2; s3++){
                        if (!dp1[i][s1][s2]) continue;
                        int tmp = 0;
                        if (s3 == 1){
                            if (!s1)
                                tmp = 1;
                        }else{
                            if (!s1)
                                tmp = 24;
                            else
                                tmp = 25;
                        }
                        (tr1[i + s3][s2][s3] += tmp * dp1[i][s1][s2]) %= mod;
                    }
                }
            }
        }

        for (int i = 0; i <= n; i ++){
            for (int s1 = 0; s1 < 2; s1++){
                for (int s2 = 0; s2 < 2; s2++){
                    dp1[i][s1][s2] = tr1[i][s1][s2];
                }
            }
        }
    }
}

int dp2[404][404][3][3];
int tr2[404][404][3][3];

void calc_two(){
    dp2[0][0][0][0] = 24 * 24;
    dp2[1][0][0][1] = 24;
    dp2[0][1][0][2] = 24;
    dp2[1][0][1][0] = 24;
    dp2[0][1][2][0] = 24;
    dp2[1][1][1][2] = 1;
    dp2[1][1][2][1] = 1;
    dp2[2][0][1][1] = 1;
    dp2[0][2][2][2] = 1;

    for (int st = 2; st < n; st++){
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                for (int s1 = 0; s1 < 3; s1++){
                    for (int s2 = 0; s2 < 3; s2++){
                        tr2[i][j][s1][s2] = 0;
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                for (int s1 = 0; s1 < 3; s1++){
                    for (int s2 = 0; s2 < 3; s2++){
                        for (int s3 = 0; s3 < 3; s3++){
                            if (!dp2[i][j][s1][s2]) continue;
                            int tmp = 0;
                            if (s3 == 0){
                                if (s1 == 0)
                                    tmp = 23;
                                else
                                    tmp = 24;
                            }else{
                                if (s1 != s3)
                                    tmp = 1;
                            }
                            (tr2[i + (s3 == 1)][j + (s3 == 2)][s2][s3] += tmp * dp2[i][j][s1][s2]) %= mod;
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                for (int s1 = 0; s1 < 3; s1++){
                    for (int s2 = 0; s2 < 3; s2++){
                        dp2[i][j][s1][s2] = tr2[i][j][s1][s2];
                    }
                }
            }
        }
    }
}

void Solve() {
    cin >> n;
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    int ans = 26 * 26;
    for (int i = 2; i < n; i++)
        ans = ans * 25 % mod;
    calc_one();
    calc_two();
    for (int c1 = 0; c1 < 26; c1++){
        for (int i = a[c1] + 1; i <= n; i++){
            for (int s1 = 0; s1 < 2; s1++){
                for (int s2 = 0; s2 < 2; s2++){
                    ans = (ans + mod - dp1[i][s1][s2]) % mod;
                }
            }
        }
    }
//    cout << ans << endl;
    for (int c1 = 0; c1 < 26; c1++){
        for (int c2 = c1 + 1; c2 < 26; c2++){
            for (int i = a[c1] + 1; i <= n; i++){
                for (int j = a[c2] + 1; j <= n; j++){
                    for (int s1 = 0; s1 < 3; s1++){
                        for (int s2 = 0; s2 < 3; s2++){
                            ans = (ans + dp2[i][j][s1][s2]) % mod;
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*
./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+
446667918
712289856

+====================== OUT ======================+
446667918
287489790

\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/