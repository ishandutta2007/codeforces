#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> r(n,n-1), l(n,0);
  for (int i = 0; i < n; i++) {
    int acc = 0;
    for (int j = i; j < n; j++) {
      acc += (s[j] != ')')*2-1;
      if (acc < 0) {
	r[i] = j-1;
	break;
      }
    }
    acc = 0;
    for (int j = i; j >= 0; j--) {
      acc += (s[j] != '(')*2-1;
      if (acc < 0) {
	l[i] = j+1;
	break;
      }
    }
    //cout << l[i] << ' ' << r[i] << endl;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (j > i && (j-i)%2 == 1 && r[i] >= j && l[j] <= i) {
	ans++;
      }
    }
  cout << ans << endl;
}