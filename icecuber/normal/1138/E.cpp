#include <bits/stdc++.h>
using namespace std;

vector<int> node[100000], rnode[100000];

int done0[100000];
int topo[100000], topoi = 0;
void dfs0(int p) {
  if (done0[p]++) return;
  for (int i : node[p])
    dfs0(i);
  topo[topoi++] = p;
}

int component[100000], componenti = 1;
vector<int> clist[100001];
void dfs1(int p) {
  if (component[p]) return;
  component[p] = componenti;
  clist[componenti].push_back(p);
  for (int i : rnode[p])
    dfs1(i);
}

int D;
int done2[100000][50];
void dfs2(int p, int d) {
  if (done2[p][d]++) return;
  for (int i : node[p])
    if (component[i] == component[p])
      dfs2(i,(d+1)%D);
}

int dp[100001][50];
int reach[100000][50];
string open[100000];
int dist[100000];
int cycle[100001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m >> D;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    rnode[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cin >> open[i];
    for (char&c : open[i])
      c -= '0';
  }

  for (int i = 0; i < n; i++)
    dfs0(i);
  for (int i = n-1; i >= 0; i--) {
    int p = topo[i];
    if (component[p]) continue;
    dfs1(p);
    componenti++;

    dfs2(p,0);
    cycle[component[p]] = D;
    for (int i = D-1; i; i--)
      if (done2[p][i]) cycle[component[p]] = i;

    int oks[50] = {};
    for (int j : clist[component[p]]) {
      //cout << j+1 << ": ";
      for (int k = 0; k < D; k++) {
	//cout << done2[j][k] << ' ';
	int ok = 0;
	for (int l = 0; l < D; l++)
	  if (done2[j][l] && open[j][(l+k)%D]) ok = 1;
	oks[k] += ok;
      }
      //cout << endl;
    }
    //for (int i = 0; i < D; i++) cout << oks[i] << ' ';
    //cout << endl;
    for (int j : clist[component[p]]) {
      dist[j] = 0;
      while (!done2[j][dist[j]]) dist[j]++;
      for (int k = 0; k < D; k++)
	reach[j][k] = oks[(k+D-dist[j])%D];
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << i+1 << ": ";
    for (int j = 0; j < D; j++)
      cout << reach[i][j];
    cout << endl;
  }
  */
  for (int i = 0; i < componenti; i++)
    for (int j = 0; j < D; j++)
      dp[i][j] = -1e9;
  int c0 = component[0];
  dp[c0][(D-dist[0])%D] = 0;

  int ans = 0, cp = 0;
  for (int i = n-1; i >= 0; i--) {
    int p = topo[i];
    if (component[p] <= cp) continue;
    cp = component[p];

    int c = cycle[cp];
    for (int j = 0; j < c; j++) {
      int ma = -1e9;
      for (int i = j; i < D; i += c)
	ma = max(ma, dp[cp][i]);
      for (int i = j; i < D; i += c)
	dp[cp][i] = ma;
    }

    /*for (int p : clist[cp])
      cout << p+1 << ' ';
    cout << ":";
    for (int j = 0; j < D; j++)
      cout << ' ' << (dp[cp][j] < 0 ? -1 : dp[cp][j]);
      cout << endl;*/

    for (int p : clist[cp]) {
      for (int d = 0; d < D; d++) {
	int base = dp[cp][(d-dist[p]+D)%D];
	ans = max(ans, reach[p][d]+base);
	int d_ = (d+1)%D;
	for (int i : node[p]) {
	  if (cp != component[i]) {
	    int&dp_ = dp[component[i]][(d_+D-dist[i])%D];
	    dp_ = max(dp_, base+reach[p][d]);
	  }
	}
      }
    }
  }
  cout << ans << endl;
}