#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  reverse(a, a+n);
  int bads = m/(k+1);
  int goods = m-bads;
  cout << 1ll*goods*a[0]+1ll*bads*a[1] << endl;
}