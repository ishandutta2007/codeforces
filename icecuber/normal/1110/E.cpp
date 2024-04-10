#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000], b[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector<int> da, db;
  for (int i = 1; i < n; i++) {
    da.push_back(a[i]-a[i-1]);
    db.push_back(b[i]-b[i-1]);
  }
  sort(da.begin(), da.end());
  sort(db.begin(), db.end());
  int ok = a[0] == b[0] && a[n-1] == b[n-1] && da == db;
  cout << (ok ? "Yes" : "No") << endl;
}