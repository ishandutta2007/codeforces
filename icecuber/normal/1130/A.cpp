#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  for (int d : {-1,1}) {
    int oks = 0;
    for (int v : a)
      oks += v*d > 0;
    if (oks >= (n+1)/2) {
      cout << d << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}