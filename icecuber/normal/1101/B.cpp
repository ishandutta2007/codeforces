#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int l = -1, r = -1;
  for (int i = 0; i < n; i++)
    if (l == -1 && s[i] == '[') l = i;
  for (int i = n-1; i >= 0; i--)
    if (r == -1 && s[i] == ']') r = i;
  if (l == -1 || r == -1) goto fail;
  {
    int pipes = 0, colon = 0, best = -1;
    for (int i = l+1; i < r; i++) {
      if (s[i] == ':') {
	if (colon)
	  best = max(best, pipes);
	if (!colon)
	  pipes = 0;
	colon = 1;
      } else if (s[i] == '|') pipes++;
    }
    if (best == -1) goto fail;
    cout << best+4 << endl;
    return 0;
  }
 fail:
  cout << -1 << endl;
}