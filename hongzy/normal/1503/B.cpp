#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 1e4 + 10;
const int mod = 1e9 + 7;

int c[2], sz[2];
int len[2];
pii s[2][N];
int main() {
  ucin();
  int n; cin >> n;
  rep(i, 1, n) rep(j, 1, n) {
    s[i + j & 1][++ len[i + j & 1]] = pii(i, j);
  }
  //c[0] -> 1 c[1] -> 2
  rep(i, 1, n * n) {
    int a; cin >> a;
    if(a != 1 && len[0]) {
      cout << "1 " << s[0][len[0]].fs << ' ' << s[0][len[0]].sc << endl;
      len[0] --;
    } else if(a != 2 && len[1]) {
      cout << "2 " << s[1][len[1]].fs << ' ' << s[1][len[1]].sc << endl;
      len[1] --;
    } else {
      if(a == 1) { //0
        cout << "3 " << s[0][len[0]].fs << ' ' << s[0][len[0]].sc << endl;
        len[0] --;
      } else {
        cout << "3 " << s[1][len[1]].fs << ' ' << s[1][len[1]].sc << endl;
        len[1] --;
      }
    }
  }
  return 0;
}