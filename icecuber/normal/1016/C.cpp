#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for (ll&v : a) cin >> v;
  for (ll&v : b) cin >> v;

  ll suma = 0, sumb = 0, sumaj = 0, sumbj = 0;
  for (int j = 0; j < n; j++) {
    suma += a[j];
    sumb += b[j];
    sumaj += a[j]*j;
    sumbj += b[j]*j;
  }
  ll ans = 0;
  ll acc = 0, t = 0;
  for (int i = 0; i < n; i++) {
    ll score = acc;
    score += suma*(t-i)+sumaj;
    score += sumb*(t+n*2-1-i)-sumbj;
    suma -= a[i];
    sumb -= b[i];
    sumaj -= a[i]*i;
    sumbj -= b[i]*i;
    /*
    for (int j = i; j < n; j++) {
      score += a[j]*(t-i)+a[j]*j;
      score += b[j]*(t+n*2-1-i)-b[j]*j;
      }*/
    ans = max(ans, score);
    acc += a[i]*t+b[i]*(t+1);
    t += 2;
    swap(a,b);
    swap(suma,sumb);
    swap(sumaj,sumbj);
  }
  cout << ans << endl;
}