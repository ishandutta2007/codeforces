#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

vector<pii > adj[100005];
int vs[100005];
int vs2[100005];
priority_queue<pii, vector<pii>, greater<pii> > qq[100005];
int dp[10][100005];
int vis[100005];
int prevv[10][100005];
int wutwut[100005];
int baru[100005];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  FOR(a,0,m-1) {
    int u,v,c;
    scanf("%d%d%d",&u,&v,&c);
    adj[u].pb(mp(v,c));
    adj[v].pb(mp(u,c));
  }
  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push(mp(0, n-1));
  FOR(a,0,n-1) {
    vs[a] = INF;
  }

  queue<int> q;
  q.push(n-1);
  vis[n-1] = 1;
  while(!q.empty()) {
    int u = q.front();
    if (vs[u] == INF) {
      pq.push(mp(0,u));
      vs[u] = 0;
    }
    q.pop();
    FOR(a,0,SIZE(adj[u])-1) {
      int v = adj[u][a].fi;
      int c = adj[u][a].se;
      if (c == 0 && !vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }

  queue<pii> lol;
  lol.push(mp(0, 0));
  fill(vs2, vs2+n, INF);
  vs2[0] = 0;
  while(!lol.empty()) {
    int dist = lol.front().fi;
    int u = lol.front().se;
    lol.pop();
    FOR(a,0,SIZE(adj[u])-1) {
      int v = adj[u][a].fi;
      int c = adj[u][a].se;
      if (vs2[v] == INF) {
        vs2[v] = dist+1;
        lol.push(mp(vs2[v], v));
      }
    }
  }


  while(!pq.empty()) {
    int dist = pq.top().fi;
    int u = pq.top().se;
    pq.pop();
    if (vs[u] == dist) {
      FOR(a,0,SIZE(adj[u])-1) {
        int v = adj[u][a].fi;
        int c = adj[u][a].se;
        if (vs[v] > dist+1) {
          vs[v] = dist+1;
          pq.push(mp(vs[v], v));
        }
      }
    }
  }
  int mins = vs[0];
  fill(baru, baru+n, INF);
  q.push(n-1);
  baru[n-1] = 0;
  while(!q.empty()) {
    int u = q.front();
    //cout << "MEH " << u << endl;
    qq[0].push(mp(0,u));
    q.pop();
    FOR(a,0,SIZE(adj[u])-1) {
      int v = adj[u][a].fi;
      int c = adj[u][a].se;
      //cout << "J " << v << " " <<c << endl;
      if (c == 0 && baru[v] == INF) {
        //cout << "MASUK " << v << endl;
        baru[v] = baru[u]+1;
        wutwut[v] = u;
        q.push(v);
      }
    }
  }
  FOR(a,0,9) {
    FOR(b,0,n-1) {
      dp[a][b] = 0;
    }
  }
  FOR(a,0,n-1) {
  //  cout << a << " " << vs2[a] << endl;
  }
  //cout << "MINS " << mins << endl; 
  int it = 0;
  vector<int> jj;
  FOR(a,0,mins) {
    int yey = qq[a].top().fi;
    if (a > 0) {
      cout << yey;
      jj.pb(yey);
    }
    //cout << SIZE(qq[a]) << endl;
    vector<pii> clean;
    vector<pii> wut[10];

    while(!qq[a].empty() && qq[a].top().fi == yey) {
      int u = qq[a].top().se;
      //cout << "LEVEL " << a << " " << qq[a].top().fi << " " << u << endl;
      qq[a].pop();
            FOR(b,0,SIZE(adj[u])-1) {
        int v = adj[u][b].fi;
        int c = adj[u][b].se;
       // cout << "YO " << v << " " << c << " " << vs[v] << " " << vs2[u] << " " << dp[c][v] << endl;
        if (1+vs[u]+vs2[v] == mins && !dp[c][v]) {
          //cout << "MASUK " << endl;
          wut[c].pb(mp(v,u));
          /*
          if (a == 0) {
            dp[c][v] = 1;
            clean.pb(mp(c,v));
            prevv[c][v] = u;
            qq[a+1].push(mp(c, v));
          }
          */
        }
      }
    }
    int it = 0;
    while(wut[it].empty()) it++;

    int mins = INF;
    FOR(b,0,SIZE(wut[it])-1) {
      pii e = wut[it][b];
      MIN(mins, baru[e.se]);
    }
    FOR(b,0,SIZE(wut[it])-1) {
      pii e = wut[it][b];
      int v = e.fi;
      int u = e.se;
      int c = it;
      //cout << "YO " << a << " " << c << " " << v << " " << u << endl;
      if (a > 0 || baru[u] == mins) {
        dp[c][v] = 1;
        prevv[c][v] = u;
        qq[a+1].push(mp(c, v));
      }
    }

  }
  if (mins == 0) cout << 0;
  cout << endl;
  vector<int> path2;
  int cur = 0;
  while(!jj.empty()) {
    path2.pb(cur);
    cur = prevv[jj.back()][cur];
    jj.pop_back();
  }
  while(cur != n-1) {
    path2.pb(cur);
    cur = wutwut[cur];
  }
  path2.pb(n-1);
  printf("%d\n", SIZE(path2));
  FOR(a,0,SIZE(path2)-1) {
    printf("%d",path2[a]);
    if (a != SIZE(path2)-1) printf(" ");
    else printf("\n");
  }


}