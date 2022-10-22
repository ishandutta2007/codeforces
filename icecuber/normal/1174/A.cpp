#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ok = 0;
  for (int i = 0; i < n*2; i++) {
    cin >> a[i];
    if (a[i] != a[0]) ok = 1;
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    sort(a, a+n*2);
    for (int i = 0; i < n*2; i++)
      cout << a[i] << ' ';
    cout << endl;
  }
}