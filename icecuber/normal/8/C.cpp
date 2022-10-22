#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[24], y[24];
int dp[1<<24];
int para[1<<24], parb[1<<24];
void self_min(int a, int b, int pa, int pb) {
  if (b < dp[a]) {
    dp[a] = b;
    para[a] = pa;
    parb[a] = pb;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int xs, ys;
  cin >> xs >> ys;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  fill_n(dp+1, (1<<n)-1, 1e9);
  for (int mask = 0; mask < (1<<n)-1; mask++) {
    int a = 0;
    while (mask>>a&1) a++;
    int mask_ = mask|1<<a;
    self_min(mask_, dp[mask]+((xs-x[a])*(xs-x[a])+(ys-y[a])*(ys-y[a]))*2, a, a);

    for (int b = 0; b < n; b++) {
      if (mask_>>b&1) continue;
      self_min(mask_|1<<b, dp[mask]+
	       (xs-x[a])*(xs-x[a])+(ys-y[a])*(ys-y[a])+
	       (x[b]-x[a])*(x[b]-x[a])+(y[b]-y[a])*(y[b]-y[a])+
	       (xs-x[b])*(xs-x[b])+(ys-y[b])*(ys-y[b]), a, b);
    }
  }
  int m = (1<<n)-1;
  cout << dp[m] << endl;
  vector<int> path = {0};
  while (m) {
    int a = para[m];
    int b = parb[m];
    path.push_back(a+1), m ^= 1<<a;
    if (a != b)
      path.push_back(b+1), m ^= 1<<b;
    path.push_back(0);
  }
  reverse(path.begin(), path.end());
  for (int i : path) cout << i << ' ';
  cout << endl;
}