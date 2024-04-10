#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, K;
    cin >> n >> K;
    vector<vector<int>> child(n);
    for (int i = 1; i < n; i++) {
      int par;
      cin >> par;
      par--;
      child[par].push_back(i);
    }
    vector<ll> s(n);
    for (ll&v : s) cin >> v;

    map<array<int,2>,ll> mem;
    function<ll(int,int)> rec = [&](int p, int k) {
      auto [it,inserted] = mem.insert({{p,k},0ll});
      if (inserted) {
        it->second += k*s[p];
        int childs = child[p].size();
        if (childs) {
          int r = k%childs;
          if (r == 0) {
            for (int i : child[p]) it->second += rec(i,k/childs);
          } else {
            vector<array<ll,2>> v(childs);
            for (int i = 0; i < childs; i++) 
              for (int j : {0,1}) 
                v[i][j] = rec(child[p][i],k/childs+j);
            sort(v.begin(), v.end(), [&](array<ll,2> a, array<ll,2> b) {
                return a[1]-a[0] > b[1]-b[0];
                });
            for (int i = 0; i < childs; i++)
              it->second += v[i][i<r];
          }
        }
      }
      return it->second; 
    };
    cout << rec(0,K) << endl;
  }
}