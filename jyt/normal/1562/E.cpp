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
#define N 5005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,f[N][N],ST[N][15],Log[N],ans;
char s[N];
class SuffixArray
{
	int cnt,Max,Sum[N],tp[N<<1];//tp2nRE
	void Rsort()
	{
		for(int i=1;i<=Max;i++) Sum[i]=0;
		for(int i=1;i<=n;i++) Sum[Rank[tp[i]]]++;
		for(int i=1;i<=Max;i++) Sum[i]+=Sum[i-1];
		for(int i=n;i;i--) sa[Sum[Rank[tp[i]]]--]=tp[i];
	}
public:
	int sa[N],Rank[N],h[N];
	void build()
	{
		for(int i=1;i<=n;i++) tp[i]=i,Max=max(Max,Rank[i]=s[i]);
		Rsort();
		if(n==1) return;
		for(int j=1;cnt<n;Max=cnt,j<<=1)
		{
			cnt=0;
			for(int i=n-j+1;i<=n;i++) tp[++cnt]=i;
			for(int i=1;i<=n;i++) if(sa[i]>j) tp[++cnt]=sa[i]-j;
			Rsort();
			for(int i=1;i<=n;i++) std::swap(Rank[i],tp[i]);
			Rank[sa[cnt=1]]=1;
			for(int i=2;i<=n;i++)
			{
				if(tp[sa[i]]^tp[sa[i-1]]||tp[sa[i]+j]^tp[sa[i-1]+j]) cnt++;
				Rank[sa[i]]=cnt;
			}
		}
		for(int i=1,tmp=0;i<=n;i++)
		{
			for(tmp?tmp--:0;Rank[i]<n&&s[sa[Rank[i]+1]+tmp]==s[i+tmp];tmp++);
			h[Rank[i]]=tmp;
		}
	}
	void clear()
	{
		for(int i=1;i<=n;i++) tp[i]=Rank[i]=0;
		Max=cnt=0;
	}
}SA;
int asklcp(int x,int y)
{
	x=SA.Rank[x],y=SA.Rank[y];
	if(x>y) std::swap(x,y);
	y--;int t=Log[y-x+1];
	return min(ST[x][t],ST[y-(1<<t)+1][t]);
}
void clear()
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) f[i][j]=0;
	ans=0,SA.clear();
}
int main()
{
	for(int i=2;i<=N-5;i++) Log[i]=Log[i>>1]+1;
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%s",&n,s+1),SA.build();
		for(int i=1;i<=n;i++) ST[i][0]=SA.h[i];
		for(int j=1;j<15;j++)
			for(int i=1;i+(1<<j)-1<=n;i++) ST[i][j]=min(ST[i][j-1],ST[i+(1<<j-1)][j-1]);
		for(int i=1,v,l;i<=n;i++)
		{
			v=0;
			for(int j=1;j<i;j++) if(s[j]<s[i]) v=max(v,f[j][n]);
			for(int j=i;j<=n;j++) f[i][j]=v+j-i+1;
			for(int j=1;j<i;j++)
				if(s[j]==s[i])
				{
					l=asklcp(j,i);
					if(i+l<=n&&s[i+l]>s[j+l]) f[i][i+l]=max(f[i][i+l],f[j][n]+1);
				}
			for(int j=i;j<=n;j++)
				f[i][j]=max(f[i][j],f[i][j-1]+1),ans=max(ans,f[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}