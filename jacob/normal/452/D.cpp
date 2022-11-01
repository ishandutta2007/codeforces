#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> pii;

set<pii> s[3];

int main() {
	int k, n[3], t[3];
	cin >> k;
	for (int i = 0; i < 3; ++i)
	  cin >> n[i];
	for (int i = 0; i < 3; ++i)
	  cin >> t[i];
	for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < n[i]; ++j) {
	    s[i].insert(pii(0, j));
	  }
	}
	while (k != 0) {
	  --k;
	  int mv = 0;
	  int ps = 0;
	  for (int i = 0; i < 3; ++i) {
	    mv = max(mv, s[i].begin()->first - ps);
	    ps += t[i];
	  }
	  ps = 0;
	  for (int i = 0; i < 3; ++i) {
	    pii v = *s[i].begin();
	    s[i].erase(v);
	    ps += t[i];
	    s[i].insert(pii(mv + ps, v.second));
	  }
	}
	cout << s[2].rbegin()->first << endl;
	return 0;
}