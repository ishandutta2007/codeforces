#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int has[101];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    has[a] = 1;
  }
  int ans = sum;
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j <= i; j++) {
      if (!has[i] || !has[j]) continue;
      for (int x = 1; x <= i; x++) {
	if (i%x) continue;
	ans = min(ans, sum-i-j+i/x+j*x);
      }
    }
  }
  cout << ans << endl;
}