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
#define MOD 1000000007
vector<int> factor[1001010];
vector<pair<int,int>> Ask[1001010];
long long tot,a[1001010][10];
int id,Answer[1001010],dif,Q,l,r,V[1001010],b[1001010],pre[1001010][10];
long long i,j,x,E1[1001010],E2[1001010],n,mul[1001010],inv[1001010];
bool vis[1001001];
void modifypre(int x,long long y){for (;x<=n;x+=x&-x) E1[x]=E1[x]*y % MOD;}
void modifysuf(int x,long long y){for (;x;x-=x&-x) E2[x]=E2[x]*y % MOD;}
long long querypre(int x){long long ans=1;for (;x;x-=x&-x) ans=ans*E1[x] % MOD;return ans;}
long long querysuf(int x){long long ans=1;for (;x<=n;x+=x&-x) ans=ans*E2[x] % MOD;return ans;}
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % p;return ans;
}
int main()
{
	n=read();
    inv[1]=1;mul[0]=1;
    for (i=2;i<=1000000;i++) inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
	for (i=2;i<=1000000;i++)
	     if (vis[i]==false)
	        for (j=1;j<=1000000/i;j++)
	            vis[i*j]=true,factor[i*j].push_back(i);
	for (i=1;i<=n;i++){
		x=read();
		for (j=0;j<factor[x].size();j++) {
			a[i][++b[i]]=(1-inv[factor[x][j]]+MOD) % MOD;
			pre[i][b[i]]=V[factor[x][j]];
			V[factor[x][j]]=i;
		}
		mul[i]=mul[i-1]*x % MOD;
	}
	Q=read();
	for (i=1;i<=Q;i++) l=read(),r=read(),Ask[r].push_back(make_pair(l,i));
	for (i=1;i<=n;i++) E1[i]=E2[i]=1;tot=1;
	for (r=1;r<=n;r++){
		for (i=1;i<=b[r];i++) modifypre(r,a[r][i]),modifysuf(pre[r][i],a[r][i]),tot=tot*a[r][i] % MOD;
		for (i=0;i<Ask[r].size();i++){
			l=Ask[r][i].first;id=Ask[r][i].second;
			dif=querypre(l-1)*querysuf(l) % MOD;
			dif=tot*pow(dif,MOD-2,MOD) % MOD;
			Answer[id]=mul[r]*pow(mul[l-1],MOD-2,MOD) % MOD*dif % MOD;
		}
	}
	for (i=1;i<=Q;i++) printf("%lld\n",Answer[i]);
return 0;
}
/*
 
log
l<=i<=r&&pre[i]<l  

r
ii>=l&&pre[i]<l
i<l||pre[i]>=l
 

 
*/