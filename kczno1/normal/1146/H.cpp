#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=300+5;
vector<pair<double,pair<int,int>>>e;
int x[N],y[N];
s64 dp[N][N][5];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n;
	cin>>n;
	rep(i,1,n)cin>>x[i]>>y[i];
	rep(i,1,n)
	rep(j,1,n)
	if(j!=i)e.push_back({atan2(x[j]-x[i],y[j]-y[i]),{i,j}});
	sort(e.begin(),e.end());
	for(auto p:e)
	{
		int x,y;
		tie(x,y)=p.second;
		++dp[x][y][0];
		rep(i,1,n)
		rep(j,0,3)dp[i][y][j+1]+=dp[i][x][j];	
	}
	s64 ans=0;
	rep(i,1,n)ans+=dp[i][i][4];
	cout<<ans;
}