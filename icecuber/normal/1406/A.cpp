#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> c(110);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a]++;
    }
    int twos = 0, ones = 0;
    while (c[twos] >= 2) twos++;
    while (c[ones] >= 1) ones++;
    cout << ones+twos << endl;
  }
}