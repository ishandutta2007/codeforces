#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int x[1000], y[1000], dx[1000], dy[1000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    cin >> dx[i] >> dy[i];
  for (int i = 0; i < n; i++) {
    int cx = x[i]+dx[0], cy = y[i]+dy[0];
    set<pair<int,int>> s;
    for (int j = 0; j < n; j++)
      s.insert({x[j],y[j]});
    int ok = 1;
    for (int j = 0; j < n; j++) {
      pair<int,int> p(cx-dx[j],cy-dy[j]);
      if (!s.count(p)) {
	ok = 0;
	break;
      }
      s.erase(p);
    }
    if (ok) {
      cout << cx << ' ' << cy << endl;
      return 0;
    }
  }
}