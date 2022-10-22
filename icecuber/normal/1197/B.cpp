#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int ma = -1, mai;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > ma) {
      ma = a[i];
      mai = i;
    }
  }
  int ok = 1;
  for (int j = 0; j < mai; j++) {
    if (a[j] > a[j+1]) ok = 0;
  }
  for (int j = mai+1; j < n; j++) {
    if (a[j-1] < a[j]) ok = 0;
  }
  cout << (ok ? "YES" : "NO") << endl;
}