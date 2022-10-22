#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    count[type]++;
  }
  int most = 0;
  for (auto p : count) {
    int type = p.first;
    int left = p.second;
    most = max(most, (left+k-1)/k);
  }
  //cout << most << endl;
  //cout << count.size() << ' ' << most << ' ' << k << ' ' << n << endl;
  cout << k*int(count.size())*most-n << endl;
}