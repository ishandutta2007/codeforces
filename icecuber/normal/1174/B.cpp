#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int has[2] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    has[a[i]%2]++;
  }
  if (has[0] && has[1]) sort(a, a+n);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
}