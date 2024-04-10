#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int r = n%m;
  ll A = 0, B = 0, C = 0;
  for (int a = 0; a < m; a++)
    for (int b = 0; b < m; b++)
      if ((a*a+b*b)%m == 0) A++;
  for (int a = 0; a < m; a++)
    for (int b = 1; b <= r; b++)
      if ((a*a+b*b)%m == 0) B++;
  for (int a = 1; a <= r; a++)
    for (int b = 1; b <= r; b++)
      if ((a*a+b*b)%m == 0) C++;
  ll x = n/m;
  cout << x*x*A+x*2*B+C << endl;
}