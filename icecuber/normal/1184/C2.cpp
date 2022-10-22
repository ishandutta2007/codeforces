#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 6e6+10;
vector<pair<int,int>> event[nax];

const int n = 1<<23;
int ma[n*2], lazy[n*2];
void add(int i, int v) {
  for (i += n; i > 1; i >>= 1) {
    if (i&1)
      lazy[i-1] += v;
    ma[i>>1] = max(ma[i]+lazy[i], ma[i^1]+lazy[i^1]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r;
  cin >> n >> r;
  for (int k = 0; k < n; k++) {
    int x, y;
    cin >> x >> y;
    int i = x-y+2e6;
    int j = x+y+2e6;
    event[i].push_back({j,-1});
    event[i].push_back({j+r*2+1,1});
    event[i+r*2+1].push_back({j,1});
    event[i+r*2+1].push_back({j+r*2+1,-1});
  }
  int ans = 0;
  for (int i = 0; i < nax; i++) {
    for (auto p : event[i])
      add(p.first, p.second);
    ans = max(ans,ma[1]);
  }
  cout << ans << endl;
}