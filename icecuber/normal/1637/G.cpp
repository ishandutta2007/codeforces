#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << -1 << endl;
      continue;
    }
    int m = 1;
    while (m < n) m *= 2;
    vector<array<int,2>> ans;
    { 
      map<int,int> has;
      vector<int> cnt(m+1);
      for (int i = 1; i <= n; i++) cnt[i]++, has[i];
      while (has.size() > 1) {
        //for (int i = 0; i <= m; i++) assert(has.count(i) == !!cnt[i]);
        for (int k = m; k >= 1; k /= 2) {
          for (auto it = has.rbegin(); it != has.rend(); it++) {
            int v = it->first;
            if (v <= k-v) break;
            if (v >= k) continue;
            assert(cnt[v]);
            /*if (has.count(k-v) != !!cnt[k-v]) {
              cout << k-v << ' ' << n << ' ' << m << endl;
            }
            assert(has.count(k-v) == !!cnt[k-v]);*/
            if (cnt[k-v]) {
              int take = min(cnt[v],cnt[k-v]);
              for (int i = 0; i < take; i++) ans.push_back({v,k-v});
              cnt[k] += take;
              cnt[v*2-k] += take;
              has[k], has[v*2-k];
              cnt[v] -= take;
              cnt[k-v] -= take;
              if (!cnt[v]) has.erase(v);
              if (!cnt[k-v]) has.erase(k-v);
              goto next;
            }
          }
        }
        for (int k = 2; k <= m; k *= 2) {
          int v = k/2;
          if (has.count(v) && cnt[v] >= 2) {
            int take = cnt[v]/2;
            for (int i = 0; i < take; i++) ans.push_back({v,v});
            cnt[v] -= take*2;
            if (!cnt[v]) has.erase(v);
            cnt[0] += take;
            cnt[k] += take;
            has[0], has[k];
            goto next;
          }
        }
        for (int v = 1; v <= m; v *= 2) {
          if (has.count(v) && has.count(0)) {
            int take = min(cnt[0], cnt[v]);
            for (int i = 0; i < take; i++) ans.push_back({0,v});
            //assert(cnt[v] == 1 || v == m);
            //assert(cnt[0]);
            cnt[v]+=take;
            cnt[0]-=take;
            has[v];
            if (!cnt[0]) has.erase(0);
            goto next;
          }
        }
        //cout << "Fail" << endl;
        assert(0);
next:;
      }
      //for (auto [v,c] : cnt) if (c) cerr << v << ',' << c << ' ';
      //cerr << endl;
    } 
    cout << ans.size() << endl;
    for (auto [x,y] : ans) cout << x << ' ' << y << '\n';
    assert(ans.size() <= n*20);

    if (1) {
      map<int,int> cnt;
      for (int i = 1; i <= n; i++) cnt[i]++;
      for (auto [x,y] : ans) {
        assert(--cnt[x] >= 0);
        assert(--cnt[y] >= 0);
        cnt[x+y]++;
        cnt[abs(x-y)]++;
      }
      //for (auto [v,c] : cnt) if (c) cerr << v << ',' << c << ' ';
      //cerr << endl;
      assert(cnt[m] == n);
    } 
  }

  /*
     map<vector<int>,int> dist;
     priority_queue<vec, vector<vec>, function<bool(vec,vec)>> pq(cmp);
     vector<int> init;
  //for (int i = 1; i <= n; i++) init.push_back(i);
  init = {1,2,0,8,8,8};
  int n = init.size();

  pq.push(init);
  dist[init] = 0;
  while (pq.size()) {
  auto p = pq.top();
  pq.pop();
  int ok = 1;
  for (int i = 0; i < n; i++) {
  if (p[i] != p[0]) ok = 0;
  }
  if (ok) {
  cout << n << ": " << p[0] << endl;
  break;
  }
  for (int i = 0; i < n; i++) {
  for (int j = 0; j < i; j++) {
  auto q = p;
  int x = q[i], y = q[j];
  q.erase(q.begin()+i);
  q.erase(q.begin()+j);
  q.push_back(x+y);
  q.push_back(abs(x-y));
  sort(q.begin(), q.end());
  if (!dist.count(q)) {
  pq.push(q);
  dist[q] = dist[p]+1;
  }
  }
  }
  }*/

}