#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n+2);
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    c[p]++;
  }
  int mis = 0, mas = 0;
  vector<int> mi(n+2), ma(n+2);
  for (int i = 1; i < n+1; i++) {
    for (int j = 0; j < c[i]; j++) {
      for (int k : {i-1,i,i+1})
	if (!ma[k]) {
	  ma[k] = 1;
	  mas++;
	  break;
	}
      int found = 0;
      for (int k : {i-1,i,i+1})
	if (mi[k]) found = 1;
      if (!found) mi[i+1] = 1, mis++;
    }
  }
  cout << mis << ' ' << mas << endl;
}