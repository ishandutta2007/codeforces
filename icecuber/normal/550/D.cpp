#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void put(int a, int b) {
  cout << a+1 << ' ' << b+1 << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;
  if (k%2==0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << '\n';
  int n = (k-1)/2;
  cout << 4*k-2 << ' ' << k*(4*k-2)/2 << '\n';
  for (int i = 0; i < n; i++)
    put(i,i+n), put(i+4*n,i+5*n);
  for (int i = 0; i < 2*n; i++)
    for (int j = 0; j < 2*n; j++)
      put(i,j+2*n), put(i+4*n,j+6*n);
  for (int i = 0; i < 2*n; i++)
    put(i+2*n,8*n),put(i+6*n,8*n+1);
  put(8*n,8*n+1);
}