#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 4000;
ll v[nax], d[nax], p[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> d[i] >> p[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (p[i] >= 0) {
      ans.push_back(i);
      vector<int> criers;
      for (int j = i+1; j < n && v[i]; j++) {
	if (p[j] >= 0) {
	  p[j] -= v[i];
	  if (p[j] < 0)
	    criers.push_back(j);
	  v[i]--;
	}
      }
      for (int it = 0; it < criers.size(); it++) {
	int i = criers[it];
	for (int j = i+1; j < n; j++) {
	  if (p[j] >= 0) {
	    p[j] -= d[i];
	    if (p[j] < 0)
	      criers.push_back(j);
	  }
	}
      }
    }
    /*for (int j = i+1; j < n; j++)
      cout << p[j] << ' ';
      cout << endl;*/
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i+1 << ' ';
  cout << endl;
}