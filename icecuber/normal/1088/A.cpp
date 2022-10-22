#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  for (int a = 1; a <= x; a++)
    for (int b = 1; b <= x; b++)
      if (a%b==0 && a*b > x && a/b < x) {
	cout << a << ' ' << b << endl;
	return 0;
      }
  cout << -1 << endl;
}