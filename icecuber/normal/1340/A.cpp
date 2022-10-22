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
    vector<int> p(n), ip(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
      ip[p[i]] = i;
    }
    vector<int> cnt(n,1);
    multiset<int> mcnt;
    set<int> nxt;
    for (int i = 0; i < n; i++) {
      mcnt.insert(1);
      nxt.insert(i);
    }

    int ok = 1;
    for (int i = 0; i < n; i++) {
      int pos = ip[i];

      /*for (int j = 0; j < n; j++)
	cout << cnt[j] << ' ';
	cout << endl;*/
      if (cnt[pos] != *mcnt.rbegin()) {
	ok = 0;
	break;
      }
      auto it = nxt.upper_bound(pos);
      if (it != nxt.end()) {
	int np = *it;
	mcnt.erase(mcnt.find(cnt[np]));
	cnt[np] += cnt[pos];
	mcnt.insert(cnt[np]);
      }
      mcnt.erase(mcnt.find(cnt[pos]));
      nxt.erase(pos);
      cnt[pos] = 0;
      mcnt.insert(cnt[pos]);
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}