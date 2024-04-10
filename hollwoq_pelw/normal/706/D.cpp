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
#define sz(a)               a.size()
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
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long
const int S = 32;

struct node {
    int cnt, child[2];
    node() {
        child[0] = child[1] = -1;
        cnt = 0;
    }
} trie[MAXN << 2];

int node_cnt = 0;

void push(int a, int v){
    int p = 0;
    for (int i = S; i >= 0; i--){
        int x = a >> i & 1;
        trie[p].cnt += v;
        if (trie[p].child[x] == -1){
            trie[p].child[x] = ++node_cnt;
        }
        p = trie[p].child[x];
    }
    trie[p].cnt += v;
}

void print(int p){
    if (p == -1) return ;
    cout << "Node " << p << " = " << trie[p].cnt << " : \n";
    cout << trie[p].child[0] << ' ' << trie[p].child[1] << "\n";
    for (int i = 0; i < 2; i++){
        print(trie[p].child[i]);
    }
}

void process(int a){
    int p = 0, ans = 0;
    for (int i = S; i >= 0; i--){
        int x = a >> i & 1;
        int zer = trie[p].child[x];
        int one = trie[p].child[x ^ 1];
        if (one != -1 && trie[one].cnt > 0){
            p = one;
            ans |= 1ll << i;
        }else{
            p = zer;
        }
    }
    cout << ans << "\n";
}

int q;
void Solve() {
    cin >> q;
    push(0, 1);
    for (int i = 0; i < q; i++){
        char c; int s;
        cin >> c >> s;
        if (c == '+')
            push(s, +1);
        if (c == '-')
            push(s, -1);
        if (c == '?')
            process(s);
    }
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


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/