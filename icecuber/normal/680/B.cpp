#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a;
  cin >> n >> a;
  a--;
  for (int i = 0; i < n; i++)
    cin >> t[i];
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (t[i]) {
      int j = a*2-i;
      if (j < 0 || j >= n || t[j]) ans++;
    }
  cout << ans << endl;
}