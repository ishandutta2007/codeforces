#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  n = k+1;

  map<int,int> pos, cnt;
  for (int i = 0; i < n; i++) {
    cout << "?";
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      cout << ' ' << j+1;
    }
    cout << endl;
    int p, v;
    cin >> p >> v;
    p--;
    cnt[v]++;
    pos[v] = p;
  }
  cout << "! " << cnt.rbegin()->second << endl;
}