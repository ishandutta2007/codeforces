// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
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
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e5 + 450, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

#define next asflkasjlf

vector<int> a;
bool brute(int pos, int ready) {
    int n = a.size();
    if (pos == n) {
        if (ready != n / 2)
            return 0;
        return !brute(0, 0);
    }
    bool ok = 0;
    for (int x = 1; x <= a[pos] && !ok; x++) {
        a[pos] -= x;
        ok |= brute(pos + 1, ready + 1);
        a[pos] += x;
    }
    if (!ok)
        ok |= brute(pos + 1, ready);
    return ok;
}

bool mda(vector<int> a) {
    ::a = a;
    return brute(0, 0);
}

bool slv(vector<int> a) {
    map<int, int> cnt;
    for (int i : a)
        cnt[i]++;
    int mn = inf;
    for (auto e : a)
        upmin(mn, e);
    int n = a.size();
    for (auto e : cnt)
        if (e.s > n / 2 && e.f == mn) {
            return 0;
        }
    return 1;
}

int main() {
    srand(time(0));
    int n, m;
    // files1;
    fast_io;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <n; i++)
        cin >> a[i];
    cout << (slv(a) ? "Alice" : "Bob");
    return 0;

    for (int iter = 0; iter < 100000; iter++) {
        int n = (rand() % 2 + 1) * 2;
        vector<int> a;
        for (int i = 0; i < n; i++)
            a.pb(rand() % 4 + 1);
        if (mda(a) != slv(a)) {
            for (auto e : a)
                cout << e << ' ';
            exit(228);
        }
    }

    // vector<int> a = {2,2,2,1};
    // cout << mda(a) << ' ' << slv(a);
    return 0;
}