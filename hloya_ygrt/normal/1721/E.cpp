#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

// hloya template v26

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
using namespace std;

bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>

#define files1 freopen("decomposable.in","r",stdin)
#define files2 freopen("decomposable.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "NO"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

mt19937_64 mt_rand(
        chrono::system_clock::now().time_since_epoch().count()
);

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';

    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }

    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 1e9 + 20;
const long double eps = 1e-12;
const ll llinf = 2e18 + 5;
const int maxn = 1e6 + 500;
const int mod = 258280327;

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int getpi(int i, const vector<int>& ps, const vector<int>& pt) {
    if (i < ps.size()) {
        return ps[i];
    }
    return pt[i - ps.size()];
}

char getst(int i, const string& s, const string& t) {
    if (i < s.size()) {
        return s[i];
    }
    return t[i - s.size()];
}

int main() {
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    fast_io;

    string s;
    cin >> s;
    auto p = prefix_function(s);

    vector<vector<int>> jcac(s.size(), vector<int>(26));
    for (int c = 0; c < 26; c++) {
        for (int i = 1; i < s.size(); i++) {
            int j = i;
            if (s[j] == char(c + 'a')) {
                jcac[i][c] = i;
            } else {
                j = p[j - 1];
                jcac[i][c] = jcac[j][c];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        string t;
        cin >> t;

        vector<int> pt(t.size());
        for (int i = s.size(); i < s.size() + t.size(); i++) {
            int j = getpi(i - 1, p, pt);
            while (j >= s.size() /* 0 */  && getst(i, s, t) != getst(j, s, t)) {
                j = getpi(j - 1, p, pt);
            }

            if (j > 0 && j < s.size()) {
                int idc = t[i - s.size()] - 'a';
                j = jcac[j][idc];
            }

            if (getst(i, s, t) == getst(j, s, t)) ++j;
            pt[i - s.size()] = j;

        }
        for (int x : pt) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    return 0;
}