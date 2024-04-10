#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mn = 1e5+10;
vi g[mn];
int ans[mn];
void dfs(int x,int p, int sgn){
  ans[x]=sgn*sz(g[x]);
  for(int y:g[x])if(y!=p)dfs(y,x,sgn*-1);
}
void solve() {
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)g[i].clear();
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,-1, 1);
  for(int i=1;i<=n;i++)printf("%d ", ans[i]);
  printf("\n");
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin>>tc;
  while(tc--){
    solve();
  }
}