/*#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")*/
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
long long pow(long long x,long long y,long long p)
{
    long long ans=1;
    for (;y;y>>=1,x=x*x % p)
        if (y&1) ans=ans*x % p;
    return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	return gcd(y,x % y);
}
long long random(long long x)
{
	return ((rand()*rand()) % x+1);
}
vector<int> edge[1001010];
long long xx,lg[1001010],de,n,MOD,i,e[1001010],x,y,dep[1001010],t,w,f1[1001010],T[1001010],val[1001010][21],fa[1001010][21],lst,j,fat[1001010],ans;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();MOD=1e9+7;
	for (i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for (i=1;i<=n;i++) e[i]=read();
	for (i=1;i<n;i++)
	     {
	     x=read();y=read();edge[x].push_back(y);edge[y].push_back(x);
		 }
	for (i=1;i<=n;i++) dep[i]=1e9;
	t=1;w=1;f1[1]=1;dep[1]=0;T[1]=e[1];
	while (t<=w)
	     {
	     	x=f1[t];
	     	for (i=0;i<edge[x].size();i++)
	     	      {
	     	      	y=edge[x][i];
	     	      	if (dep[y]>dep[x]+1)
	     	      	     {
	     	      	     	dep[y]=dep[x]+1;fa[y][0]=x;val[y][0]=e[x];
	     	      	     	T[y]=gcd(T[x],e[y]);
	     	      	     	for (j=1;j<=20;j++)
	     	      	     	    {
	     	      	     	    	fa[y][j]=fa[fa[y][j-1]][j-1];
	     	      	     	    	val[y][j]=gcd(val[y][j-1],val[fa[y][j-1]][j-1]);
									}
							fat[y]=x;
							w++;f1[w]=y;
							}
				   }
	     	t++;
		 }
	ans=e[1];
	for (i=2;i<=n;i++)
	    {
			x=e[i];
			for (j=i;j;j=j)
			    {
			    	lst=j;
			    	for (de=lg[j];de>=0;de--)
			    	    if (fa[j][de]!=0)
			    	          {
			    	          	if ((x==0)&&(val[j][de]!=0)) continue;
			    	          	if (val[j][de]%x!=0) continue;
						      j=fa[j][de];
						      }
					ans=(ans+(dep[lst]-dep[j]+1)*(x % MOD)) % MOD;
					j=fat[j];
					if (j==0) break;
					x=gcd(x,e[j]);  
				}
		}
    printf("%lld\n",ans);
    return 0;
}