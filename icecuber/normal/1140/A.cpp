#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int good = -1, days = 0;
  for (int i = 1; i <= n; i++) {
    if (i > good) days++;
    int a;
    cin >> a;
    good = max(good, a);
  }
  cout << days << endl;
}