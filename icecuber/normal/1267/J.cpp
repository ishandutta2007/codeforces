#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int,int> count;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      ++count[c];
    }
    map<int,int> ccount;
    for (auto p : count) ccount[p.second]++;

    int need = n;
    for (int s = 2; s <= ccount.rbegin()->first; s++) {
      int ok = 0;
      for (auto p : ccount) {
	int c = p.first;
	int mi = (c+s-1)/s, ma = c/(s-1);
	if (mi > ma) ok = n;
	ok += mi*p.second;
      }
      need = min(need, ok);
    }
    cout << need << endl;
  }
}