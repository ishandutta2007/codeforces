#include<bits/stdc++.h>
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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;
const int seed=181;
const int mod=1e9+7;

int n,m,p1[maxn];

char S[maxn];
char T[maxn];

int snxt[maxn][26];
int hst;

inline void get_Hasht()
{
	static int num[26];
	REP(i,1,m)
	{
		int x=T[i]-'a';
		hst=((ll)hst*seed+i-num[x])%mod;
		num[x]=i;
	}
}

inline void init()
{
	n=read();m=read();
	scanf("%s",S+1);
	scanf("%s",T+1);
	p1[0]=1; REP(i,1,n)p1[i]=(ll)p1[i-1]*seed%mod;
	REP(j,0,25)snxt[n+1][j]=n+1;
	DREP(i,n,1)
	{
		REP(j,0,25)snxt[i][j]=snxt[i+1][j];
		snxt[i][S[i]-'a']=i;
	}
	get_Hasht();
}

vector<int>ans;

inline void doing()
{
	static int num[maxn];
	int hs=0;
	REP(i,1,n)
	{
		int x=S[i]-'a',lst=i-m+1;
		if(lst>1)
		{
			REP(j,0,25)if(snxt[lst-1][j]<=i-1)
				hs=(hs-p1[i-1-snxt[lst-1][j]])%mod;
		}
		hs=(hs+mod)%mod;
		hs=((ll)hs*seed+(i-max(num[x],lst-1)))%mod;
		num[x]=i;
		if(hs==hst)
		{
			static int mch[maxn];
			REP(j,0,26)mch[j]=26;
			REP(j,0,25)
				if(snxt[lst][j]<=i)
					mch[j]=T[snxt[lst][j]-lst+1]-'a';
				else mch[j]=26;
			int flg=0;
			REP(j,0,25)if(mch[mch[j]]!=j && mch[mch[j]]!=26)
			{
				flg=1; break;
			}
			if(!flg)ans.push_back(lst);
		}
	}
	printf("%d\n",SZ(ans));
	for(int x:ans)printf("%d ",x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}