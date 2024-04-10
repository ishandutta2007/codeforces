#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1e5+10,P=998851111,B=802051111;
int n,H[maxn],pw[maxn],pre[maxn][26],ok[16][maxn];char S[maxn];ll bk[maxn],val[maxn][26];
int ask(int l,int r){return(H[r]+1ll*(P-H[l-1])*pw[r-l+1])%P;}

int main(){
  scanf("%s",S+1),n=strlen(S+1),pw[0]=1;ll sum=n,ans=0;
  rep(i,1,n)H[i]=(1ll*B*H[i-1]+S[i])%P,pw[i]=1ll*B*pw[i-1]%P,memcpy(pre[i],pre[i-1],104),pre[i][S[i]-'a']++,ok[0][i]=1;
  rep(i,1,15)rep(j,1,n){
    int s=(1<<i)-1;
    if(j<=s||j+s>n)continue;
    int l=j-(s+1)/2,r=j+(s+1)/2;ll t=1ll*(s*2+1)*(s*2+1);
    int o=pre[j+s][S[j]-'a']-pre[j-s-1][S[j]-'a'];
    bool f1=ask(j-s,j-1)==ask(j+1,j+s),p=ok[i-1][l],q=ok[i-1][r];
    if(f1&&p&&q){
      rep(c,0,25)if(pre[j+s][c]==pre[j-s-1][c])val[j][c]+=t;
      if(o==1)ok[i][j]=1,sum+=t,bk[j-s]+=t,bk[j+s+1]-=t;
    }else if(!f1){
      int lp=0,le=s;
      while(lp<le){
        int mid=(lp+le+1)/2;
        ask(j-s,j-s+mid-1)==ask(j+1,j+mid)?lp=mid:le=mid-1;
      }
      int x=j-s+le,y=j+le+1;
      if(ask(x+1,j-1)==ask(y+1,j+s)&&o<=2){
        if((o==1||S[x]==S[j])&&q)val[x][S[y]-'a']+=t;
        if((o==1||S[y]==S[j])&&p)val[y][S[x]-'a']+=t;
      }
    }
  }
  rep(i,1,n){
    bk[i]+=bk[i-1];
    rep(c,0,25)if(c!=S[i]-'a')ans=max(ans,sum-bk[i]+val[i][c]);
  }
  cout<<ans<<endl;
  return 0;
}