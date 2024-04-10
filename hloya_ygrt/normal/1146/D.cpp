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
  
 int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)3e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

#define abs(x) (x)>0?(x):-(x)

const int buben = 5e6;
ll dd[buben];

ll prog(ll x) {
    return x * (x + 1) / 2;
}

ll solve(ll m, ll a, ll b) {
    for (int i = 0; i < buben; i++)
        dd[i] = inf;

    dd[0] = 0;
    queue<int> q;
    q.push(0);

    ll g = gcd(a, b);
    a /= g;
    b /= g;


    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x + a < buben) {
            if (dd[x + a] > max(dd[x], x + a)) {
                dd[x + a] = max(dd[x], x + a);
                q.push(x + a);
            }
        }
        if (x - b >= 0) {
            if (dd[x - b] > dd[x]) {
                dd[x - b] = dd[x];
                q.push(x - b);
            }
        }
    }

    // for (int i = 0; i < buben; i++)
    //     assert(dd[i] != inf);

    // for (int i = buben - 100; i < 30; i++)
    //     cout << dd[i] << ' ';
    // cout << endl;
    // // exit(0);

    // for (int i = 0; i < 30; i++)
    //     cout << dd[i] * g << ' ';
    // cout << endl;
    // exit(0);
    // for (int i = 0; i < buben; i++)
    //     dd[i] *= g;

    ll sum = m + 1;

    for (int i = 1; i < buben; i++) {
        if (1ll * i * g > m) {
            return sum;
        }
        if (i > (a + b) * 3) {
            // cout << "kek";
            // cout << sum << endl;

            ll x = m / g - (i - 1);
            // cout << x << endl;
            ll y = prog(m / g) - prog(i - 1);
            sum += 1ll * (m + 1) * x - y * g;
            return sum;
        }
        sum += max(m - dd[i] * g + 1, 0ll);
    }    

    assert(0);
}

int solvefull(int x, int a, int b) {
    set<int> q;
    q.insert(0);
    while (1) {
        int s = q.size();
        for (auto e : q) {
            if (e + a <= x)
                q.insert(e + a);
            if (e - b >= 0)
                q.insert(e - b);
        }
        int t = q.size();
        if (s == t)
            break;
    }
    return q.size();
}

int brute(int m, int a, int b) {
    ll ans = 0;
    for (int i = 0; i <= m; i++)
        ans += solvefull(i, a, b);
    return ans;
}

int main() {
    // files1;
    fast_io;

//     cout << solve(22, 3, 3) << ' ' << brute(22, 3, 3);
//     return 0;
// // 
    // for (int iter = 0; iter < 100000; iter++) {
    //     int m = rand() % (int)30 + 1, a = rand() % (int)30 + 1, b = rand() % (int)30 + 1;
    //     if (solve(m, a, b) != brute(m, a, b)) {
    //         cerr << m << ' ' << a << ' ' << b << endl;
    //         exit(228);
    //     }
    // }
    // return 0;
    int m, a, b;
    cin >> m >> a >> b;

    cout << solve(m, a, b);
}