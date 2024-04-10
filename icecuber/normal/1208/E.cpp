#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+10;
ll ans[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, w;
  cin >> n >> w;
  w += 2;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> a(k+2,0);
    for (int j = 0; j < k; j++)
      cin >> a[j+1];
    k += 2;

    int l = w-k+1;
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < w; i++) {
      if (i < k)
	pq.push({a[i],i});
      while (pq.top().second+l <= i) pq.pop();
      assert(pq.size());
      ll v = pq.top().first;
      if (i == k && w-k > i) {
	int j = w-k;
	ans[j] -= v;
	ans[i] += v;
	i = j-1;
      } else {
	ans[i+1] -= v;
	ans[i] += v;
      }
    }
  }
  ll acc = 0;
  for (int i = 1; i < w-1; i++) {
    acc += ans[i];
    cout << acc << ' ';
  }
  cout << endl;
}