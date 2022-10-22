#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, ya;
  cin >> na >> ya;
  vector<int> a(na);
  for (int&v : a) cin >> v;
  int nb, yb;
  cin >> nb >> yb;
  vector<int> b(nb);
  for (int&v : b) cin >> v;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  for (int l = 0; l <= 30; l++) {
    int mask = (1ll<<l+1)-1;
    vector<int> va, vb;
    for (int v : a)
      va.push_back(v&mask);
    for (int v : b)
      vb.push_back(v&mask);
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int off = l == 30 ? 0 : 1<<l;
    for (int k = 0; k < 2; k++) {
      int last = -1;
      for (int v : (k ? vb : va)) {
	if (v == last) continue;
	int v1 = v+off*( k)&mask;
	int v2 = v+off*(!k)&mask;
	int pas =
	  upper_bound(va.begin(), va.end(), v1)-
	  lower_bound(va.begin(), va.end(), v1);
	int pbs =
	  upper_bound(vb.begin(), vb.end(), v2)-
	  lower_bound(vb.begin(), vb.end(), v2);
	ans = max(ans, pas+pbs);
	last = v;
      }
    }
    /*
    map<int,int> ma, mb;
    for (int v : a)
      ma[v&mask]++;
    for (int v : b)
      mb[v&mask]++;
    int off = l == 30 ? 0 : 1<<l;
    for (auto&pa : ma) {
      auto it = mb.find(pa.first+off&mask);
      ans = max(ans, pa.second+(it == mb.end() ? 0 : it->second));
    }
    for (auto&pb : mb) {
      auto it = ma.find(pb.first+off&mask);
      ans = max(ans, pb.second+(it == ma.end() ? 0 : it->second));
      }*/
  }
  cout << ans << endl;
}