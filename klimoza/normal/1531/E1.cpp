//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
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

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

const int N = 100;
const int K = 16;

vector<int> ans[N][N][K + 1];
string s;

vector<int> get(int l, int r, int k) {
  if(!ans[l][r][k].empty()) return ans[l][r][k];
  if(r - l + 1 == 1) {
    if(k != 2)
      ans[l][r][k] = {-1};
    else if(s[l] == '0')
      ans[l][r][k] = {1, 2};
    else
      ans[l][r][k] = {2, 1};
    return ans[l][r][k];
  }
  if(r - l + 1 == 2) {
    if(k != 3)
      ans[l][r][k] = {-1};
    else if(s[l] == '0' && s[r] == '0')
      ans[l][r][k] = {1, 2, 3};
    else if(s[l] == '1' && s[r] == '0')
      ans[l][r][k] = {1, 3, 2};
    else
      ans[l][r][k] = {-1};
    return ans[l][r][k];
  }
  if(r - l + 1 == 3) {
    if(k != 3)
      ans[l][r][k] = {-1};
    else if(s[l] == '0' && s[l + 1] == '1' && s[l + 2] == '0')
      ans[l][r][k] = {2, 1, 3};
    else if(s[l] == '1' && s[l + 1] == '1' && s[l + 2] == '0')
      ans[l][r][k] = {2, 3, 1};
    else if(s[l] == '0' && s[l + 1] == '1' && s[l + 2] == '1')
      ans[l][r][k] = {3, 1, 2};
    else if(s[l] == '1' && s[l + 1] == '1' && s[l + 2] == '1')
      ans[l][r][k] = {3, 2, 1};
    else
      ans[l][r][k] = {-1};
    return ans[l][r][k];
  }
  int m1 = k / 2;
  int m2 = (k + 1) / 2;
  for(int i = l; i < r; i++) {
    vector<int> p1 = get(l, i, m1);
    if(p1 == vector<int>(1, -1)) continue;
    for(int j = i + 1; j < r; j++) {
      vector<int> p2 = get(i + 1, j, m2);
      if(p2 == vector<int>(1, -1)) continue;
      vector<int> c1, c2;
      int cur = 1;
      for(int h = j + 1; h <= r; h++) {
        if(s[h] == '0')
          c1.push_back(cur++);
        else
          c2.push_back(cur++);
      }
      if(s[r] == '0')
        c2.push_back(cur++);
      else
        c1.push_back(cur++);
      if(c1.size() > m1 || c2.size() > m2) continue;
      if(c1.size() < m1 && c2.size() < m2) continue;
      if(c1.size() < m1 && s[r] == '0') continue;
      if(c2.size() < m2 && s[r] == '1') continue;
      while(c1.size() < m1)
        c1.push_back(cur++);
      while(c2.size() < m2)
        c2.push_back(cur++);
      vector<int> c;
      for(int &i : p1) {
        i = c1[i - 1];
        c.push_back(i);
      }
      for(int &i : p2) {
        i = c2[i - 1];
        c.push_back(i);
      }
      ans[l][r][k] = c;
      return c;
    }
  }
  ans[l][r][k] = vector<int>(1, -1);
  return ans[l][r][k];
}

vector<int> smart() {
  int n = s.size();
  for(int k = 1; k <= K; k++) {
    vector<int> ans = get(0, n - 1, k);
    if(ans != vector<int>(1, -1)) {
      return ans;
    }
  }
  return vector<int>(1, -1);
}

void solve() {
  cin >> s;
  vector<int> ans = smart();
  cout << ans.size() << endl;
  for(int i : ans)
    cout << i << " ";
  return;
}