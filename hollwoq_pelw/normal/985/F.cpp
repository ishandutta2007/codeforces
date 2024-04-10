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
ostream& operator << (ostream& out, vector<T> v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U> v){
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
const int mod = allmod[1];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, m, a[MAXN];

const int H = 2;

struct hash_t {
    int val[H];
    hash_t () {}
    hash_t (int x) {
        for (int i = 0; i < H; i++)
            val[i] = x;
    }
    bool operator < (hash_t oth) {
        for (int i = 0; i < H; i++) 
            if (val[i] != oth.val[i]) 
                return val[i] < oth.val[i];
        return 0;
    }
    bool operator == (hash_t oth) {
        for (int i = 0; i < H; i++)
            if (val[i] != oth.val[i])
                return 0;
        return 1;
    }
    bool operator != (hash_t oth) {
        return !(*this == oth);
    }
    friend hash_t operator + (hash_t a, hash_t b) {
        hash_t res;
        for (int i = 0; i < H; i++)
            res.val[i] = (a.val[i] + b.val[i]) % allmod[i];
        return res;
    }
    friend hash_t operator - (hash_t a, hash_t b) {
        hash_t res;
        for (int i = 0; i < H; i++)
            res.val[i] = (a.val[i] - b.val[i] + allmod[i]) % allmod[i];
        return res;
    }
    friend hash_t operator * (hash_t a, hash_t b) {
        hash_t res;
        for (int i = 0; i < H; i++)
            res.val[i] = a.val[i] * b.val[i] % allmod[i];
        return res;
    }
    vector<int> to_prt() {
        vector<int> res(H);
        for (int i = 0; i < H; i++)
            res[i] = val[i];
        return res;
    }
} hsh[26][MAXN], pw[MAXN];

hash_t get_hsh(int c, int l, int r) {
    return hsh[c][r] - hsh[c][l - 1] * pw[r - l + 1];
}

void answer_query() {
    int x, y, len;
    cin >> x >> y >> len;
    vector<hash_t> X(26), Y(26);
    for (int i = 0; i < 26; i++){
        X[i] = get_hsh(i, x, x + len - 1);
        Y[i] = get_hsh(i, y, y + len - 1);
    }
    sort(all(X)), sort(all(Y));
    for (int i = 0; i < 26; i++){
        if (X[i] != Y[i])
            Ptest("NO");
    }
    Ptest("YES");
}

void Hollwo_Pelw() {
    string s;
    cin >> n >> m >> s; 
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a';
    }
    pw[0] = hash_t(1);
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 26; i++) {
            hsh[i][j] = hsh[i][j - 1] * hash_t(2) + hash_t(a[j] == i);
        }
        pw[j] = pw[j - 1] * hash_t(2);
    }
    while (m --) {
        answer_query();
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