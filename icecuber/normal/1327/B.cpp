#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> aleft, left;
    for (int i = 0; i < n; i++) left.insert(i);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      int found = -1;
      while (k--) {
	int g;
	cin >> g;
	g--;
	if (found == -1 && left.count(g)) {
	  found = g;
	}
      }
      if (found != -1)
	left.erase(found);
      else
	aleft.insert(i);
    }
    if (aleft.size() && left.size()) {
      cout << "IMPROVE" << endl;
      cout << *aleft.begin()+1 << ' ' << *left.begin()+1 << endl;
    } else
      cout << "OPTIMAL" << endl;
  }
}