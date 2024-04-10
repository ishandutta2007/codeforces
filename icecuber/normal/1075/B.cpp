#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[200000], t[200000];
int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n+m; i++)
    cin >> x[i];
  vector<int> taxi;
  for (int i = 0; i < n+m; i++) {
    cin >> t[i];
    if (t[i]) taxi.push_back(x[i]);
  }
  for (int i = 0; i < n+m; i++) {
    if (t[i]) continue;
    int j = upper_bound(taxi.begin(), taxi.end(), x[i])-taxi.begin();
    if (j == 0 || j < m && x[i]-taxi[j-1] > taxi[j]-x[i])
      a[j]++;
    else
      a[j-1]++;
  }
  for (int i = 0; i < m; i++)
    cout << a[i] << ' ';
  cout << endl;
}