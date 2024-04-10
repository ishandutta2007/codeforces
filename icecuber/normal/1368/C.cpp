#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cout << n*3+4 << endl;
  cout << 0 << ' ' << 0 << endl;
  for (int i = 0; i <= n; i++) {
    cout << i << ' ' << i+1 << endl;
    cout << i+1 << ' ' << i+1 << endl;
    cout << i+1 << ' ' << i << endl;
  }
}