#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 1;
  int last = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i-1]) last = i;
    ans = max(ans, i-last+1);
  }
  cout << ans << endl;
}