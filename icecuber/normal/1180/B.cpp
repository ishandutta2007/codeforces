#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int mi = 0, mii;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0) a[i] = -a[i]-1;
    if (a[i] < mi) {
      mi = a[i];
      mii = i;
    }
  }
  if (n%2)
    a[mii] = -a[mii]-1;
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
}