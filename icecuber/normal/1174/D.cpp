#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x;
  cin >> n >> x;
  if (x >= 1<<n) {
    cout << (1<<n)-1 << endl;
    for (int i = 1; i < 1<<n; i++)
      cout << (i^i-1) << ' ';
    cout << endl;
  } else {
    cout << (1<<n-1)-1 << endl;
    int last = 0;
    for (int i = 1; i < 1<<n; i++) {
      if (i > (i^x) && i != x) {
	cout << (i^last) << ' ';
	last = i;
      }
    }
    cout << endl;
  }
}