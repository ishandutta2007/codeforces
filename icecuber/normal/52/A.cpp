#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int c[4] = {};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  int sum = c[1]+c[2]+c[3];
  int ma = max(c[1],max(c[2],c[3]));
  cout << sum-ma << endl;
}