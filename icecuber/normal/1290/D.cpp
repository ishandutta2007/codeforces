#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void reset() {
  cout << "R" << endl;
}

int ans;
void go(set<int>&s) {
  vector<int> bads;
  for (int i : s) {
    cout << "? " << i+1 << endl;
    char seen;
    cin >> seen;
    if (seen == 'Y') {
      bads.push_back(i);
    }
  }
  ans -= bads.size();
  for (int i : bads) s.erase(i);
}

int main() {
  if (0) {
    int n = 2;//024;
    int need = 0;
    for (int i = 1; i < n; i++) {
      vector<int> done(n);
      for (int j = 0; j < n; j++) {
	if (!done[j]) {
	  for (int k = j; !done[k]++; k = (k+i)%n) {
	    need++;
	  }
	  need+=2;
	}
      }
    }
    cout << need << ' ' << 3*n*n/2. << endl;
    return 0;
  }

  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  ans = n;
  vector<set<int>> group(n/k);
  for (int i = 0; i < n/k; i++) {
    for (int j = 0; j < k; j++)
      group[i].insert(i*k+j);
  }

  int r = n/k;
  for (int i = (r!=1); i < r; i++) {
    vector<int> done(r);
    for (int j = 0; j < r; j++) {
      reset();
      if (!done[j]) {
	int dones = 0;
	for (int p = j; !done[p]++; p = (p+i)%r) {
	  dones += group[p].size();
	  go(group[p]);
	}
	if (r > 1) {
	  reset();
	  go(group[(j-i+r)%r]);
	  go(group[j]);
	}
      }
    }
  }
  cout << "! " << ans << endl;
}