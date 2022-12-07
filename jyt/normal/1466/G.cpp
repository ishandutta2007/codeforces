#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define P 19260817
#define mod 1000000007
#define mod1 19990213
#define mod2 998244353
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,K,Cn,len[99],po[N],Sum[N][26],nex[N*10],ha1[N*20],ha2[N*20],ans;
char A[22][N*20],B[N],C[N*10];
int cal(int x) {x-=x<mod?0:mod;return x;}
int Pow(int x,int y) {int res=1;for(;y;x=(ll)x*x%mod,y>>=1) if(y&1) res=(ll)res*x%mod;return res;}
class HashTable
{
#define M 666073
public:
	int ecnt,last[M+5];
	struct road{int to,v,w,nex;}e[N*20];
	void insert(int x,int v,int w) {e[++ecnt]=(road){x,v,w,last[v%M]},last[v%M]=ecnt;}
	bool find(int x,int v,int w)
	{
		if(!v&&!w) return 1;
		for(int k=last[v%M];k;k=e[k].nex) if(e[k].to<=x&&e[k].v==v&&e[k].w==w) return 1;
		return 0;
	}
}mp[2];
int main()
{
	scanf("%d%d%s%s",&n,&m,A[0]+1,B+1),len[0]=strlen(A[0]+1),po[0]=1;
	for(int i=1;i<=n;i++) po[i]=cal(po[i-1]+po[i-1]);
	for(int i=1;len[i-1]<1e6;i++)
	{
		len[i]=len[i-1]<<1|1,A[i][len[i-1]+1]=B[i];
		for(int j=1;j<=len[i-1];j++) A[i][j]=A[i][j+len[i-1]+1]=A[i-1][j];
	}
	for(int i=1;i<=len[0];i++)
	{
		ha1[i]=((ll)ha1[i-1]*P+A[0][i])%mod1;
		ha2[i]=((ll)ha2[i-1]*P+A[0][i])%mod2;
		mp[0].insert(0,ha1[i],ha2[i]);
	}
	for(int i=len[0],h1,h2,v1=P,v2=P;i;v1=(ll)v1*P%mod1,v2=(ll)v2*P%mod2,i--)
	{
		h1=(ha1[len[0]]-(ll)ha1[i-1]*v1%mod1+mod1)%mod1;
		h2=(ha2[len[0]]-(ll)ha2[i-1]*v2%mod2+mod2)%mod2;
		mp[1].insert(0,h1,h2);
	}
	for(int i=1,v1,v2;len[i-1]<1e6;i++)
	{
		for(int j=len[i-1]+1;j<=len[i];j++)
		{
			ha1[j]=((ll)ha1[j-1]*P+A[i][j])%mod1;
			ha2[j]=((ll)ha2[j-1]*P+A[i][j])%mod2;
			mp[0].insert(i,ha1[j],ha2[j]);
		}
		v1=v2=P;
		for(int j=1;j<=len[i-1];j++) v1=(ll)v1*P%mod1,v2=(ll)v2*P%mod2;
		for(int j=len[i-1]+1,h1,h2;j;v1=(ll)v1*P%mod1,v2=(ll)v2*P%mod2,j--)
		{
			h1=(ha1[len[i]]-(ll)ha1[j-1]*v1%mod1+mod1)%mod1;
			h2=(ha2[len[i]]-(ll)ha2[j-1]*v2%mod2+mod2)%mod2;
			mp[1].insert(i,h1,h2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++) Sum[i][j]=Sum[i-1][j];
		Sum[i][B[i]-97]=cal(Sum[i][B[i]-97]+po[n-i]);
	}
	for(int id;m--;printf("%d\n",ans),ans=0)
	{
		scanf("%d%s",&K,C+1),Cn=strlen(C+1);
		for(int i=2,j=0;i<=Cn;i++)
		{
			for(;j&&C[j+1]^C[i];j=nex[j]);
			if(C[j+1]==C[i]) j++;
			nex[i]=j;
		}
		for(id=0;len[id]<Cn&&id<K;id++);
		for(int i=1,j=0;i<=len[id];i++)
		{
			for(;j&&A[id][i]^C[j+1];j=nex[j]);
			if(A[id][i]==C[j+1]) j++;
			if(j==Cn) ans++,j=nex[j];
		}
		ans=(ll)ans*po[K-id]%mod;
		if(id==K) continue;
		for(int i=1;i<=Cn;i++)
			ha1[i]=((ll)ha1[i-1]*P+C[i])%mod1,ha2[i]=((ll)ha2[i-1]*P+C[i])%mod2;
		for(int i=Cn,h1,h2,v1=1,v2=1;i;v1=(ll)v1*P%mod1,v2=(ll)v2*P%mod2,i--)
		{
			h1=(ha1[Cn]-(ll)ha1[i]*v1%mod1+mod1)%mod1;
			h2=(ha2[Cn]-(ll)ha2[i]*v2%mod2+mod2)%mod2;
			if(mp[1].find(id,ha1[i-1],ha2[i-1])&&mp[0].find(id,h1,h2))
				ans=(ans+(ll)(Sum[K][C[i]-97]-Sum[id][C[i]-97]+mod)*Pow(po[n-K],mod-2))%mod;
		}
	}
	return 0;
}