#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1) cout << 1 << endl;
  else if (n-m > m-1) cout << m+1 << endl;
  else cout << m-1 << endl;
}