#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 1;
  int prev;
  cin >> prev;
  int streak = 1;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    if (a > prev*2) streak = 1;
    else streak++;
    ans = max(ans, streak);
    prev = a;
  }
  cout << ans << endl;
}