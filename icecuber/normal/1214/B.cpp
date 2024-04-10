#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int b, g, n;
  cin >> b >> g >> n;
  cout << max(n+1-max(n-g,0)-max(n-b,0),1) << endl;
}