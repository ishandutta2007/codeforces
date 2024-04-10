#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coulds[1<<18][20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = n*20;
  for (int i = 0; i < n; i++) {
    int steps = 0;
    coulds[a[i]][0]++;
    while (a[i]) {
      a[i] /= 2;
      steps++;
      coulds[a[i]][steps]++;
    }
  }
  for (int v = 0; v < 1<<18; v++) {
    int cp = k, need = 0;
    for (int i = 0; i < 20; i++) {
      if (cp > coulds[v][i]) {
	cp -= coulds[v][i];
	need += i*coulds[v][i];
      } else {
	need += i*cp;
	cp = 0;
	break;
      }
    }
    if (cp == 0)
      ans = min(ans, need);
  }
  cout << ans << endl;
}