#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, x, y;
  cin >> n >> x >> y;
  ll dw = max(x-1,y-1), db = max(n-x,n-y);
  if (dw <= db) cout << "White" << endl;
  else cout << "Black" << endl;
}