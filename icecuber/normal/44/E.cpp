#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, a, b;
  string s;
  cin >> k >> a >> b >> s;
  int n = s.size();
  if (k*a > n || k*b < n) {
    cout << "No solution" << endl;
  } else {
    for (int i = 0; i < k; i++) {
      cout << s.substr(i*n/k,(i+1)*n/k-i*n/k) << endl;
    }
  }
}