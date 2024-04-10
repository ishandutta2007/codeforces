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
    vector<int> c[2] = {vector<int>(n,0),vector<int>(n,0)};
    for (int i = 0; i < n; i++) {
      int a, f = 0;
      cin >> a;
      a--;
      c[f][a]++;
    }
    vector<pair<int,int>> b;
    for (int i = 0; i < n; i++)
      if (c[0][i]+c[1][i])
	b.push_back({c[0][i]+c[1][i],c[1][i]});
    sort(b.begin(), b.end());
    int j = int(b.size())-1;
    int ansn = 0, ansf = 0;
    priority_queue<int> pq;
    for (int i = n; i > 0; i--) {
      while (j >= 0 && b[j].first >= i)
	pq.push(b[j--].second);
      if (pq.size()) {
	ansf += min(pq.top(),i);
	pq.pop();
	ansn += i;
      }
    }
    cout << ansn << endl;
  }
}