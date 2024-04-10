#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, k;
    cin >> a >> b >> k;
    cout << (a-b)*(k/2)+a*(k%2) << endl;
  }
}