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

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();
signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

bool intersect(int a, int b, int x, int y) {
  if(a > b) swap(a, b);
  if(x > y) swap(x, y);
  return (a <= x && x <= b && b <= y) || (x <= a && a <= y && y <= b);
}

void solve() {
    int t; cin >> t;
    while(t--) {
      int n, k; cin >> n >> k;
      vector<bool> used(2 * n);
      vector<pair<int, int>> kek;
      for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        kek.push_back(mp(a, b));
        used[a] = used[b] = true;
      }
      ll ans = 0;
      vector<int> mem;
      for(int i = 0; i < 2 * n; i++)
        if(!used[i])
          mem.push_back(i);
      for(int i = 0; i < (n - k); i++)
        kek.push_back(mp(mem[i], mem[i + n - k]));
      k = kek.size();
      for(int i = 0; i < k; i++) {
        for(int j = i + 1 ; j < k; j++) {
          if(intersect(kek[i].first,  kek[i].second, kek[j].first, kek[j].second))
            ans++;
        }
      }
      cout << ans << endl;
    }
}