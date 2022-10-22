/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#pragma Ofast
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
#define debug(x)            cout << #x << " = " << x << endl;
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
const int MAXN = 1e6 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, k;
string a[MAXN];
bool dict[26], del[26];
bool prv[26][26], nxt[26][26];

void build(string s, string t){
    int i = 0;
    while(i < s.length() && i < t.length() && s[i] == t[i]) i++;
    if (i < s.length() && i < t.length()){
        // s[i] < t[i] now
        nxt[t[i] - 'a'][s[i] - 'a'] = true;
    }
    if (i == t.length() && i < s.length()){
        cout << "IMPOSSIBLE";
        exit(0);
    }
}

void Solve () {
    cin >> n >> k;
    for (int i = 0, p; i < n; i++){
        cin >> p;
        for (int j = 0; j < k; j++){
            cin >> a[p * k + j];
        }
    }
    for (int i = 0; i < n * k; i++){
        for (auto c : a[i]) dict[c - 'a'] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) cnt += dict[i];
    for (int i = 1; i < n * k; i++){
        build(a[i - 1], a[i]);
    }
    // check if this directed graph no cycle (topo sort then AC)
    string res = "";
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if (dict[j] && !del[j]){
                bool f = true;
                for (int k = 0; k < 26; k++){
                    if (nxt[k][j]){
                        f = false;
                    }
                }
                if (f){
                    del[j] = true;
                    res += (char) (j + 'a');
                    for (int k = 0; k < 26; k++){
                        nxt[j][k] = false;
                    }
                }
            }
        }
    }
    reverse(all(res));
    if (res.length() != cnt)
        cout << "IMPOSSIBLE";
    else
        cout << res;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
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