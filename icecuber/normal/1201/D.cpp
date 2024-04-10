#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
int mi[nax], ma[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k, q;
  cin >> h >> w >> k >> q;
  fill_n(mi, h+1, 1e9);
  while (k--) {
    int y, x;
    cin >> y >> x;
    mi[y] = min(mi[y], x);
    ma[y] = max(ma[y], x);
  }
  vector<int> safe(q);
  for (int&v : safe) cin >> v;
  sort(safe.begin(), safe.end());

  auto upDist = [&](int a, int b) {
    auto right = lower_bound(safe.begin(), safe.end(), a);
    auto left = upper_bound(safe.begin(), safe.end(), a);
    int ans = 1e9;
    if (right != safe.end()) {
      ans = min(ans, abs(*right-a)+abs(*right-b));
    }
    if (left != safe.begin()) {
      --left;
      ans = min(ans, abs(*left-a)+abs(*left-b));
    }
    return ans;
  };

  ll left = 0, right = 0;
  int lpos = 1, rpos = 1;
  if (ma[1]) {
    left = ma[1]-lpos+(ma[1]-mi[1]);
    right = ma[1]-lpos;
    lpos = mi[1];
    rpos = ma[1];
  }
  int lasth = 1;
  for (int i = 2; i <= h; i++) {
    if (ma[i]) {
      lasth = i;
      ll newleft = 1e18, newright = 1e18;
      //Left to left
      newleft = min(newleft, left+upDist(lpos, ma[i])+(ma[i]-mi[i]));
      //Left to right
      newright = min(newright, left+upDist(lpos, mi[i])+(ma[i]-mi[i]));
      //Right to left
      newleft = min(newleft, right+upDist(rpos, ma[i])+(ma[i]-mi[i]));
      //Right to right
      newright = min(newright, right+upDist(rpos, mi[i])+(ma[i]-mi[i]));
      left = newleft;
      right = newright;
      lpos = mi[i];
      rpos = ma[i];
    }
  }
  cout << min(left, right)+lasth-1 << endl;
}