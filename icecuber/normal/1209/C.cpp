#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int found = 0;
    for (int a = 0; a < 10; a++) {
      vector<int> path(n,1);
      int last = a;
      for (int i = 0; i < n; i++) {
	int c = s[i]-'0';
	if (c >= last) {
	  path[i] = 2;
	  last = c;
	}
      }
      int ok = 1;
      last = 0;
      for (int i = 0; i < n; i++) {
	if (path[i] == 2) continue;
	int c = s[i]-'0';
	if (c < last) {
	  ok = 0;
	  break;
	}
	last = c;
      }
      if (last > a) ok = 0;
      if (ok) {
	for (int i : path)
	  cout << i;
	cout << endl;
	found = 1;
	break;
      }
    }
    if (!found) {
      cout << '-' << endl;
    }
  }
}