#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> a;
  vector<int> a0(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a0[i] = v;
    a.emplace_back(-v, i);
  }
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  vector<vector<pair<int,int>>> query(n+1);
  for (int i = 0; i < q; i++) {
    int k, p;
    cin >> k >> p;
    p--;
    query[k].emplace_back(p, i);
  }
  vector<int> ans(q);
  int B = 1;
  while (B < n) B *= 2;
  vector<int> tree(B*2);

  for (int i = 0; i < n; i++) {
    {
      int j = a[i].second+B;
      tree[j] += 1;
      for (j /= 2; j; j /= 2) {
	tree[j] = tree[j*2]+tree[j*2+1];
      }
    }
    for (auto q : query[i+1]) {
      int v = q.first;
      int j = 1;
      while (j < B) {
	if (tree[j*2] <= v) {
	  v -= tree[j*2];
	  j = j*2+1;
	} else {
	  j *= 2;
	}
      }
      ans[q.second] = a0[j-B];
    }
  }
  for (int i : ans) cout << i << ' ';
  cout << endl;
}