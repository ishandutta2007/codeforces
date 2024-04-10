#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int h[20];
int mem[5001][501];
int f(int x, int c, int k) {
  if (x < 0) return -1e9;
  if (c == 0) return 0;
  int&memo = mem[x][c];
  if (!memo) {
    int ans = 0;
    for (int t = 0; t <= k; t++) {
      ans = max(ans, h[t]+f(x-t, c-1, k));
    }
    memo = ans+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> c;
  for (int i = 0; i < n*k; i++) {
    int v;
    cin >> v;
    c[v]++;
  }
  map<int,int> fav;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    fav[v]++;
  }
  for (int i = 1; i <= k; i++) cin >> h[i];

  int ans = 0;
  for (auto [v,cnt] : fav) {
    ans += f(min(c[v], cnt*k), cnt, k);
  }
  cout << ans << endl;
}