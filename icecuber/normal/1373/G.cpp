#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<19;
int ma[nax*2], off[nax*2];
void add(int i, int v) {
  for (i += nax; i > 1; i >>= 1) {
    if (i&1) {
      off[i-1] += v;
    }
    ma[i>>1] = max(ma[i]+off[i], ma[i^1]+off[i^1]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  set<pair<int,int>> has;
  multiset<int> cur;
  for (int i = 0; i < n*2+10; i++) {
    add(i, -i);
    add(i+1, i);
  }
  add(nax-1, -1e9);
  while (q--) {
    int x, y;
    cin >> x >> y;
    int z = y+abs(x-k);
    if (has.count({x,y})) {
      has.erase({x,y});
      cur.erase(cur.find(z));
      add(z,-1);
    } else {
      has.insert({x,y});
      cur.insert(z);
      add(z,1);
    }
    if (cur.size())
      add(*cur.rbegin(), 1e9);
    cout << max(ma[1],n)-n << endl;
    if (cur.size())
      add(*cur.rbegin(),-1e9);
  }
}