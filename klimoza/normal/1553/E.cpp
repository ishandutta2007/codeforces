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

const int N = 3e5 + 2;
int p[N], sz[N];

void build(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}

int get(int k) {
  if(k == p[k]) return k;
  return p[k] = get(p[k]);
}

void merge(int a, int b) {
  a = get(a); b = get(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}

int id(int i, int p, int n) {
  return (i - p + n) % n;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<int> cnt(n,0 );
    for(int i = 0; i < n; i++) {
      cin >> p[i]; p[i]--;
      cnt[id(i, p[i], n)]++;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
      if(cnt[i] < n - 2 * m) continue;
      build(n);
      for(int j = 0; j < n; j++)
        merge(p[j], (j - i + n) % n);
      vector<bool> used(n, false);
      int tot = 0;
      for(int j = 0; j < n; j++) {
        if (!used[get(j)]) {
          used[get(j)] = true;
          tot++;
        }
      }
      if(n - tot <= m)
        ans.push_back(i);
    }
    cout << ans.size() << " ";
    for(int i : ans)
      cout << i << " ";
    cout << endl;
  }
}