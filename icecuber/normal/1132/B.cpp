#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a,a+n);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    cout << sum-a[n-q] << endl;
  }
}