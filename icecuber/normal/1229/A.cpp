#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int out[7000];
ll a[7000], b[7000];
int oks[7000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    ans += b[i];
  }
  queue<int> leave;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && (a[i]&a[j]) == a[i]) oks[i]++;
    }
    if (!oks[i]) leave.push(i);
  }
  while (leave.size()) {
    int i = leave.front();
    leave.pop();
    ans -= b[i];
    out[i] = 1;
    for (int j = 0; j < n; j++) {
      if (out[j]) continue;
      if ((a[j]&a[i]) == a[j]) {
	if (!--oks[j]) {
	  leave.push(j);
	}
      }
    }
  }
  cout << ans << endl;
}