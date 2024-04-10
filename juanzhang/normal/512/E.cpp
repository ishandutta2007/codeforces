#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
typedef vector<pii>vi;
const int maxn=1010;
int n,E[maxn][maxn];

vi solve(int chk){
  memset(E,0,sizeof E);
  rep(i,1,n-3){
    int u,v;cin>>u>>v,E[u][v]=E[v][u]=1;
  }
  rep(i,1,n)E[i][i%n+1]=E[i%n+1][i]=1;
  vi res;
  rep(i,2,n-1){
    int j=i+1;
    while(j<=n&&!E[1][j])j++;
//    printf("#%d : %d %d\n",chk,i,j);
    if(j==i+1||j>n)continue;
    assert(E[i][j]);
    E[i][j]=E[j][i]=0;
    int x=-1;
    rep(k,i+1,j-1)if(E[k][i]&&E[j][k])x=k;
//    printf("!%d\n",x);
    E[1][x]=E[x][1]=1;
    res.push_back(!chk?pii{i,j}:pii{1,x});
    i--;
  }
  return res;
}

int main(){
  cin>>n;
  vi lef=solve(0);
  vi rig=solve(1);
  cout<<lef.size()+rig.size()<<endl;
  for(pii p:lef)printf("%d %d\n",p.first,p.second);
  per(i,rig.size()-1,0)printf("%d %d\n",rig[i].first,rig[i].second);
  return 0;
}