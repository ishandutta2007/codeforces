#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+10;
int isprime[nax];


vector<int> node[nax];
int dist[nax];

int ans = 1e9;
void bfs(int s, int n) {
  queue<int> q;
  q.push(s);
  vector<int> undos;
  //vector<int> dist(n,1e9);
  dist[s] = 0;
  undos.push_back(s);
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p]) {
      if (dist[i] == 1e9) {
	dist[i] = dist[p]+1;
	undos.push_back(i);
	q.push(i);
      } else if (dist[i] >= dist[p]) {
	ans = min(ans, dist[i]+dist[p]+1);
	goto finish;
      }
    }
  }
 finish:
  for (int i : undos) dist[i] = 1e9;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < nax; i++) isprime[i] = 1;
  vector<int> prime;
  for (int i = 2; i < nax; i++) {
    if (!isprime[i]) continue;
    prime.push_back(i);
    for (int j = i*2; j < nax; j += i)
      isprime[j] = 0;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vector<int> facs;
    for (int p : prime) {
      if ((ll)p*p > a) break;
      if (a%p == 0) {
	int c = 0;
	while (a%p == 0) {
	  c ^= 1;
	  a /= p;
	}
	if (c) facs.push_back(p);
      }
    }
    if (a > 1) facs.push_back(a);
    assert(facs.size() <= 2);
    if (facs.size() == 0) {
      cout << 1 << endl;
      return 0;
    } else if (facs.size() == 1) {
      node[1].push_back(facs[0]);
      node[facs[0]].push_back(1);;
    } else {
      int a = facs[0], b = facs[1];
      node[a].push_back(b);
      node[b].push_back(a);
    }
  }

  fill_n(dist, nax, 1e9);
  for (int i = 0; i < 1e3; i++)
    bfs(i, nax);
  cout << (ans == 1e9 ? -1 : ans) << endl;
}