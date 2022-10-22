#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> a(n), b(n);
  int suma = 0, sumb = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[j][i];
      suma += a[j][i];
    }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
      cin >> b[j][i];
      sumb += b[j][i];
    }
  if (suma != sumb) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  array<int,2> A = {0,0};
  array<int,2> B = {0,0};
  for (int i = 0; i < n; i++) {
    A[0] += a[i][0];
    A[1] += a[i][1];
    B[0] += b[i][0];
    B[1] += b[i][1];
    while (A[0] && B[0]) A[0]--, B[0]--;
    while (A[1] && B[1]) A[1]--, B[1]--;
    while (A[0] && B[1]) A[0]--, B[1]--, ans++;
    while (A[1] && B[0]) A[1]--, B[0]--, ans++;
    ans += A[0]+A[1]+B[0]+B[1];
  }

  /*int i = 0, j = 0;
  while (i < n && j < n) {
    int sa = a[i][0]+a[i][1];
    int sb = b[j][0]+b[j][1];
    if (sa == 0) {
      i++;
    } else if (sb == 0) {
      j++;
    } else if (sa == 2 && sb == 2) {
      ans += 2*abs(i-j);
      i++;
      j++;
    } else if (sa == 1 && sb == 1) {
      ans += abs(i-j)+(a[i][0]!=b[j][0]);
      i++;
      j++;
    } else if (sa == 2 && sb == 1) {
      ans += abs(i-j);
      a[i][b[j][1]] = 0;
      j++;
    } else if (sa == 1 && sb == 2) {
      ans += abs(i-j);
      b[j][a[i][1]] = 0;
      i++;
    } else assert(0);
  }*/
  cout << ans << endl;
}