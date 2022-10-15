#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
bool grid[1010][1010];
int num[1010][1010];
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
			if(s[j]=='*')
				grid[i][j+1]=1,
				cnt++;
	}
	int ccnt=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			num[j][i]=ccnt++;
	int coin=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(grid[i][j]&&num[i][j]<=cnt)
				coin++;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(grid[x][y])
		{
			if(num[x][y]<=cnt)
				coin--;
			grid[x][y]=0;
			if(grid[(cnt-1)%n+1][(cnt-1)/n+1])
				coin--;
			cnt--;
		}
		else
		{
			if(num[x][y]<=cnt)
				coin++;
			grid[x][y]=1;
			cnt++;
			if(grid[(cnt-1)%n+1][(cnt-1)/n+1])
				coin++;
		}
		cout<<cnt-coin<<endl;
	}
	return 0;
}