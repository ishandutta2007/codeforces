#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k;
  cin >> w >> h >> k;
  vector<pair<int, int>> v;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x = (i%2 ? w-1-j : j)+1, y = i+1;
      v.push_back({x,y});
    }
  }
  for (int i = 0; i < k-1; i++) {
    cout << 2;
    cout << ' ' << v[i*2].first << ' ' << v[i*2].second;
    cout << ' ' << v[i*2+1].first << ' ' << v[i*2+1].second;
    cout << '\n';
  }
  cout << w*h-2*k+2;
  for (int i = k*2-2; i < w*h; i++)
    cout << ' ' << v[i].first << ' ' << v[i].second;
  cout << endl;
}