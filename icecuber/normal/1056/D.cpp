#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int par[100000], sz[100000], c[100001], ans[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  fill_n(sz, n, 1);
  par[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    par[i]--;
    sz[par[i]] = 0;
  }
  for (int i = n-1; i; i--)
    sz[par[i]] += sz[i];
  for (int i = 0; i < n; i++)
    c[sz[i]]++;
  int j = 1;
  for (int i = 1; i <= n; i++) {
    c[i] += c[i-1];
    while (j <= n && c[i] >= j)
      ans[j++] = i;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}