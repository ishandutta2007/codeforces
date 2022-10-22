#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> a, int m, int d, ll b, int n) {
  vector<ll> acc(n+1,0);
  for (int i = 0; i < n; i++)
    acc[i+1] = acc[i]+a[i];
  int fails = 0;
  for (int i = 0; i < m; i++) {
    ll can = acc[min(i+1+ll(i+1)*d,(ll)n)];
    ll need = (i+1-fails)*b;
    if (can < need) fails++;
  }
  return fails;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d, b;
  cin >> n >> d >> b;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int A = solve(a, (n+1)/2, d, b, n);
  reverse(a.begin(), a.end());
  int B = solve(a, n/2, d, b, n);
  cout << max(A,B) << endl;
}