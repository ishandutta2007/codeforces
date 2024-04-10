#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod=1e9+7;

const int mn=110;
bool eq[mn][mn][mn];
vector<int> g[mn][mn];
int n;

bool vis[mn];
vi res[mn];
bool fail;
void dfs(int x, int p) {
  vis[x]=1;
  for(int y:g[x][p]){
    if(vis[y]){fail=1;return;}
    res[x].push_back(y);
    res[y].push_back(x);
    dfs(y,x);
    if(fail)return;
  }
}
int d[mn];
void dfs2(int x,int p){
  for(int y:res[x])if(y!=p){
    d[y]=d[x]+1;
    dfs2(y,x);
  }
}


bool check(int a,int b) {
  for(int i=1;i<=n;i++)vis[i]=0,res[i].clear();
  fail = 0;
  res[a].push_back(b);
  res[b].push_back(a);
  dfs(a,b);
  if(vis[b])return 0;
  dfs(b,a);
  if(fail)return 0;
  for(int i=1;i<=n;i++)if(!vis[i])return 0;
  for(int i=1;i<=n;i++){
    d[i]=0;
    dfs2(i,-1);
    for(int j=1;j<=n;j++)for(int k=j+1;k<=n;k++){
      if(eq[i][j][k]!=(d[j]==d[k])){
        return 0;
      }
    }
  }
  printf("Yes\n");
  for(int i=1;i<=n;i++){
    for(int j:res[i])if(i<j){
      printf("%d %d\n",i,j);
    }
  }
  return 1;
}

void solve() {
  
  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++)eq[i][j][k]=0;
      g[i][j].clear();
    }
    res[i].clear();
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
      string s;
      cin >> s;
      for(int k=0;k<n;k++)if(s[k]=='1'){
        eq[k+1][i][i+j]=eq[k+1][i+j][i]=1;
        g[k+1][i].push_back(i+j);
        g[k+1][i+j].push_back(i);
      }
    }
  }
  int num=0;
  for(int i=2;i<=n;i++)if(check(1,i))return;
  printf("No\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--)solve();
}