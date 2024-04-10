#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n%2)
      cout << (k-1 + (k-1)/((n-1)/2))%n+1 << endl;
    else
      cout << (k-1)%n+1 << endl;
  }
}