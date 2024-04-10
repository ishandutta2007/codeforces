#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long tem[10010],x,y,z1,z2,rt,id,n,i,ans,j,inv[1001010],final[1001010],V[1001010],len,prim[1001010],fre[1001010],cnt,a[1001010],b[1001010],c1[1001010],c2[1001010],d[1001010],MOD,depp[1001010];
bool vis[1001010];
double dep[1001010],mx,val[1001010];
void add(int x,int y,int z1,int z2){
	cnt++;a[cnt]=y;b[cnt]=d[x];c1[cnt]=z1;c2[cnt]=z2;d[x]=cnt;
}
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % MOD;
	return ans;
}
void back(int x,int fa){
	long long G;
	for (int i=d[x];i;i=b[i])
	     if (a[i]!=fa){
	     	G=c1[i];
	     	for (int j=1;j<=len;j++)
	     	    while (G % prim[j]==0) {V[prim[j]]++;G/=prim[j];}int w=0;
	     	if (G!=1) V[G]++,tem[++w]=G;
	        G=c2[i];
	        for (int j=1;j<=len;j++)
	            while (G % prim[j]==0) V[prim[j]]--,final[prim[j]]=max(final[prim[j]],-V[prim[j]]),G/=prim[j];
	        
	       if (G!=1) V[G]--,final[G]=max(final[G],-V[G]),tem[++w]=G;
		  back(a[i],x);
		  G=c1[i];
	     	for (int j=1;j<=len;j++)
	     	    while (G % prim[j]==0) V[prim[j]]--,G/=prim[j];
	     	if (G!=1) V[G]--;
	        G=c2[i];
	        for (int j=1;j<=len;j++)
	            while (G % prim[j]==0) V[prim[j]]++,G/=prim[j];
	        if (G!=1) V[G]++;
		 }
}
void solve(int x,int fa,long long now){
	ans=(ans+now) % MOD;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	       solve(a[i],x,now*c1[i] % MOD*pow(c2[i],MOD-2,MOD) % MOD);
}
void Main(){
    n=read();MOD=998244353;
    cnt=0;
    for (i=1;i<=n;i++) dep[i]=0,final[i]=0,depp[i]=1,V[i]=0,c1[i]=c2[i]=0,d[i]=0,vis[i]=false;len=0;
    for (i=2;i<=sqrt(n);i++)
         {
         	if (vis[i]==false) prim[++len]=i;
         	for (j=1;j<=len&&i*prim[j]<=(sqrt(n));j++){
         		vis[i*prim[j]]=true;
         		if (i % prim[j]==0) break;
			 }
		 }
    for (i=2;i<=n;i++) val[i]=log(i),inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
    for (i=1;i<n;i++){
    	x=read();y=read();z1=read();z2=read();
    	add(x,y,z2,z1);add(y,x,z1,z2);
	}
    back(1,0);rt=1;
    for (i=1;i<=n;i++) rt=rt*pow(i,final[i],MOD) % MOD;ans=0;
    solve(1,0,rt);
    printf("%lld\n",ans);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}