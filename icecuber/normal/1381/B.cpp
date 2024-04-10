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
    vector<int> a(n*2);
    int ma = 0;
    vector<int> b;
    for (int&v : a) {
      cin >> v;
      if (v > ma) {
	b.push_back(0);
	ma = v;
      }
      b.back()++;
    }
    //for (int l : b) cout << l << ' ';
    //cout << endl;
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int l : b) {
      for (int i = n; i >= l; i--) {
	dp[i] |= dp[i-l];
      }
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
  }
}