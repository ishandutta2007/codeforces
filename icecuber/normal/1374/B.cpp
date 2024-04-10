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
    int a = 0, b = 0;
    while (n%2 == 0) n /= 2, a++;
    while (n%3 == 0) n /= 3, b++;
    cout << (n == 1 && b-a >= 0 ? b*2-a : -1) << endl;
  }
}