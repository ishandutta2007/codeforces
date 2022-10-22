#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int x = 18; x >= 0; x--) {
    vector<int> base;
    vector<int> v, vi;
    for (int i = 0; i < n; i++) {
      int r = s[i];
      if (r>>x) continue;
      for (int j = 0; j < v.size(); j++) {
	if (r>>vi[j]&1)
	  r ^= v[j];
      }
      if (!r) continue;
      base.push_back(s[i]);
      int j = 0;
      while ((r>>j&1)==0) j++;
      for (int&i : v)
	if (i>>j&1) i ^= r;
      vi.push_back(j);
      v.push_back(r);
    }
    if (v.size() == x) {
      cout << x << endl;
      for (int i = 0; i < 1<<x; i++) {
	int r = 0;
	for (int j = 0; j < x; j++)
	  if ((i>>j^i>>j+1)&1)
	    r ^= base[j];
	cout << r << ' ';
      }
      cout << endl;
      return 0;
    }
  }
}