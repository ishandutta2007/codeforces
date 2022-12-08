#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

int snd(int x, int y, int a, int b);
int fst(int x, int y, int a, int b) {
  if(x == 0 && a == 0) return 0;
  if(y) {
    int t = snd(b, a + 1, y - 1, x);
    if(t == -1)
      return -1;
    else
      return 1 + t;
  } else {
    return -1;
  }
}

int snd(int x, int y, int a, int b) {
  if(x == 0 && a == 0) return 0;
  if(x) {
    int t = fst(b + 1, a, y, x - 1);
    if(t == -1)
      return -1;
    else
      return 1 + t;
  } else
    return -1;
}

void solve() {
   int tp; cin >> tp;
   while(tp--) {
     int n; cin >> n;
     string s; cin >> s;
     string t; cin >> t;
     int x = 0, y = 0, a = 0, b = 0;
     for(int i = 0; i < n; i++) {
       if(s[i] == '1' && t[i] == '0')
         x++;
       else if(s[i] == '1' && t[i] == '1')
         y++;
       else if(s[i] == '0' && t[i] == '1')
         a++;
       else
         b++;
     }
     int a1 = fst(x, y, a, b);
     int a2 = snd(x, y, a, b);
     if(a1 == -1) cout << a2 << endl;
     else if(a2 == -1) cout << a1 << endl;
     else cout << min(a1, a2) << endl;
   }
}