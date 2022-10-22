#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000000];
pair<int,int> sparse[20][1000000];
void build(int n) {
  for (int i = 0; i < n; i++)
    sparse[0][i] = {a[i],i};
  for (int j = 0; j < 19; j++)
    for (int i = 0; i+(1<<j) <= n; i++)
      sparse[j+1][i] = max(sparse[j][i],sparse[j][i+(1<<j)]);
}
ll dq(int l, int r) {
  if (r-l == 0) return 0;
  if (r-l == 1) return a[l];
  int lod = log2(r-l);
  int m = max(sparse[lod][l], sparse[lod][r-(1<<lod)]).second;
  ll ans = ll(m-l+1)*(r-m)*a[m];
  return ans+dq(l,m)+dq(m+1,r);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(n);
  ll ans = dq(0,n);
  for (int i = 0; i < n; i++) a[i] *= -1;
  build(n);
  ans += dq(0,n);
  cout << ans << endl;
}