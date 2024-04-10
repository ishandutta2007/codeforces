#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <list>

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
const int maxn = (int)1e6 + 12;//, base = 1e9 + 7;
const ll llinf = 1e18 + 5;
const double PI = acos(-1.0);
 
const int mod= 998244353;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}  

struct Line {
    long long b;
    long long k;
    int id;

    Line() {}
    Line(long long a, long long b, int id) : k(a), b(b), id(id) {}
};

int timer;

struct CHT_MAX {
  inline long double eval(const Line& a, long double q) {
      return a.k * q + a.b;
  }

  inline long double inter(const Line& a, const Line& b) {
    return 1.L * (a.b - b.b) / (a.k - b.k);
  }

  inline bool bad(const Line& a, const Line& b, const Line& c) {
      return (a.k - c.k) * (a.b - b.b) >= (a.b - c.b) * (a.k - b.k);
  }

  vector<Line> ch;
  vector<pair<int, Line> > changes;

  void add_line(Line a) {
      ++timer;
      changes.push_back(make_pair(timer, a));
      ch.push_back(a);
      while ((int)ch.size() > 2 && bad(ch[(int)ch.size() - 2], ch[(int)ch.size() - 3], ch.back())) {
          Line J = ch.back();
          changes.push_back(make_pair(-timer, ch.back()));
          ch.pop_back();
          changes.push_back(make_pair(-timer, ch.back()));
          ch.pop_back();
          changes.push_back(make_pair(timer, J));
          ch.push_back(J);
      }
  }

  pair<long double, int> find(long double x) {
      int l = 0, r = ch.size() - 1;
      for (int iter = 0; l < r && ch.size() > 1; ++iter) {
          int m = (l + r) / 2;
          if (eval(ch[m], x) >= eval(ch[m + 1], x)) {
              l = m + 1;
          } else {
              r = m;
          }
      }
      return make_pair(eval(ch[r], x), ch[r].id);
  }

  pair<long double, int> find2(long long k, long long b) {
    // if (ch.size() == 1) {
    //     return make_pair(inter(Line(k, b), ch[0]), ch[0].second);
    // }
    int l = 0, r = ch.size() - 1;
    auto lnm = Line(k, b, -1);
    // cout << bad(ch[0], lnm, ch[1]);
    // exit(0);
    while (r - l > 0) {
        int m = (l + r) >> 1;
        if (bad(ch[m], ch[m + 1], lnm)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    // cout << l << endl;
    // exit(0);
    // cout << inter(ch[1], lnm) << endl;
    // exit(0);
    return make_pair(inter(lnm, ch[l]), ch[l].id);
  }

  void pop_last() {
    while (changes.size() && abs(changes.back().first) == timer) {
      Line t = changes.back().second;
      int timer = changes.back().first;
      if (timer < 0) {
        ch.push_back(t);
      } else {
        ch.pop_back();
      }
      changes.pop_back();
    }
    timer--;
  }
} mx;

int a[maxn];
long long sum[maxn];
double ans[maxn];

int main() {
    // files1;
    fast_io;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        mx.add_line(Line(i, sum[i], i));
    }

    // for (auto c : mx.ch) {
    //     cout << c.k << ' ' << -1 << ' ' << c.b << endl;
    // }

    for (int i = 1; i <= n;) {
        // int mda = mx.find2(i + 1, sum[i - 1]);
        // long double l = 0, r = a[i - 1];
        // for (int iter = 0; iter < 50; iter++) {
        //     long double md = (l + r) / 2.L;
        //     if (mx.find(-md).first < 1.L*sum[i-1]-1.L*i*md+md) {
        //         r = md;
        //     } else {
        //         l = md;
        //     }
        // }
        // cout << 
        // return 0;
        auto [x, kek] = mx.find2(i - 1, sum[i - 1]);
        // return 0;

        // long double x = l;
        while (i <= kek) {
            ans[i] = x;
            i++;
            mx.pop_last();
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(20) << ans[i] << "\n";
    }
    return 0;
}