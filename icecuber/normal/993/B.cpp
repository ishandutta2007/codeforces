#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
int a[12][2], b[12][2];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb;
  for (int i = 0; i < na; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  for (int i = 0; i < nb; i++) {
    cin >> b[i][0] >> b[i][1];
  }

  set<int> possible, possible_a[12], possible_b[12];
  for (int i = 0; i < na; i++) {
    for (int j = 0; j < nb; j++) {
      for (int x = 0; x < 2; x++) {
	for (int y = 0; y < 2; y++) {
	  if (a[i][x] == b[j][y] && a[i][!x] != b[j][!y]) {
	    possible.insert(a[i][x]);
	    possible_a[i].insert(a[i][x]);
	    possible_b[j].insert(a[i][x]);
	    //cout << i << ' ' << j << ' ' << a[i][x] << endl;
	  }
	}
      }
    }
  }
  if (possible.size() == 1) {
    cout << *possible.begin() << endl;
    return 0;
  }
  int knows = 1;
  for (int i = 0; i < na; i++)
    if (possible_a[i].size() > 1) knows = 0;
  for (int i = 0; i < nb; i++)
    if (possible_b[i].size() > 1) knows = 0;
  cout << (knows ? 0 : -1) << endl;
}