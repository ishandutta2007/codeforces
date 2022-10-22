#include <bits/stdc++.h>
using namespace std;

int a[200000][2];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][0]--, a[i][1]--;
  }
  if (n == 3) {
    cout << "1 2 3" << endl;
    return 0;
  }
  int p = 0;
  do {
    cout << p+1 << ' ';
    for (int i = 0; i < 2; i++) {
      int q = a[p][i];
      if (a[p][!i] == a[q][0] || a[p][!i] == a[q][1]) {
	p = q;
	break;
      }
    }
  } while (p);
  cout << endl;
}