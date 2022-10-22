#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[1<<12];
int d[1<<12];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, n, m;
  cin >> w >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  while (m--) {
    copy_n(c, 1<<w, d);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int j = 0; j < w; j++) {
      if (s[j] == 'A') {
	for (int i = 0; i < 1<<w; i++) if (i>>j&1) {
	    swap(d[i], d[i^1<<j]);
	    d[i^1<<j] += d[i];
	}
      } else if (s[j] == 'O') {
	for (int i = 0; i < 1<<w; i++) if (i>>j&1) {
	    d[i] = 0;
	  }
      } else if (s[j] == 'X') {
	;
      } else if (s[j] == 'a') {
	for (int i = 0; i < 1<<w; i++) if (i>>j&1) {
	    d[i^1<<j] = 0;
	}
      } else if (s[j] == 'o') {
	for (int i = 0; i < 1<<w; i++) if (i>>j&1) {
	    swap(d[i], d[i^1<<j]);
	    d[i] += d[i^1<<j];
	}
      } else if (s[j] == 'x') {
	for (int i = 0; i < 1<<w; i++) if (i>>j&1) {
	    swap(d[i], d[i^1<<j]);
	}
      } else {
	assert(0);
      }
    }
    int ans = 0;
    for (int i = 0; i < 1<<w; i++) {
      ans += c[i]*d[i];
    }
    cout << ans << endl;
  }
}