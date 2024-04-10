#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[1000], y[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  while (1) {
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      (x[i]+y[i]&1 ? b : a).push_back(i);
    }
    if (a.size()%n == 0) {
      for (int i = 0; i < n; i++) {
	tie(x[i], y[i]) = make_pair((x[i]+y[i])>>1, (x[i]-y[i])>>1);
      }
    } else {
      cout << a.size() << endl;
      for (int i : a) cout << i+1 << ' ';
      cout << endl;
      return 0;
    }
  }
}