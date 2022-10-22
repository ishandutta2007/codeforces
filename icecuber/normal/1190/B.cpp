#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i]-i;
  }
  map<int,int> count;
  for (int i = 0; i < n; i++) {
    if (count[a[i]]++) {
      int neg = 0;
      if (--a[i] < 0) neg = 1;
      sort(a.begin(), a.end());
      if (unique(a.begin(), a.end()) != a.end() || neg) {
	cout << "cslnb" << endl;
	return 0;
      }
      break;
    }
  }
  cout << (sum%2 == 0 ? "cslnb" : "sjfnb") << endl;
}