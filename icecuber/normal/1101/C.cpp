#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

pair<pair<int,int>,int> p[100000];
int ans[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i].x.x >> p[i].x.y;
      p[i].y = i;
    }
    sort(p, p+n);
    int last = -1, two = -1;
    for (int i = 0; i < n; i++) {
      if (p[i].x.x > last) two++;
      ans[p[i].y] = !!two+1;
      last = max(last, p[i].x.y);
    }
    if (two) {
      for (int i = 0; i < n; i++)
	cout << ans[i] << ' ';
      cout << '\n';
    } else
      cout << -1 << '\n';
  }
}