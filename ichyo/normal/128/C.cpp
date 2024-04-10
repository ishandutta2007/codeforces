#include<cstdio>

#define MOD ((int)(1e9+7))
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int n,m,k;
ll d[1001][1001];
ll rec(int x,int cnt){
  if(x-cnt*2<0)return 0;
  if(cnt==0)return 1;
  if(d[x][cnt]>-1)return d[x][cnt];

  ll ans=0;
  REP(i,x-2){
    ans+=((x-2-i)*rec(i+1,cnt-1))%MOD;
  }
  return d[x][cnt] = ans%MOD;
}

int main(){
  scanf("%d%d%d",&n,&m,&k);
  REP(i,1001)REP(j,1001)d[i][j]=-1;
  printf("%lld\n",rec(m,k)*rec(n,k)%MOD);
}