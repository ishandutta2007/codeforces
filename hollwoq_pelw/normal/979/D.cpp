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
const int MAXN = 1e5 + 1;
const int inf = 2e9;
const ll linf = 1e18;
// #define int long long

struct Node {
    int mn, c[2];
    Node () {
        mn = inf;
        c[0] = c[1] = -1;
    }
};

struct Trie {
    vector<Node> tr;
    Trie () { tr.eb(); }
    void add(int x){
        int p = 0;
        for (int i = 18; i >= 0; i--){
            tr[p].mn= min(tr[p].mn, x);
            int bt = x >> i & 1;
            if (tr[p].c[bt] == -1) {
                tr[p].c[bt] = tr.size();
                tr.eb();
            }
            p = tr[p].c[bt];
        }
        tr[p].mn= min(tr[p].mn, x);
    }
    
    int query(int x, int s){
        int p = 0, res = 0;
        if (tr[p].mn > s) 
            return -1;
        for (int i = 18; i >= 0; i--){
            int bt = x >> i & 1;
            int nxt = tr[p].c[bt ^ 1];
            if (nxt != -1 && tr[nxt].mn <= s){
                res |= (bt ^ 1) << i;
                p = nxt;
            }else {
                res |= bt << i;
                p = tr[p].c[bt];
            }
        }
        return res;
    }
} tr[MAXN];

vector<int> d[MAXN];
int chk[MAXN], q;

void Hollwo_Pelw(){
    for (int i = 1; i < MAXN; i++){
        for (int j = i; j < MAXN; j += i){
            d[j].eb(i);
        }
    }
    cin >> q;
    while (q--) {
        int t, x, k, s;
        cin >> t >> x;
        if (t == 1) {
            if (!chk[x]) {
                chk[x] = 1;
                for (auto v : d[x])
                    tr[v].add(x);
            }
        }else{
            cin >> k >> s;
            if (x % k)
                cout << "-1\n";
            else
                cout << tr[k].query(x, s - x) << "\n";
        }
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