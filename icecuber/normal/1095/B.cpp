#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  cout << min(a[n-1]-a[1], a[n-2]-a[0]) << endl;
}