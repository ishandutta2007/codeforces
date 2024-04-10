#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    int a = b+ma;
    ma = max(ma, a);
    cout << a << ' ';
  }
  cout << endl;
}