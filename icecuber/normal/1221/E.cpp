#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    int fairs = 0, first = -1;
    int lastx = -1;
    for (int i = 0; i <= s.size(); i++) {
      if (i == s.size() || s[i] == 'X') {
	int l = i-1-lastx;
	lastx = i;
	if (l >= b) {
	  if (l < a) goto fail;
	  if (l >= 2*b) {
	    if (first != -1) goto fail;
	    first = l;
	  } else fairs++;
	}
      }
    }
    //cout << s << ' ' << fairs << ' ' << first << endl;
    if (first == -1) {
      if (fairs%2) goto win;
      else goto fail;
    }
    for (int i = 0; i+a <= first; i++) {
      int x = i, y = first-i-a;
      if (x >= 2*b || y >= 2*b || x >= b && x < a || y >= b && y < a) continue;
      if ((fairs+(x >= a)+(y >= a))%2 == 0) goto win;
    }
    goto fail;
  win:
    cout << "YES\n";
    continue;
  fail:
    cout << "NO\n";
  }
}