#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, s;
int a[100005];
vector<int> E[100005];

int dist[105][100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> k >> s;
  FOR(i,1,n+1) cin >> a[i];
  REP(i,m){int x, y; cin >> x >> y; E[x].pb(y); E[y].pb(x);}

  FOR(t,1,k+1){
    queue<int> Q;
    FOR(i,1,n+1)
      if (a[i] == t) Q.push(i), dist[t][i] = 0;
      else dist[t][i] = 1e9;
    while (!Q.empty()){
      int id = Q.front(); Q.pop();
      for (auto nxt : E[id])
	if (dist[t][nxt] > dist[t][id] + 1)
	  dist[t][nxt] = dist[t][id] + 1, Q.push(nxt);
    }
  }

  FOR(i,1,n+1){
    vector<int> all;
    FOR(j,1,k+1) all.pb(dist[j][i]);
    sort(all.begin(), all.end());
    int sum = 0;
    REP(j,s) sum += all[j];
    cout << sum << " ";
  } cout << endl;

  return 0;
}