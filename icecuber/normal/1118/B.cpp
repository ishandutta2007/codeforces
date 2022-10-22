#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i]*(i%2 ? 1 : -1);
  }
  int ans = 0;
  int sum2 = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i]*(i%2 ? 1 : -1);
    if (sum-v-sum2 == sum2) ans++;
    sum2 += v;
  }
  cout << ans << endl;
}