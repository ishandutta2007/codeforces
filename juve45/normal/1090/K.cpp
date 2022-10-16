#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int i, j, n, mask[N], last[N], nr, need[N], bucket[N];
string a[N], b[N];
vector<vector<int>> ans;
vector<int> v[N];
map<pair<int, int>, int> M;

int getPref(string &a, string &b) {
  int sz = min(a.size(), b.size());
  for(int i = 0; i < sz; ++i)
    if(a[i] != b[i]) return i;
  return sz;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i]; last[i] = -1;
    for(char c : b[i]) mask[i] |= (1 << (c - 'a'));
    for(j = a[i].size() - 1; j >= 0; --j) 
      if(!((mask[i] >> (a[i][j] - 'a')) & 1)) {
        last[i] = j;
        break;
      }

    pair<int, int> aux = make_pair(last[i], mask[i]);
    if(!M.count(aux)) {
      ++nr;
      need[nr] = last[i];
      M[aux] = nr;
    }

    bucket[i] = M[aux];
    v[bucket[i]].push_back(i);
  }

  for(i = 1; i <= nr; ++i) {
    sort(v[i].begin(), v[i].end(), [&](int x, int y) { return a[x] < a[y]; });

    for(j = 0; j < v[i].size();) {
      int cnt = 1;
      while(j + cnt < v[i].size() && getPref(a[v[i][j]], a[v[i][j + cnt]]) > need[i]) ++cnt;
      vector<int> aux;
      while(cnt--) {
        aux.push_back(v[i][j]);
        ++j;
      }
      ans.push_back(aux);
    }
  }

  cout << ans.size() << '\n';
  for(auto v : ans) {
    cout << v.size() << ' ';
    for(int it : v) cout << it << ' ';
    cout << '\n';
  }

  return 0;
}