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

const int N = 501;

char a[N][N];


void solve() {
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> a[i][j];
    int st = 0;
    if(n % 3 == 0)
      st = 1;
    for(int i = st; i < n; i += 3)
      for(int j = 0; j < m ;j++)
        a[i][j] = 'X';
    for(int i = st; i < n - 2; i += 3){
      bool fl = false;
      for(int j = 0; j < m; j++){
        if(a[i + 1][j] == 'X'){
          a[i + 2][j] = 'X';
          fl = true;
          break;
        }
        if(a[i + 2][j] == 'X'){
          a[i + 1][j] = 'X';
          fl = true;
          break;
        }
      }
      if(!fl){
        a[i + 1][0] = 'X';
        a[i + 2][0] = 'X';
      }
    }
    for(int i = 0; i < n ;i++){
      for(int j = 0; j < m ;j++)
        cout << a[i][j];
      cout << endl;
    }
  }
  return;
}