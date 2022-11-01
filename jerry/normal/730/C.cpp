#include <bits/stdc++.h>
using namespace std;

#define D(x...) fprintf(stderr,x)
#define D(x...)

typedef long long ll;
typedef pair<ll,ll> pll;

const int MAX_N = 5005;

int N, M;
vector<int> edges[MAX_N];
int dist[MAX_N][MAX_N];

int T;
int seen[MAX_N];

int W;
pair<pll, int> store[MAX_N];

int main() {
  scanf("%d %d",&N,&M);

  for(int i=0;i<M;i++) {
    int x, y;
    scanf("%d %d",&x,&y);
    x--;
    y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      dist[i][j] = MAX_N;
    }

    T++;
    queue<int> q;
    q.push(i);
    seen[i] = T;
    dist[i][i] = 0;

    while(!q.empty()) {
      int u = q.front();
      q.pop();

      D("dist[%d][%d] = %d\n",i,u,dist[i][u]);

      for(auto v: edges[u]) {
        if(seen[v] != T) {
          seen[v] = T;
          dist[i][v] = dist[i][u] + 1;
          q.push(v);
        }
      }
    }
  }

  scanf("%d",&W);
  for(int i=0;i<W;i++) {
    scanf("%d %lld %lld",&store[i].second,&store[i].first.second,&store[i].first.first);
    store[i].second--;
  }
  sort(store, store+W);

  for(int i=0;i<W;i++) {
    D("store %d: cost=%lld, num=%lld, at=%d\n",i,store[i].first.first,store[i].first.second,store[i].second);
  }

  int Q;
  scanf("%d",&Q);

  for(int i=0;i<Q;i++) {
    int g;
    ll num;
    ll cost;
    scanf("%d %lld %lld",&g,&num,&cost);
    g--;

    int lo = 0;
    int hi = MAX_N;
    int ans = MAX_N;
    while(lo <= hi) {
      int mid = (lo+hi)/2;

      // perform check
      ll tot = num;
      ll tc = 0;
      for(int s=0;s<W;s++) {
        if(dist[g][store[s].second] <= mid) {
          ll p = min(store[s].first.second, tot);
          tc += p * store[s].first.first;
          tot -= p;
        }
      }

      D("mid = %d, tot = %lld, tc =%lld\n",mid,tot,tc);

      if(tot == 0 && tc <= cost) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if(ans < MAX_N) {
      printf("%d\n",ans);
    } else {
      printf("-1\n");
    }
  }

  return 0;
}