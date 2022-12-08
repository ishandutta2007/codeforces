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

int get(vector<int> &f) {
  int t1 = 0;
  int t2 = 0;
  for(int i = 0; i < 10; i++) {
    if(i % 2 == 0)
      t1 += f[i];
    else
      t2 += f[i];

    int lst1 = (10 - i - 1) / 2;
    int lst2 = (10 - i) / 2;
    if(t1 > t2 + lst2 || t2 > t1 + lst1)
      return i + 1;
  }
  return 10;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int ans = 10;
    int n = s.size();
    vector<int> f1(n);
    vector<int> f2(n);
    for(int i = 0; i < n; i++) {
      if(s[i] == '?') {
        if(i % 2 == 0) {
          f1[i] = 1;
          f2[i] = 0;
        } else {
          f1[i] = 0;
          f2[i] = 1;
        }
      } else {
        f1[i] = f2[i] = (s[i] - '0');
      }
    }
    cout << min(get(f1), get(f2)) << endl;
  }
}