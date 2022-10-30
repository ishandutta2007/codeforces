#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

namespace IO {
const int MAXSIZE = 1 << 22;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) {
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x;
}
}using namespace IO;

int n,t,a[500501][3],pre[500501],st[500501],ed[500501],x,m,l,dp[500501],sum[500501],tmp,sb=1;
ll ans=1;

int main(){
	register int i,j,k;
	dp[0]=sum[0]=1;
	
	n=rd();x=rd();m=rd();
	for(i=1;i<=m;i++){
		a[i][1]=rd();a[i][2]=rd();a[i][0]=rd();
	}
	for(k=0;k<x;k++,sb<<=1){
		memset(pre,0,sizeof(int)*n+10);
		
		for(i=1;i<=m;i++){
			if(sb&a[i][0]){st[a[i][1]]++;ed[a[i][2]]++;}
			else{
				if(pre[a[i][2]]==0){pre[a[i][2]]=a[i][1];}
				else{pre[a[i][2]]=max(pre[a[i][2]],a[i][1]);}
			}
		}
		tmp=0;l=0;
		for(i=1;i<=n;i++){
			tmp+=st[i];
			dp[i]=sum[i-1]-((l==0)?0:sum[l-1]);dp[i]%=M;
			if(tmp){dp[i]=0;}
			sum[i]=(sum[i-1]+dp[i])%M;
			if(pre[i]>l){l=pre[i];}
			tmp-=ed[i];st[i]=ed[i]=0;
		}
		ans=ans*((sum[n]%M-((l==0)?0:sum[l-1]%M))%M+M)%M;
	}
	printf("%lld\n",(ans+M)%M);
}