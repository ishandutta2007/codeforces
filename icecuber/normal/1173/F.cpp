#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int px[1000], py[1000], ipx[1000], ipy[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> py[i];
    py[i]--;
    ipy[py[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> px[i];
    px[i]--;
    ipx[px[i]] = i;
  }

  vector<pair<pair<int,int>,pair<int,int>>> ans;
  auto add = [&](pair<int,int> a, pair<int,int> b) {
    ans.emplace_back(a,b);
    swap(px[a.first], px[b.first]);
    swap(ipx[px[a.first]], ipx[px[b.first]]);
    swap(py[a.second], py[b.second]);
    swap(ipy[py[a.second]], ipy[py[b.second]]);
  };
  for (int i = 0; i < n; i++)
    if (px[i] != i || py[i] != i)
      add({i,ipy[i]},{ipx[i],i});

  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first.second+1 << ' ' << p.first.first+1 << ' ' << p.second.second+1 << ' ' << p.second.first+1 << endl;
  }
  for (int i = 0; i < n; i++) {
    assert(px[i] == i);
    assert(ipx[i] == i);
    assert(py[i] == i);
    assert(ipy[i] == i);
  }
}