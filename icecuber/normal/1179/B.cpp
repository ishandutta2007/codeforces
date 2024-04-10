#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h;
  cin >> w >> h;
  auto gen = [&](int w) {
    vector<int> x;
    int l = 1, r = w;
    for (int i = 0; i < w; i++) {
      if (i%2)
	x.push_back(r--);
      else
	x.push_back(l++);
    }
    for (int i = 0; i < w; i++)
      x.push_back(x[w-1-i]);
    return x;
  };
  vector<int> x = gen(w), y = gen(h);
  for (int i = 0; i < h; i += 2) {
    for (int j = 0; j < w+(i<h-1)*w; j++)
      cout << x[j] << ' ' << y[i+j%2] << '\n';
  }
}