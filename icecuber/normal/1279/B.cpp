#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    ll sum = 0;
    priority_queue<pair<int,int>> pq;
    int best = -1, besti = -1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
      pq.emplace(a,i);
      if (sum <= s && i+1 > best) {
	best = i+1;
	besti = -1;
      }
      if (sum-pq.top().first <= s && i > best) {
	best = i;
	besti = pq.top().second;
      }
    }
    cout << besti+1 << endl;
  }
}