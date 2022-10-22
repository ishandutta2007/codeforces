#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

int a[100000], c[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int,int>> cheap;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    cheap.insert({c[i],i});
  }
  while (m--) {
    int t, d;
    cin >> t >> d;
    t--;
    ll cost = 0;
    while(1) {
      int eat = min(d,a[t]);
      a[t] -= eat;
      d -= eat;
      if (eat && !a[t])
	cheap.erase({c[t],t});
      cost += ll(eat)*c[t];
      if (!d) break;
      if (!cheap.size()) {
	cost = 0;
	break;
      }
      t = cheap.begin()->second;
    }
    cout << cost << endl;
  }
}