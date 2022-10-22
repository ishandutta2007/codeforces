#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1000][1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int j = (i+1)%n, k = (i+2)%n;
    ll v = a[i][j]*a[i][k]/a[j][k];
    ll x = sqrt(v);
    while (x*x < v) x++;
    while (x*x > v) x--;
    cout << x << ' ';
  }
  cout << endl;
}