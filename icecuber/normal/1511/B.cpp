#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << int(pow(10,a-1)) << ' ' << int(pow(10,c-1))*int(pow(10,b-c)+1) << endl;
  }
}