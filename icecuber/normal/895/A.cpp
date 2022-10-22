#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int acc[400];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    acc[i+1] = a+acc[i];
  }
  int ans = 360;
  for (int l = 0; l < n; l++) {
    for (int r = 0; r < n; r++) {
      int a = acc[r]-acc[l];
      if (r <= l) a += 360;
      ans = min(ans, abs(a-(360-a)));
    }
  }
  cout << ans << endl;
}