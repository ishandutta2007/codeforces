#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<200> s[200];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      s[i].reset();
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
	int a;
	cin >> a;
	a--;
	s[i][a] = 1;
      }
    }

    int any = 0;
    vector<int> ans(n);
    for (ans[0] = 0; ans[0] < n; ans[0]++) {
      vector<bitset<200>> mask(n);
      mask[0][ans[0]] = 1;
      vector<int> used(n-1);
      int ok = 1;
      for (int i = 1; i < n; i++) {
	int found = 0;
	for (int j = 0; j < n-1; j++) {
	  if(used[j]) continue;
	  int sz = s[j].count();
	  if (i+1 >= sz && (int)(s[j]&mask[i+1-sz]).count() == sz-1) {
	    ans[i] = (s[j]&~mask[i+1-sz])._Find_first();
	    for (int k = 0; k <= i; k++)
	      mask[k].set(ans[i]);
	    used[j] = 1;
	    found = 1;
	    break;
	  }
	}
	if (!found) {
	  ok = 0;
	  break;
	}
      }
      if (ok) {
	any = 1;
	for (int v : ans) cout << v+1 << ' ';
	cout << endl;
	break;
      }
    }
    assert(any);
  }
}