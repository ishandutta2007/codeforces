#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[12][2000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    priority_queue<tuple<int,int,int>> pq;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
	cin >> A[i][j];
	pq.push({A[i][j], i, j});
      }
    set<int> done;
    vector<vector<int>> cols;
    while (cols.size() < n && pq.size()) {
      auto t = pq.top();
      pq.pop();
      int v, i, j;
      tie(v,i,j) = t;
      if (done.count(j)) continue;
      done.insert(j);
      {
	vector<int> v(1<<n,0);
	for (int m = 0; m < 1<<n; m++) {
	  for (int r = 0; r < n; r++) {
	    int s = 0;
	    for (int i = 0; i < n; i++) {
	      int k = (i+r)%n;
	      if (m>>k&1) s += A[i][j];
	    }
	    v[m] = max(v[m],s);
	  }
	}
	cols.push_back(v);
      }
    }

    vector<int> dp(1<<n);
    for (int j = 0; j < cols.size(); j++) {
      vector<int> ndp = dp;
      for (int b = 0; b < 1<<n; b++) {
	for (int a = b; a; a = (a-1)&b) {
	  ndp[b] = max(ndp[b], dp[b^a]+cols[j][a]);
	}
      }
      swap(dp,ndp);
    }
    cout << dp[(1<<n)-1] << endl;
  }
}