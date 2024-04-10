#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2000+5;
char s[N][N];
int dp[N][N];
bool in[N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n,k;
	cin>>n>>k;
	rep(i,1,n)scanf("%s",s[i]+1);
	int mx=1;
	rep(i,1,n)
	rep(j,1,n)
	{
		if(i==1&&j==1)dp[i][j]=s[i][j]!='a';
		else dp[i][j]=(s[i][j]!='a')+min(i==1?k+1:dp[i-1][j],j==1?k+1:dp[i][j-1]);
		if(dp[i][j]<=k)chmax(mx,i+j);
	}
	rep(i,1,mx-1)putchar('a');
	deque<int>q;
	rep(i,1,n)
	rep(j,1,n)
	if(dp[i][j]<=k&&i+j==mx)q.push_back(i*N+j);
	if(q.empty()){putchar(s[1][1]);q.push_back(1*N+1);}
	while(1)
	{
		int mn='z'+1;
		for(auto i:q)
		{
			int x=i/N,y=i%N;
			if(x<n)chmin(mn,int(s[x+1][y]));
			if(y<n)chmin(mn,int(s[x][y+1]));
		}
		if(mn>'z')break;
		putchar(mn);
		deque<int>q1;
		for(auto i:q)
		{
			int x=i/N,y=i%N;
			if(s[x+1][y]==mn&&!in[x+1][y]){q1.push_back((x+1)*N+y);in[x+1][y]=1;}
			if(s[x][y+1]==mn&&!in[x][y+1]){q1.push_back(x*N+y+1);in[x][y+1]=1;}
		}
		q=q1;
	}
}