#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int P=1e9+7;
void Add(int&x,int y){
  x+=y-P,x+=x>>31&P;
}
int n,m,ans,sel,dp[2][2][2][155][155];ll kub[2][2][155][155];

int main(){
//  n=150,m=150;
  cin>>n>>m;
  rep(_,1,m){
    memset(kub,0,sizeof kub);
    memset(dp[sel],0,sizeof dp[sel]);
    rep(p,0,1)rep(q,0,1)rep(l,1,n)rep(r,l,n){
      int x=dp[sel^1][p][q][l][r];
      if(!x)continue;
      // i <= r || j >= l
      if(q){
        if(!p){
          rep(i,1,l){
            kub[p][q][l][i]+=x;
            kub[p][q][r+1][i]-=x;
          }
        }else{
          rep(i,l,r){
            kub[p][q][i][i]+=x;
            kub[p][q][r+1][i]-=x;
          }
        }
      }else{
        rep(i,1,r)if(((i<l)^p)||i==l){
          kub[p][q][r][i]+=x;
        }
      }
      if(!p){
        if(q){
          rep(i,l+1,r){
            kub[1][q][l][i]+=x;
            kub[1][q][r+1][i]-=x;
          }
        }else{
          rep(i,l+1,r){
            kub[1][q][r][i]+=x;
          }
        }
      }
      if(!q){
        rep(i,1,r)if(((i<l)^p)||i==l){
          kub[p][1][max(i,l)][i]+=x;
          kub[p][1][r][i]-=x;
        }
      }
      if(!p&&!q){
        rep(i,l+1,r){
          kub[1][1][i][i]+=x;
          kub[1][1][r][i]-=x;
        }
      }
    }
    rep(p,0,1)rep(q,0,1)rep(i,1,n){
      rep(j,1,n)kub[p][q][j][i]+=kub[p][q][j-1][i],Add(dp[sel][p][q][i][j],(kub[p][q][j][i]%P+P)%P);
    }
    rep(i,1,n)rep(j,i,n){
//      if(sel)rep(p,0,1)rep(q,0,1)printf("(%d %d %d %d) %d\n",i,j,p,q,dp[sel][i][j][p][q]);
      Add(dp[sel][0][0][i][j],1);
      rep(p,0,1)rep(q,0,1)Add(ans,dp[sel][p][q][i][j]);
    }
    sel^=1;
  }
  cout<<ans<<endl;
  return 0;
}