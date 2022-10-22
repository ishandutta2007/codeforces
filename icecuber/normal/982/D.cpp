#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,vector<int>> event;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    event[-a].push_back(i);
  }
  map<int,int> range;
  range[n] = 0;

  int bestk = -event.begin()->first+1, best = 1;
  map<int,int> lens;
  ++lens[n];
  int nxt = 0;
  for (auto [a,v] : event) {
    if (nxt == 1) bestk = -a + 1, nxt = 0;
    for (int i : v) {
      auto [r,l] = *range.upper_bound(i);
      range.erase(r);
      if (!--lens[r-l]) lens.erase(r-l);
      if (i > l) range[i] = l, ++lens[i-l];
      if (r > i+1) range[r] = i+1, ++lens[r-i-1];
    }
    if (lens.size() <= 1) {
      if ((int)range.size() >= best) {
	best = range.size();
	bestk = -a;
	nxt = 1;
      }
    }
  }
  cout << bestk << endl;
}