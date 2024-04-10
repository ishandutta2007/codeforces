#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> divs[20001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= 20000; i++) {
    for (int d = 1; d*d <= i; d++) {
      if (i%d == 0) {
	divs[i].push_back(d);
	if (d*d < i)
	  divs[i].push_back(i/d);
      }
    }
  }
  vector<tuple<int,int,int>> all;
  for (int c = 1; c <= 20000; c++)
    for (int b : divs[c])
      for (int a : divs[b])
	all.emplace_back(a,b,c);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int best = 1e9;
    tuple<int,int,int> ans;
    for (auto [x,y,z] : all) {
      int score = abs(a-x)+abs(b-y)+abs(c-z);
      if (score < best) {
	best = score;
	ans = {x,y,z};
      }
    }
    cout << best << endl;
    auto [x,y,z] = ans;
    cout << x << ' ' << y << ' ' << z << endl;
  }
}