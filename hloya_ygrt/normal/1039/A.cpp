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

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
const int maxn = (int)5e5 + 12, base = 1e9 + 7;
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

ll a[maxn], x[maxn], b[maxn], pref[maxn], add[maxn];

int main() {
    // files1;
    fast_io;

    int n;
    ll t;

    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[i] < i)
            return cout << "No", 0;
    }

    for (int i = 1; i <= n; i ++) {
        add[i + 1] += 1;
        add[x[i] + 1] -= 1;
    }

    int bb = 0;
    for (int i = 1; i <= n; i ++) {
        b[i] = a[i] + t;
        bb += add[i];
        if (bb)
            b[i - 1] = max(b[i - 1], a[i] + t);
    }

    for (int i = 2; i <= n; i++) {
        b[i] = max(b[i - 1] + 1, b[i]);
    }

    pref[1] = 0;
    for (int i = 2; i <= n; i++) {
        ll cur = 0;
        if (a[i] + t <= b[i - 1])
            cur = 1;
        pref[i] = pref[i - 1] + cur;
    }

    for (int i = 1; i <= n; i++) {
        if (x[i] != n) {
            int s = pref[x[i] + 1] - pref[i];
            int s2 = pref[x[i]] - pref[i];

            if (s == x[i] - i + 1 || s2 != x[i] - i) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
}