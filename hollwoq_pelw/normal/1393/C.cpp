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
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
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
#define sz(a)               (int) a.size()
#define len(a)              a.length()
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
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 1e5 + 6, MAXM = 200010;
// code
#define int long long

int n, ans = 0;
int a[MAXN], cnt[MAXN];

bool check(int x) {
    for (int i = 1; i <= n; i ++) cnt[i] = 0;
    for (int i = 0; i < n; i ++) cnt[a[i]]++;

    set<pair<int, int>, greater<pair<int, int>>> ss; 
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] > 0) ss.insert({cnt[i], i});
    }
    vector<int> b;
    for (int i = 0; i < n; i ++) {
        if (i >= x && cnt[b[i - x]]) {
            ss.insert({cnt[b[i - x]], b[i - x]});
        }
        if (ss.empty()) return 0;
        b.push_back(ss.begin()->second);
        ss.erase(ss.begin());
        cnt[b.back()]--;
    }
    return 1;
}


void Solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l - 1 << endl;
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