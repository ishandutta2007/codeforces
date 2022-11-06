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
bool vis[1001010];
int opt,x,y,z,tag,len,n,Q,mu[1001010],prim[1001010];
bitset<7001> now,G1[7010],G2[7010],G[100010];
int i,j; 
int main()
{
	n=read();Q=read();
	mu[1]=1;
	for (i=2;i<=7000;i++){
		if (vis[i]==false){prim[++len]=i;mu[i]=-1;}
		for (j=1;j<=len&&i*prim[j]<=7000;j++){
		    vis[i*prim[j]]=true;mu[i*prim[j]]=mu[i]*mu[prim[j]];
		    if (i % prim[j]==0){
		    	mu[i*prim[j]]=0;break;
			}
		}
	}
	for (i=1;i<=7000;i++) mu[i]=abs(mu[i]);
	for (i=1;i<=7000;i++)
	  for (j=i;j<=7000;j+=i)
	      G1[i][j]=mu[j/i];
	for (i=1;i<=7000;i++)
	   for (j=i;j<=7000;j+=i)  
	       G2[j][i]=1;
	for (;Q;Q--){
		opt=read();
		if (opt==1) x=read(),y=read(),G[x]=G2[y];
		if (opt==2) x=read(),y=read(),z=read(),G[x]=G[y]^G[z];
		if (opt==3) x=read(),y=read(),z=read(),G[x]=G[y]&G[z];
		if (opt==4) x=read(),y=read(),now=G[x]&G1[y],tag=now.count() % 2,printf("%d",tag);
		}
	puts("");
return 0;
}