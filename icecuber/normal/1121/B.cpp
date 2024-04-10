#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000], ans[200001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int best = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      best = max(best, ++ans[a[i]+a[j]]);
  cout << best << endl;
}