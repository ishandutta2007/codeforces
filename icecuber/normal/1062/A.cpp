#include <bits/stdc++.h>
using namespace std;

int a[1002];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = 0;
  a[n+1] = 1001;
  n += 2;
  int streak = 0, maxstreak = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i-1]+1) {
      streak++;
      maxstreak = max(maxstreak, streak);
    }
    else streak = 0;
  }
  cout << max(0, maxstreak-1) << endl;
}