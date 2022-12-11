#include<unordered_map>
#include<unordered_set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=252;
const int seed=181;
const int mod=1e9+7;

int n,m;
char str[maxn][maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)scanf("%s",str[i]+1);
}

int num[maxn][26],hs[maxn];
int p[26];
int odd[maxn];
int S[maxn<<1];
int f[maxn<<1];

ll ans;

inline void doing()
{
	p[0]=1; REP(i,1,25)p[i]=(ll)p[i-1]*seed%mod;
	REP(i,0,n)S[i<<1]=-1;
	REP(l,1,m)
	{
		REP(i,1,n)REP(j,0,25)num[i][j]=0;
		REP(i,1,n)odd[i]=0,hs[i]=0;
		REP(r,l,m)
		{
			REP(i,1,n)
			{
				num[i][str[i][r]-'a']++;
				if(num[i][str[i][r]-'a']&1)odd[i]++;
				else odd[i]--;
				hs[i]=(hs[i]+p[str[i][r]-'a'])%mod;
			}
			REP(i,1,n)
			{
				if(odd[i]<=1)S[(i<<1)-1]=hs[i];
				else S[(i<<1)-1]=-i-1;
			}

			int mx=-1,id=-1;
			REP(i,0,n<<1)
			{
				if(mx>=i)f[i]=min(f[id*2-i],mx-i+1);
				else f[i]=1;
				while(i-f[i]>=0 && i+f[i]<=(n<<1) && S[i-f[i]]==S[i+f[i]])f[i]++;
				if(i+f[i]-1>mx)mx=i+f[i]-1,id=i;
				if(S[i]>=-1)ans+=f[i]>>1;
			}

			f[0]=1;
			
		}
	}
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("beauty.in","r",stdin);
	freopen("beauty.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}