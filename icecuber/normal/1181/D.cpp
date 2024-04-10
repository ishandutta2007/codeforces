#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

vector<pair<ll,int>> query[500001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<ll,int>> c(m);
  for (int i = 0; i < m; i++) c[i] = {0,i+1};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a-1].x++;
  }
  sort(c.begin(), c.end());
  vector<ll> acc(m+1,0);
  for (int i = 1; i <= m; i++)
    acc[i] = acc[i-1]+c[i-1].x;

  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;
    k--;
    int fail = 0, pass = m;
    while (pass-fail > 1) {
      int mid = pass+fail>>1;
      if (acc[m]-acc[mid]+c[mid].x*mid > k)
	pass = mid;
      else
	fail = mid;
    }
    //cout << pass << ' ' << (k-(acc[m]-acc[pass]))%pass << endl;
    query[pass].emplace_back((k-(acc[m]-acc[pass]))%pass, i);
  }

  // 0 1 2 3

  //1 0 0 2 1
  //0 0 1 1 2
  //4 4 5 1 | 2 3 1 2 3

  {
    int n = 1<<19;
    vector<int> sum(n*2,0);
    vector<int> ans(q);
    for (int j = 0; j <= m; j++) {
      for (auto p : query[j]) {
	int i = 1;
	while (i < n) {
	  i *= 2;
	  if (sum[i] <= p.x)
	    p.x -= sum[i++];
	}
	ans[p.y] = i-n;
      }
      if (j == m) break;
      for (int i = c[j].y+n; i; i /= 2)
	sum[i]++;
    }
    for (int v : ans) cout << v << endl;
  }
}