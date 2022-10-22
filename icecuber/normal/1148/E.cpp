#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].x, a[i].y = i+1;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<pair<int,ll>> v;
  vector<pair<pair<int,int>,int>> ans;
  for (int i = 0; i < n; i++) {
    int&ai = a[i].x, bi = b[i];
    if (ai < bi) {
      v.emplace_back(a[i].y, bi-ai);
    } else if (bi < ai) {
      while (bi < ai) {
	if (v.empty()) {
	  cout << "NO" << endl;
	  return 0;
	}
	ll d = min(ll(ai-bi), v.back().second);
	ans.push_back({{v.back().first,a[i].y},d});
	ai -= d;
	v.back().second -= d;
	if (!v.back().second)
	  v.pop_back();
      }
    }
  }
  if (v.size()) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << '\n';
  cout << ans.size() << '\n';
  for (auto p : ans)
    cout << p.x.x << ' ' << p.x.y << ' ' << p.y << '\n';
}