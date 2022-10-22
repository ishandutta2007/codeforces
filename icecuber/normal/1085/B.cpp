#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int b = k-1; b; b--) {
    if (n%b==0) {
      cout << n/b*k+b << endl;
      return 0;
    }
  }
}