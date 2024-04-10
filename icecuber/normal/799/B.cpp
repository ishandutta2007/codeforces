#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  priority_queue<ll> pq[3][3];
  int n;
  cin >> n;
  vector<int> p(n),a(n),b(n);
  for (int&v : p) cin >> v;
  for (int&v : a) cin >> v;
  for (int&v : b) cin >> v;
  for (int i = 0; i < n; i++) {
    pq[a[i]-1][b[i]-1].push(-p[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int c;
    cin >> c;
    c--;
    int a, b;
    ll pay = 2e9;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
	if (i == c || j == c) {
	  if (pq[i][j].size() && -pq[i][j].top() < pay) {
	    pay = -pq[i][j].top();
	    a = i, b = j;
	  }
	}
      }
    }
    if (pay == 2e9) {
      cout << -1 << ' ';
    } else {
      cout << pay << ' ';
      pq[a][b].pop();
    }
  }
  cout << endl;
}