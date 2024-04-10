#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int ok(int problems) {
  if (problems > n) return 0;
  int need = 0;
  for (int i = 1; i <= problems; i++)
    need += 5*i;
  return need+k <= 4*60;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  int pass = 0, fail = n+1;
  while (fail-pass > 1) {
    int mid = (pass+fail)/2;
    if (ok(mid)) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}