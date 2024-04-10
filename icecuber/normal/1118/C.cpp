#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400];
int ans[20][20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> c;
  for (int i = 0; i < n*n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  vector<int> l[5];
  int left = 0;
  for (auto p : c) {
    for (int i = 0; i < p.second/4; i++)
      l[4].push_back(p.first);
    int v = p.second%4;
    if (v)
      l[v].push_back(p.first);
  }
  vector<int> v;
  int p[5] = {0,1,3,2,4};
  for (int ii = 4; ii; ii--) {
    int i = p[ii];
    for (int k : l[i])
      for (int j = 0; j < i; j++)
	v.push_back(k);
  }
  int k = 0;
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < n/2; j++) {
      ans[i][j] = v[k++];
      ans[n-1-i][j] = v[k++];
      ans[i][n-1-j] = v[k++];
      ans[n-1-i][n-1-j] = v[k++];
    }
  }
  if (n%2) {
    for (int i = 0; i < n/2; i++) {
      ans[n/2][i] = v[k++];
      ans[n/2][n-1-i] = v[k++];
    }
    for (int i = 0; i < n/2; i++) {
      ans[i][n/2] = v[k++];
      ans[n-1-i][n/2] = v[k++];
    }
    ans[n/2][n/2] = v[k++];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (ans[i][j] != ans[n-1-i][j] || ans[i][j] != ans[i][n-1-j]) {
	cout << "NO" << endl;
	return 0;
      }
    }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << ' ';
    cout << endl;
  }
}