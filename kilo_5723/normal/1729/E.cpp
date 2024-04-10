#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 55;
ll a[maxn];
int main() {
  for (int i = 0; i < 25; i++) {
    cout << '?' << ' ' << i + 1 << ' ' << i + 2 << endl;
    cin >> a[i * 2];
    cout << '?' << ' ' << i + 2 << ' ' << i + 1 << endl;
    cin >> a[i * 2 + 1];
    if (a[i * 2] == -1 || a[i * 3] == -1) {
      cout << "! " << i + 2 << endl;
      return 0;
    }
    if (a[i * 2] != a[i * 2 + 1]) {
      cout << "! " << a[i * 2] + a[i * 2 + 1] << endl;
      return 0;
    }
  }
  cout << "! " << a[0] + a[1] << endl;
  return 0;
}