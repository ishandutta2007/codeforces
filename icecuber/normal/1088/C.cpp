#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << n+1 << endl;
  for (int i = n-1; i >= 0; i--) {
    int x = ((i-a[i])%n+n)%n;
    for (int j = 0; j <= i; j++)
      a[j] += x;
    cout << 1 << ' ' << i+1 << ' ' << x << endl;
  }
  cout << 2 << ' ' << n << ' ' << n << endl;
}