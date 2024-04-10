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

int a[maxn];
bool is_rec[maxn];
int solo[maxn];
int pos[maxn], pr[maxn], sf[maxn];

int main() {
   // files1;
    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
        pos[a[i]] = i;
    }

    set<int> q;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            is_rec[i] = 1;
        } else {
            if (*(--q.end()) < a[i])
                is_rec[i] = 1;
        }

        // solo max > a[i]
        if (q.size() == 1) {
            if (*(--q.end()) > a[i]) {
                solo[pos[*(--q.end())]] += 1;
            }
        } else if (q.size() > 1) {
            if (*(--q.end()) > a[i] && *(--(--q.end())) < a[i]) {
                solo[pos[*(--q.end())]] += 1;   
            }
        }

        q.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
        pr[i] = (int)is_rec[i] + (i > 0 ? pr[i - 1] : 0);
    for (int i = n - 1; i >= 0; i--)
        sf[i] = (int)is_rec[i] + (i != n - 1 ? sf[i + 1] : 0);

    pair<int, int> ans;
    ans.f = -inf;

    for (int i = 0; i < n; i++) {
        int p = (i > 0) ? pr[i - 1] : 0;
        int s = (i != n - 1) ? sf[i + 1] : 0;
        // cout << p + s + solo[i] << endl;
        ans = max(ans, mp(p + s + solo[i], -a[i]));
    }
    cout << -ans.s;
    return 0;
}