#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int n;
int a[1<<22];
int done1[1<<22][2];

void dfs1(int p, char t) {
  if (t == 0 && a[p] == 0 || done1[p][t]++) return;
  if (t == 0) {
    dfs1((1<<n)-1-p,1);
  } else {
    dfs1(p,0);
    for (int j = 0; j < n; j++)
      if (p>>j&1)
        dfs1(p^1<<j,1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> n >> m;
  while (m--) {
    int ai;
    cin >> ai;
    a[ai] = 1;
  }

  int ans = 0;
  for (int i = 0; i < 1<<n; i++) {
    if (a[i] && done1[i][0] == 0) {
      ans++;
      dfs1(i,0);
    }
  }
  cout << ans << endl;
}