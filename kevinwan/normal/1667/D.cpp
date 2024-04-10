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
const int mn = 5e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

vi g[mn];
bool good[mn][2];
vi res[mn][2];

void dfs(int x,int p){
  vi gr[4];
  for(int y:g[x])if(y!=p){
    dfs(y,x);
    int val=good[y][0]+good[y][1]*2;
    gr[val].push_back(y);
  }
  int cur[4];
  for(int pt=0;pt<2;pt++){
    memset(cur,0,sizeof(cur));
    vi ans;
    gr[1<<pt].push_back(p);
    bool ok=1;
    for(int i=g[x].size();i>0;i--){
      int des=1<<(i%2);
      if(cur[des]!=gr[des].size()){
        ans.push_back(gr[des][cur[des]++]);
      }
      else if(cur[3]!=gr[3].size()){
        ans.push_back(gr[3][cur[3]++]);
      }
      else ok=0;
    }
    if(ok){
      good[x][pt]=1;
      res[x][pt]=ans;
    }
    gr[1<<pt].pop_back();
  }
}

void dfs2(int x,int p, int pt){
  bool ct=(g[x].size()%2);
  for(int y:res[x][pt]){
    if(y!=p){
      dfs2(y,x,ct);
    }
    else {
      printf("%d %d\n",x,p);
    }
    ct^=1;
  }
}

void solve(){
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)g[i].clear(),good[i][0]=good[i][1]=0,res[i][0].clear(),res[i][1].clear();
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=1;i<=n;i++)if(g[i].size()==1){
    dfs(g[i][0],i);
    if(!good[g[i][0]][1]){
      printf("NO\n");
      return;
    }
    printf("YES\n");
    dfs2(g[i][0],i, 1);
    break;
  }

}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  cin >> tc;
  while(tc--){
    solve();
  }
}