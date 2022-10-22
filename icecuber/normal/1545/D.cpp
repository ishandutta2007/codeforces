#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, k;
  cin >> m >> k;
  vector<ll> sum(k), sum2(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      ll x;
      cin >> x;
      sum[i] += x;
      sum2[i] += x*x;
    }
  }
  ll sumv = (sum[k-1]-sum[0])/(k-1);
  int badk = -1;
  for (int i = 0; i < k; i++) {
    if (sum[0]+sumv*i != sum[i]) badk = i;
  }
  assert(badk != -1);
  int goodk = (badk == 1 ? 2 : 1);
  ll d = sum[badk]-(sum[0]+sumv*badk);
  ll A = (sum2[k-1]-sum2[0])/(k-1);
  ll B = (sum2[goodk]-sum2[0])/goodk;
  ll x2 = sum2[0];
  ll v2 = (A-B)/(k-1-goodk);
  ll vx2 = B-v2*goodk;
  ll y = ((sum2[badk]-v2*badk*badk-vx2*badk-x2)/d-d)/2;
  cout << badk << ' ' << y << endl;
}