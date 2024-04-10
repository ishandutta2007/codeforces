#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //for (int sn = 1; sn < 10000; sn++) {
  {
    string s;
    cin >> s;
    //s = to_string(sn);
    int n = s.size();
    int ans = 1e9;
    pair<int,int> path;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (i == j) continue;
	if (s[i] == '0' && s[j] == '0' ||
	    s[i] == '2' && s[j] == '5' ||
	    s[i] == '5' && s[j] == '0' ||
	    s[i] == '7' && s[j] == '5') {
	  int dist = abs(n-2-i)+abs(n-1-j);
	  if (j < i) {
	    dist = 1+(abs(n-2-j)+abs(n-1-i));
	  }
	  if (i == 0 || j == 0) {
	    int zeros = 0;
	    while (zeros+1 < max(i,j) && s[zeros+1] == '0') zeros++, dist++;
	  }
	  if (dist <= ans) {
	    ans = dist;
	    path = {i, j};
	  }
	}
      }
    }
    if (ans == 1e9) ans = -1;
    /*if (ans != -1 && (path.first == 0 || path.second == 0) && count(s.begin(), s.end(), '0')) {
      cout << sn << ' ' << ans << endl;
      }*/
    cout << ans << endl;
  }
}