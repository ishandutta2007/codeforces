#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.push_back(v&(1<<15)-1);
    b.push_back(v>>15);
  }
  vector<pair<vector<int>, int>> pa, pb;
  for (int j : {0,1}) {
    for (int x = 0; x < 1<<15; x++) {
      vector<int> h;
      int first = 0;
      for (int i = 0; i < n; i++) {
	int v = __builtin_popcount((j ? b : a)[i]^x);
	if (!i) first = v;
	h.push_back(v-first);
	if (j) h.back() *= -1;
      }
      (j ? pb : pa).push_back({h, x});
    }
  }
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  int j = 0;
  for (int i = 0; i < 1<<15; i++) {
    while (j < 1<<15 && pb[j].first < pa[i].first) j++;
    if (j < 1<<15 && pb[j].first == pa[i].first) {
      cout << (pb[j].second<<15 | pa[i].second) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}