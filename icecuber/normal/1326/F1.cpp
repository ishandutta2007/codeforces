#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//#warning change nax
const int nax = 14;
int adj[nax][nax];

ll ans[1<<(nax-1)];
//ll ways[1<<nax][1<<(nax-1)][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      adj[i][j] = (row[j] == '1');
    }
  }

  vector<vector<ll>> ways(1<<n);
  for (int i = 0; i < 1<<n; i++) {
    int p = __builtin_popcount(i);
    ways[i] = vector<ll>(n<<max(p-1,0));
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    //q.emplace(1<<i, 0, i);
    q.push(1<<i);
    ways[1<<i][0*n+i] = 1;
  }

  vector<int> qdone(1<<n);
  while (q.size()) {
    int done = q.front();
    q.pop();
    int pop = __builtin_popcount(done);
    for (int path = 0; path < 1<<max(pop-1, 0); path++) {
      for (int p = 0; p < n; p++) {
	ll w0 = ways[done][path*n+p];
	for (int j = 0; j < n; j++) {
	  if (done>>j&1) continue;
	  int done_ = done|1<<j;
	  int path_ = path*2+adj[p][j];
	  ll&w = ways[done_][path_*n+j];
	  if (!qdone[done_]++)
	    q.emplace(done_);
	  w += w0;
	}
      }
    }
    //cout << done << ' ' << path << ' ' << p << ": " << ways[done][path][p] << endl;
    //cout << __builtin_popcount(done) << endl;
    //assert(ways[done][path][p]);
  }

  for (int i = 0; i < 1<<(n-1); i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++)
      sum += ways[(1<<n)-1][i*n+j];
    cout << sum << ' ';
  }
  cout << endl;
}