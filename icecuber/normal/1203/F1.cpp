#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

pair<int,int> f(vector<pair<int,int>>&a, int r0) {
  int r = r0;
  int count = 0;
  for (auto p : a) {
    if (r >= p.x) {
      r += p.y;
      count++;
    }
  }
  return {r,count};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r0;
  cin >> n >> r0;
  vector<pair<int,int>> pos, neg;
  for (int i = 0; i < n; i++) {
    int need, del;
    cin >> need >> del;
    if (del >= 0) pos.push_back({need,del});
    else neg.push_back({need+del,-del});
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  auto top = f(pos, r0);
  int ans = top.y;
  for (int r = 0; r <= top.x; r++) {
    auto p = f(neg, r);
    if (p.x == top.x) {
      ans = max(ans, top.y+p.y);
    }
  }
  cout << (ans==n ? "YES" : "NO") << endl;
}