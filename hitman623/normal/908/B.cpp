#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,m,sx,sy,ex,ey,ans=0;
string c;	
string s[101];
map<int,pii>mp;
int dfs(int x,int y)
{
	rep(i,0,sz(c))
	{
		int num=c[i]-'0';
		x=x+mp[num].x;
		y=y+mp[num].y;
		if(x<0 || y>=m  || x>=n || y<0 || s[x][y]=='#') return 0;
		if(s[x][y]=='E') return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	rep(i,0,n)
		cin>>s[i];
	rep(i,0,n)
		rep(j,0,m)
			if(s[i][j]=='S') sx=i,sy=j;
			else if(s[i][j]=='E') ex=i,ey=j;
	cin>>c;
	vi v={0,1,2,3};
	do
	{
		mp[v[0]]={-1,0};
		mp[v[1]]={1,0};
		mp[v[2]]={0,-1};
		mp[v[3]]={0,1};
		if(dfs(sx,sy))
			ans++;	
	}
	while(next_permutation(all(v)));
	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}