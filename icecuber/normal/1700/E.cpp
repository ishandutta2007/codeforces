#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> cur(h, vector<int>(w));
  int numbads = 0;
  auto check = [&](int i, int j) {
    int found = (a[i][j]==1);
    for (int d = 0; d < 4; d++) {
      int ni = i+(d==0)-(d==1);
      int nj = j+(d==2)-(d==3);
      if (ni >= 0 && nj >= 0 && ni < h && nj < w && a[ni][nj] < a[i][j])
        found = 1;
    }
    return !found;
  };
  auto update = [&](int i, int j) {
    for (int d = 0; d < 5; d++) {
      int ni = i+(d==0)-(d==1);
      int nj = j+(d==2)-(d==3);
      if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
        numbads -= cur[ni][nj];
        cur[ni][nj] = check(ni,nj);
        numbads += cur[ni][nj];
      }
    }
  };
  vector<array<int,2>> bads;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) 
      cin >> a[i][j];

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (check(i,j)) {
        numbads++;
        cur[i][j] = 1;
        bads.push_back({i,j});
      }

  if (bads.empty()) {
    cout << 0 << endl;
    return 0;
  }
  set<array<int,4>> done;
  int swaps = 0;
  for (int d = 0; d < 5; d++) {
    int ni = bads[0][0]+(d==0)-(d==1);
    int nj = bads[0][1]+(d==2)-(d==3);
    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        array<int,4> A = {i,j,ni,nj}, B = {ni,nj,i,j};
        if (A == B || done.count(A) || done.count(B)) continue;
        done.insert(A);
        swap(a[i][j], a[ni][nj]);
        update(i,j);
        update(ni,nj);
        if (!numbads) swaps++;
        swap(a[i][j], a[ni][nj]);
        update(i,j);
        update(ni,nj);
      }
    }
  }
  if (swaps == 0) cout << 2 << endl;
  else cout << 1 << ' ' << swaps << endl;
}