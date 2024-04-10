#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[150000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  int last = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    for (int d : {-1,0,1}) {
      if (a[i]+d > last) {
	last = a[i]+d;
	ans++;
	break;
      }
    }
  }
  cout << ans << endl;
}