#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int pass = 1e9, fail = 0;
  while (pass-fail > 1) {
    int mid = (pass+fail)/2;
    int ok = 0;
    for (int flip : {0,1}) {
      int len = 0;
      for (int v : a) {
	if (flip || v <= mid) {
	  len++;
	  flip ^= 1;
	}
      }
      if (len >= k) ok = 1;
    }
    if (ok) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}