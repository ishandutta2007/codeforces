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
typedef double ld;

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
  freopen("/Users/klimoza/CLionProjects/Test/test.in", "r", stdin);
  freopen("/Users/klimoza/CLionProjects/Test/test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> cur;
    a.push_back(0);
    int ans = 0;
    int xx = 0;
    int yy = n;
    int cur_x = 0;
    for(int x : a) {
      if(!x) {
        if(!cur.empty()) {
          int cnt_2 = 0;
          int cnt_m = 0;
          for(int y : cur) {
            if(y < 0) cnt_m++;
            if(abs(y) == 2) cnt_2++;
          }
//          cout << xx << " " << cnt_2 << " " << cnt_m << endl;
          if(cnt_m % 2 == 0) {
            if(ans < cnt_2) {
              ans = cnt_2;
              xx = cur_x;
              yy = n - xx - cur.size();
            }
          } else {
            int cnt_2l = 0, cnt_2r = 0;
            int cnt_ml = 0, cnt_mr = 0;
            while(cur[cnt_ml] > 0) {
              if(abs(cur[cnt_ml]) == 2)
                cnt_2l++;
              cnt_ml++;
            }
            if(abs(cur[cnt_ml]) == 2)
              cnt_2l++;
            cnt_ml += 1;
            while(cur[cur.size() - 1 - cnt_mr] > 0) {
              if(abs(cur[cur.size() - 1 - cnt_mr]) == 2)
                cnt_2r++;
              cnt_mr++;
            }
            if(abs(cur[cur.size() - 1 - cnt_mr]) == 2)
              cnt_2r++;
            cnt_mr += 1;
            if(cnt_2l > cnt_2r) {
              if(ans < cnt_2 - cnt_2r) {
                ans = cnt_2 - cnt_2r;
                xx = cur_x;
                yy = n - xx - (cur.size() - cnt_mr);
              }
            } else {
              if(ans < cnt_2 - cnt_2l) {
                ans = cnt_2 - cnt_2l;
                xx = cur_x + cnt_ml;
                yy = n - cur_x - cur.size();
              }
            }
          }
        }
        cur_x += cur.size() + 1;
        cur.clear();
      } else
        cur.push_back(x);
    }
    cout << xx << " " << yy << endl;
  }
}