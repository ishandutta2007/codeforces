#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  int mi = a[0], ma = a[n-1];
  for (int i = 0; i < n; i++) {
    mi = max(mi, a[i]-i);
  }
  vector<int> acc(n*2);
  for (int i = 0; i < n; i++) {
    acc[max(a[i]-mi,0)]++;
  }
  for (int i = 1; i < n*2; i++)
    acc[i] += acc[i-1];
  vector<int> g(ma-mi,0);
  auto add = [&](int m, int l, int v) {
    l += ((m-l)%p+p)%p;
    if (l < ma-mi)
      g[l] += v;
  };
  vector<int> f(ma-mi,1);
  for (int i = 0; i < n*2; i++) {
    int m = ((i-acc[i])%p+p)%p;
    add(m, max(0, i-(n-1)), 1);
    add(m, min(ma-mi, i+1),-1);

    /*for (int x = max(0,i-(n-1)); x < min(ma-mi, i+1); x++) {
      if (x%p == m)
	f[x] = 0;
	}*/
  }
  for (int i = p; i < ma-mi; i++)
    g[i] += g[i-p];

  vector<int> ans;
  for (int i = mi; i < ma; i++) {
    //assert(!g[i-mi] == f[i-mi]);
    if (!g[i-mi]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int v : ans) cout << v << ' ';
  cout << endl;
}