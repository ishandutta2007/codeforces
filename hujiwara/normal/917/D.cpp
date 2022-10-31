#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}

int n;
vector<vector<int> > e;
long long dp[110][110][110]={0};
int sz[110];

const int MSIZE=110;
long long inv[MSIZE],F[MSIZE],iF[MSIZE];

void prev(int N)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=iF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    iF[i]=iF[i-1]*inv[i]%mod;
  }
}

long long Ch(int i,int j)
{
  return F[i]*iF[j]%mod*iF[i-j]%mod;
}


void dfs(int i,int p)
{
  sz[i]=1;
  dp[i][0][0]=1ll;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs(j,i);
    long long temp[110][110]={0};
    for(int a=0;a<sz[i];a++){
      for(int b=0;b<sz[i];b++){
	for(int c=0;c<sz[j];c++){
	  for(int d=0;d<sz[j];d++){
	    ad(temp[a][b+d],dp[i][a][b]*dp[j][c][d]%mod*(c+1)%mod*n%mod);
	    ad(temp[a+c+1][b+d+1],dp[i][a][b]*dp[j][c][d]%mod);
	  }
	}
      }
    }
    sz[i]+=sz[j];
    for(int a=0;a<sz[i];a++){
      for(int b=0;b<sz[i];b++){
	dp[i][a][b]=temp[a][b];
      }
    }
  }
}

int main()
{
  scanf("%d",&n);
  e=vector<vector<int> >(n);
  for(int t=0;t<n-1;t++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(0,-1);
  /*for(int i=0;i<n;i++){
    for(int a=0;a<sz[i];a++){
      for(int b=0;b<sz[i];b++){
	printf("%d %d %d %lld\n",i,a,b,dp[i][a][b]);
      }
    }
    }*/
  long long ans[110];
  prev(n+5);
  long long rn=inv[n];
  for(int i=0;i<n;i++){
    ans[i]=0;
    for(int j=0;j<n;j++){
      ad(ans[i],dp[0][j][i]*(j+1)%mod);
    }
    ml(ans[i],rn);
  }
  for(int i=n-1;i>=0;i--){
    for(int j=i+1;j<n;j++){
      mn(ans[i],ans[j]*Ch(j,i)%mod);
    }
  }
  for(int i=0;i<n;i++){
    printf("%lld%c",ans[i],i<n-1?' ':'\n');
  }
  return 0;
}