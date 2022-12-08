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
//const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt[10];
    fill(cnt, cnt + 10, 0);
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i] - '0']++;
    }
    if (cnt[1]) {
      cout << "1\n1\n";
      continue;
    }
    if (cnt[4]) {
      cout << "1\n4\n";
      continue;
    }
    if (cnt[6]) {
      cout << "1\n6\n";
      continue;
    }
    if (cnt[8]) {
      cout << "1\n8\n";
      continue;
    }
    if (cnt[9]) {
      cout << "1\n9\n";
      continue;
    }
    if (cnt[0]) {
      cout << "2\n" << a[0] << "0\n";
      continue;
    }
    bool fl = false;
    for (int i = 2; i < 10; i++) {
      if (cnt[i] >= 2) {
        cout << "2\n" << (char) (i + '0') << (char) (i + '0') << "\n";
        fl = true;
        break;
      }
    }
    if (fl) continue;
    if (cnt[2] && a[0] != '2') {
      cout << "2\n" << a[0] << "2\n";
      continue;
    }
    if (cnt[5] && a[0] != '5') {
      cout << "2\n" << a[0] << "5\n";
      continue;
    }
    if ((a[0] == '2' || a[0] == '5') && cnt[7]) {
      cout << "2\n" << a[0] << "7\n";
      continue;
    }
    cout << n << endl;
    for (char c : a)
      cout << c;
    cout << endl;
  }
}