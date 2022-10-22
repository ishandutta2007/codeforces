#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  int gfree = 0, rfree = 0;
  vector<int> grundy(10,0);
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    int g = -1, r = -1, dash = -1;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'G') g = j;
      else if (s[j] == 'R') r = j;
      else dash = j;
    }
    if (g != -1 && r != -1) {
      int d = abs(g-r)-1;
      for (int i = 0; i < 10; i++)
	grundy[i] += d>>i&1;
    }
    else if (g != -1 && dash != -1) gfree = 1;
    else if (r != -1 && dash != -1) rfree = 1;
  }
  if (gfree && rfree) cout << "Draw" << endl;
  else if (gfree) cout << "First" << endl;
  else if (rfree) cout << "Second" << endl;
  else {
    int lose = 1;
    for (int v : grundy)
      if (v%(k+1))
	lose = 0;
    cout << (lose ? "Second" : "First") << endl;
  }
}