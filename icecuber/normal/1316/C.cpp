#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p;
int solve(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) if (a[i]%p) return i;
  assert(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb >> p;
  int a = solve(na);
  int b = solve(nb);
  cout << a+b << endl;
}