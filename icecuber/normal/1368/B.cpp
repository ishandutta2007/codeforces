#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s = "codeforces";
  ll n;
  cin >> n;
  int m = s.size();
  for (int base = 1;;base++) {
    vector<int> cnt(m, base);
    for (int i = 0; i < m; i++) {
      ll got = 1;
      for (int v : cnt) {
	got *= v;
      }
      if (got >= n) {
	for (int i = 0; i < m; i++)
	  for (int j = 0; j < cnt[i]; j++)
	    cout << s[i];
	cout << endl;
	return 0;
      }
      cnt[i] = base+1;
    }
  }
}