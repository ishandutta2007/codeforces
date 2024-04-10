#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
int pref_minx[nax], pref_maxx[nax], pref_miny[nax], pref_maxy[nax];
int pref_x[nax], pref_y[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') x--;
      else if (s[i] == 'D') x++;
      else if (s[i] == 'W') y++;
      else y--;

      pref_x[i+1] = x;
      pref_y[i+1] = y;
      pref_minx[i+1] = min(pref_minx[i], x);
      pref_maxx[i+1] = max(pref_maxx[i], x);
      pref_miny[i+1] = min(pref_miny[i], y);
      pref_maxy[i+1] = max(pref_maxy[i], y);
    }
    ll ans = (ll)(pref_maxx[n]-pref_minx[n]+1)*(pref_maxy[n]-pref_miny[n]+1);
    int maxx = x, minx = x, maxy = y, miny = y;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == 'D') x--;
      else if (s[i] == 'A') x++;
      else if (s[i] == 'S') y++;
      else y--;
      maxx = max(maxx, x);
      maxy = max(maxy, y);
      minx = min(minx, x);
      miny = min(miny, y);

      int dx[] = {0,0,1,-1};
      int dy[] = {-1,1,0,0};
      for (int j = 0; j < 4; j++) {
	ll w = max(pref_maxx[i]+dx[j],maxx)-min(pref_minx[i]+dx[j],minx)+1;
	ll h = max(pref_maxy[i]+dy[j],maxy)-min(pref_miny[i]+dy[j],miny)+1;

	ll need = w*h;
	ans = min(ans, need);
      }
    }
    cout << ans << endl;
  }
}