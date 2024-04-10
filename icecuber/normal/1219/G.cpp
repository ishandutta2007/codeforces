#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans = 0;
void solve(vector<vector<int>>&a, int w, int h, int do22) {
  vector<ll> row_sum(h,0);
  priority_queue<ll> pq;
  auto submit = [&](ll score = 0) {
    while (pq.size()) {
      score -= pq.top();
      pq.pop();
    }
    ans = max(ans, score);
  };

  // 4 + 0
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      row_sum[i] += a[i][j];
    }
    pq.push(-row_sum[i]);
    if (pq.size() > 4) pq.pop();
  }
  submit();

  // 3 + 1
  for (int k = 0; k < w; k++) {
    ll score = 0;
    for (int i = 0; i < h; i++) {
      score += a[i][k];

      ll row = row_sum[i]-a[i][k];
      pq.push(-row);
      if (pq.size() > 3) pq.pop();
    }
    submit(score);
  }

  if (do22) {
    // 2 + 2
    for (int k = 0; k < h; k++) {
      for (int l = 0; l < k; l++) {
	ll score = 0;
	for (int i = 0; i < h; i++) {
	  score += a[i][k]+a[i][l];
	  ll row = row_sum[i]-a[i][k]-a[i][l];
	  pq.push(-row);
	  if (pq.size() > 2) pq.pop();
	}
	submit(score);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(w, vector<int>(h));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      b[j][i] = a[i][j];
    }
  }
  solve(a, w, h, (h <= w));
  solve(b, h, w,!(h <= w));
  cout << ans << endl;
}