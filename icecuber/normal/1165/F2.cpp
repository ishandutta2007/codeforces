#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> offer[1000000];
int need[200000];
int has[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> need[i];
    sum += need[i];
  }
  for (int i = 0; i < m; i++) {
    int d, t;
    cin >> d >> t;
    offer[d-1].push_back(t-1);
  }
  int fail = 0, pass = 5e5;
  while (pass-fail > 1) {
    int mid = fail+pass>>1;
    fill_n(has, n, 0);
    int burles = mid, save = 0;
    for (int i = mid-1; i >= 0; i--) {
      burles = min(burles, i+1);
      for (int j : offer[i]) {
	if (has[j] < need[j]) {
	  int buy = min(need[j]-has[j], burles);
	  burles -= buy;
	  has[j] += buy;
	  save += buy;
	}
      }
    }
    if (mid+save >= sum*2) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}