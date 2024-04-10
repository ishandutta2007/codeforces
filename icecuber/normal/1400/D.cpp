#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> A(n+1);
    vector<vector<ll>> B(n+1, vector<ll>(n+1));
    vector<vector<ll>> C(n+1, vector<ll>(n+1));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for (int j = 0; j <= n; j++)
	ans += C[j][a];
      for (int j = 0; j <= n; j++)
	C[a][j] += B[a][j];
      for (int j = 0; j <= n; j++)
	B[j][a] += A[j];
      A[a]++;
    }
    cout << ans << endl;
  }
}