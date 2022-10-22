#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> like;
  for (int i = 1; like.size() < 1000; i++) {
    if (i%10 == 3 || i%3 == 0) continue;
    like.push_back(i);
  }
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    cout << like[k-1] << endl;
  }
}