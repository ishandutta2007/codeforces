#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500][500];
vector<int> mat(int w, int h) {
  vector<int> r(h,0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      r[i] ^= a[i][j];
    }
  }
  for (int j = 0; j < w; j++) {
    int v = 0;
    for (int i = 0; i < h; i++) {
      v ^= a[i][j];
    }
    r.push_back(v);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  auto a = mat(w, h);
  auto b = mat(w, h);
  cout << (a == b ? "Yes" : "No") << endl;
}