#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int isLess(int i, int j) {
  cout << "? " << i+1 << ' ' << j+1 << endl;
  char ans;
  cin >> ans;
  return ans == '<';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 0, b = 1;
    if (isLess(b, a)) swap(a,b);
    vector<int> left;
    for (int i = 2; i < n*2; i++) left.push_back(i);
    vector<int> done;
    while (left.size() > 1) {
      int c = left[0], d = left[1];
      if (isLess(d, c)) swap(c, d);
      if (isLess(a, c)) swap(a,c), swap(b,d);
      vector<int> new_left = {d};
      for (int i = 2; i < left.size(); i++) {
	if (isLess(c, left[i])) {
	  new_left.push_back(left[i]);
	} else {
	  for (int j : done)
	    isLess(j,left[i]);
	  done.push_back(left[i]);
	}
      }
      left = new_left;
      done.push_back(c);
    }
    cout << "!" << endl;
  }
}