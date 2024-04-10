#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  vector<int> ans;
  int fail = -1, pass = 1e9;
  while (pass-fail > 1) {
    int mid = pass+fail>>1;
    vector<int> done(n,0);
    int p = 0;
    int ok = 1;
    vector<int> sol;
    while (p < n-1) {
      sol.push_back(a[p]);
      done[p] = 1;
      int base = a[p], p0 = p;
      while (p < n-1 && base+mid >= a[p+1]) p++;
      if (p == p0) {
	ok = 0;
	break;
      }
    }
    int last = a[p];
    for (int i = n-1; i >= 0; i--) {
      if (!done[i]) {
	if (last-a[i] > mid) ok = 0;
	last = a[i];
	sol.push_back(a[i]);
      }
    }
    if (last-a[0] > mid) ok = 0;
    if (ok) pass = mid, ans = sol;
    else fail = mid;
  }
  for (int i : ans) cout << i << ' ';
  cout << endl;
}