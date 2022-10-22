#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int pass = 1, fail = n+1;
  while (pass < fail-1) {
    int mid = pass+fail>>1;
    int boxes = 1, room = k;
    for (int i = n-mid; i < n; i++) {
      if (room < a[i]) boxes++, room = k;
      room -= a[i];
    }
    if (boxes <= m) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}