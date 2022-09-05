#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=7000+5;
int n;
int du[2][N],dp[2][N];
int s[2][N];
deque<pii>q;
void push(int b,int i,int v)
{
	dp[b][i]=v;du[b][i]=0;
	q.push_back({b,i});
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n;
	rep(b,0,1)
	{
		scanf("%d",s[b]);
		rep(j,1,s[b][0])scanf("%d",s[b]+j);
		rep(j,0,n-1)du[b][j]=s[b][0];
	}
	rep(i,0,1)push(i,0,0);
	while(!q.empty())
	{
		auto now=q.front();q.pop_front();
		bool b=now.first;int i=now.second;
		if(dp[b][i])
		{
			rep(j,1,s[b^1][0])
			{
				int _i=(i-s[b^1][j]+n)%n;
				if(!--du[b^1][_i])push(b^1,_i,0);
			}
		}
		else
		{
			rep(j,1,s[b^1][0])
			{
				int _i=(i-s[b^1][j]+n)%n;
				if(du[b^1][_i]>0)push(b^1,_i,1);
			}
		}
	}
	rep(b,0,1)
	{
		rep(i,1,n-1)
		if(du[b][i]>0)printf("Loop "); else
		if(dp[b][i])printf("Win "); else
			printf("Lose ");
		puts("");
	}
}