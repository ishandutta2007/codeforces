#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int b, k;
  cin >> b >> k;
  int odd = 0;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    if (a%2 && (i==k-1 || b%2)) odd ^= 1;
  }
  cout << (odd ? "odd" : "even") << endl;
}