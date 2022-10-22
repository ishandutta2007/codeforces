#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ok = 1;
    string part(k, '?');
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
	if (part[i%k] == '?') part[i%k] = s[i];
	else ok &= (part[i%k] == s[i]);
      }
    }
    int zeros= count(part.begin(), part.end(), '0');
    int ones = count(part.begin(), part.end(), '1');
    //cout << zeros << ' ' << ones << ' ' << k << endl;
    if (zeros <= k/2 && ones <= k/2 && ok)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}