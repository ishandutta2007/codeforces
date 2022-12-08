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

void solve() {
  int n; cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++)
    cin >> p[i];
  vector<int> prv(n);
  vector<int> nxt(n);
  prv[0] = 0;
  for(int i = 1; i < n; i++){
    if(p[i] > p[i - 1])
      prv[i] = prv[i - 1];
    else
      prv[i] = i;
  }
  nxt[n - 1] = n - 1;
  for(int i = n - 2; i >= 0; i--){
    if(p[i] > p[i + 1])
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = i;
  }
  int m = -1, c = 0;
  int x = -1;
  for(int i = 0; i < n; i++){
    if(i - prv[i] > m) {
      m = i - prv[i];
      c = 1;
      x = i;
    }
    else if(i - prv[i] == m){
      c++;
    }

    if(nxt[i] - i > m){
      m = nxt[i] - i;
      c = 1;
      x = i;
    }
    else if(nxt[i] - i == m){
      c++;
    }
  }
  if(c >= 3 || (c == 2 && (x - prv[x] != nxt[x] - x)))
    cout << 0 << endl;
  else if(c == 2){
    if(m & 1)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return;
}