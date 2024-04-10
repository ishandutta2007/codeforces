#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c[2][2];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    c[a[i]-'0'][b[i]-'0']++;
  }
  cout << c[0][0]*c[1][0] + c[1][1]*c[0][0] + c[1][0]*c[0][1] << endl;
}