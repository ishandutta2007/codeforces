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
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e3+20;

char str[maxn][maxn];

int n,k,vis[maxn][maxn],pre[maxn][maxn],dp[maxn][maxn];
char now[maxn][maxn];

int main()
{
	n=read();k=read();
	REP(i,1,n)
	{
		scanf("%s",str[i]+1);
		memcpy(now[i],str[i],sizeof(now[i]));
	}

	memset(dp,63,sizeof(dp));
	vis[1][1]=1;dp[1][1]=0;

	int K=0;
	
	REP(i,1,2*n-1)
	{
		int flg=0,mn=100;
		REP(y,1,min(i,n))
		{
			int x=i-y;
			if((x>0 && x<=min(i,n)) && (y<=i))
			{
				if(vis[x][y])
				{
					chkmin(mn,str[x][y]-'a');
					if(dp[x][y]<k && now[x][y]!='a')dp[x][y]++,now[x][y]='a',mn=0;
				}
			}
		}

		REP(y,1,min(i,n))
		{
			int x=i-y;
			if((x>0 && x<=min(i,n)) && (y<=min(n,i)))
			{
				if(vis[x][y] && now[x][y]-'a'==mn)
				{
					vis[x+1][y]=vis[x][y+1]=1;
					//chkmin(dp[x+1][y],dp[x][y]); chkmin(dp[x][y+1],dp[x][y]);
					//pre[x+1][y]=1;
					//pre[x][y+1]=0;
					if(dp[x+1][y]>dp[x][y])dp[x+1][y]=dp[x][y],pre[x+1][y]=1;
					if(dp[x][y+1]>dp[x][y])dp[x][y+1]=dp[x][y],pre[x][y+1]=0;
				}
			}
		}
	}
	vector<char>t;
	int x=n,y=n;
	while(x>=1 && y>=1)
	{
		t.push_back(str[x][y]);
		int op=pre[x][y];
		if(op)x--;else y--;
	}
	reverse(t.begin(),t.end());
	int sum=0;
	REP(i,0,2*n-2)
	{
		if(sum==k)printf("%c",t[i]);
		else {
			printf("%c",'a');
			sum+=t[i]!='a';
		}
	}
		
	return 0;
}