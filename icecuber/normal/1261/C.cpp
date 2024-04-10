#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int area(vector<vector<int>>&acc, int x0, int y0, int x1, int y1) {
  return acc[y1][x1]+acc[y0][x0]-acc[y0][x1]-acc[y1][x0];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> acc(h+1, vector<int>(w+1));
  vector<string> row(h);
  for (int i = 0; i < h; i++) {
    cin >> row[i];
    for (int j = 0; j < w; j++) {
      acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+(row[i][j] == 'X');
    }
  }
  int pass = 0, fail = w;
  vector<string> ans = row;
  while (fail-pass > 1) {
    int mid = pass+fail>>1;
    vector<string> s(h, string(w,'.'));
    vector<vector<int>> cum(h+1, vector<int>(w+1));
    ll A = ll(mid*2+1)*(mid*2+1);
    for (int i = mid; i+mid < h; i++)
      for (int j = mid; j+mid < w; j++)
	if (area(acc, j-mid, i-mid, j+mid+1, i+mid+1) == A) {
	  s[i][j] = 'X';
	}

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	cum[i+1][j+1] = cum[i+1][j]+cum[i][j+1]-cum[i][j]+(s[i][j] == 'X');
      }
    }

    vector<string> dil(h, string(w,'.'));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if (area(cum, max(j-mid,0), max(i-mid,0), min(j+mid+1,w), min(i+mid+1,h))) {
	  dil[i][j] = 'X';
	}
      }
    }

    /*cout << mid << '\n';
    for (int i = 0; i < h; i++)
      cout << s[i] << '\n';
      cout << endl;*/

    if (row == dil) {
      pass = mid;
      ans = s;
    } else fail = mid;
  }
  cout << pass << '\n';
  for (int i = 0; i < h; i++)
    cout << ans[i] << '\n';
}