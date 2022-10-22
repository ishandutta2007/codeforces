#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<pair<int,vector<int>>> a(n, make_pair(0, vector<int>(m)));
  map<int,int> cnt;
  vector<int> w(n);
  map<int,vector<int>> pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      a[i].second[j] = v;
      cnt[v]++;
    }
    cin >> a[i].first;
  }
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      pos[a[i].second[j]].push_back(i);

  int B = min(3000, (int)cnt.size());
  vector<array<int,2>> srt;
  for (auto [v,c] : cnt)
    srt.push_back({c,v});
  sort(srt.rbegin(), srt.rend());

  map<int, bitset<nax>> mask;
  for (int i = 0; i < B; i++) {
    int v = srt[i][1];
    mask[v].flip();
    for (int j : pos[v])
      mask[v][j] = 0;
  }

  int ans = 2e9+10;
  for (int i = 0; i < n; i++) {
    bitset<nax> avail;
    avail.flip();
    for (int j = 0; j < m; j++) {
      int v = a[i].second[j];
      if (mask.count(v))
        avail &= mask[v];
      else
        for (int k : pos[v])
          avail[k] = 0;
    }
    {
      int j = avail._Find_first();
      if (j < n) {
        ans = min(ans, a[i].first+a[j].first);
      }
    }
  }
  if (ans == 2e9+10) ans = -1;
  cout << ans << endl;
}