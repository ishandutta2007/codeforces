#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=1e5+20;

int cnt[10];
int a[maxn],s[128],v[128];
int n;
char str[maxn];

const int M=6;

inline void init()
{
	scanf("%s",str+1);
	REP(i,1,n=strlen(str+1))cnt[str[i]-'a']++;
	REP(i,0,(1<<M)-1)
		REP(j,0,M-1)if(i>>j&1){v[i]=v[i^(1<<j)]+cnt[j];break;}
	int m=read();
	REP(i,1,m)
	{
		int now=read();
		scanf("%s",str+1);
		REP(j,1,strlen(str+1))a[now]|=1<<(str[j]-'a');
	}
	REP(i,1,n)if(!a[i])a[i]=(1<<M)-1;
	REP(i,1,n)s[a[i]]++;
	DREP(i,(1<<M)-1,0)
	{
		for(int t=i-1;~t;t--)
		{
			t&=i;
			s[i]+=s[t];
		}
	}

}

int ans[maxn];

inline bool check(int S,int x)
{
	REP(j,0,(1<<M)-1)if(v[j]-(((1<<x)|j)==j)<s[j]-((S|j)==j))return 0;
	return 1;
}

inline void doing()
{
	REP(i,1,n)
	{
		int flg=0;
		REP(j,0,M-1)
		{
			if(cnt[j] && (a[i]>>j&1) && check(a[i],j))
			{
				flg=1;ans[i]=j;
				cnt[j]--;
				REP(k,1,(1<<M)-1)
					REP(l,0,M-1)if(k>>l&1)v[k]=v[k^(1<<l)]+cnt[l];

				int bi=((1<<M)-1)^a[i];
				for(int t=bi;~t;t--)
				{
					t&=bi;
					s[t|a[i]]--;
				}
				break;
			}
		}
		if(!flg){puts("Impossible");exit(0);}
	}
	REP(i,1,n)printf("%c",ans[i]+'a');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}