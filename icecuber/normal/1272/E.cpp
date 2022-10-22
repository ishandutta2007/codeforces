#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
vector<int> node[nax];
int odist[nax], edist[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  queue<int> odd, even;
  fill_n(odist, n, 1e9);
  fill_n(edist, n, 1e9);
  vector<int> a0(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a0[i] = a;
    (a%2 ? odd : even).push(i);
    (a%2 ? odist : edist)[i] = 0;
    if (i+a < n)
      node[i+a].push_back(i);
    if (i-a >= 0)
      node[i-a].push_back(i);
  }
  for (int k : {0,1}) {
    queue<int> q = k ? odd : even;
    int*dist = k ? odist : edist;
    while (q.size()) {
      int p = q.front();
      q.pop();
      for (int i : node[p]) {
	if (dist[i] == 1e9) {
	  dist[i] = dist[p]+1;
	  q.push(i);
	}
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int d = (a0[i]%2 ? edist[i] : odist[i]);
    cout << (d==1e9 ? -1 : d) << ' ';
  }
  cout << endl;
}