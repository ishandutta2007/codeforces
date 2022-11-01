// hloya template v25
  
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
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
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
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e5 + 12, base = 1e9 + 7;
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

int pr[maxn];

int main() {
    int n, c, d;
    // files1;
    read(n, c, d);

    int ans = 0;

    vector<pair<int, int> > a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        read(x, y);
        char c = endl;
        while (c == endl || c == ' ') c = getchar();
        if (c == 'C')
            a.pb(mp(y, x));
        else
            b.pb(mp(y, x));
    }
    sort(all(a));
    sort(all(b));

    int ans1 = 0;
    int fnd1 = 0, fnd2 = 0;

    for (auto e : a) {
        int cost = e.f, profit = e.s;
        if (cost <= c) {
            amax(fnd1, profit);
        }
    }

    for (auto e : b) {
        int cost = e.f, profit = e.s;
        if (cost <= d) {
            amax(fnd2, profit);
        }
    }

    if (fnd1 && fnd2)
        ans1 = fnd1 + fnd2;

    int ans2 = 0;
    for (int i = 0; i < a.size(); i++) {
        pr[i] = a[i].s;
        if (i)
            amax(pr[i], pr[i - 1]);
    }
    for (int i = 1; i < a.size(); i++) {
        int cost = a[i].f, profit = a[i].s;
        int have = c - cost;
        if (have <= 0)
            continue;
        int l = 0, r = i - 1;
        while (r - l > 0) {
            int m = (l + r + 1) >> 1;
            if (a[m].f > have)
                r = m - 1;
            else
                l = m;
        }
        if (a[l].f > have)
            continue;
        int profit2 = pr[l];
        amax(ans2, profit2 + profit);
    }

    int ans3 = 0;
    for (int i = 0; i < b.size(); i++) {
        pr[i] = b[i].s;
        if (i)
            amax(pr[i], pr[i - 1]);
    }
    for (int i = 1; i < b.size(); i++) {
        int cost = b[i].f, profit = b[i].s;
        int have = d - cost;
        if (have <= 0)
            continue;
        int l = 0, r = i - 1;
        while (r - l > 0) {
            int m = (l + r + 1) >> 1;
            if (b[m].f > have)
                r = m - 1;
            else
                l = m;
        }
        if (b[l].f > have)
            continue;
        int profit3 = pr[l];
        amax(ans3, profit3 + profit);
    }
    cout << max({ans1, ans2, ans3});
    return 0;
}