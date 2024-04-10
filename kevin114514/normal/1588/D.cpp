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
void die(string S){puts(S.c_str());exit(0);}
map<vector<int>,pair<int,string> > dp;
char s[11][110];
int edge[11][110][55];
int to_int(char c)
{
	if(islower(c))
		return c-'a';
	return c-'A'+26;
}
char to_char(int a)
{
	if(a<26)
		return 'a'+a;
	else	return 'A'+a-26;
}
int n;
pair<int,string> dfs(vector<int> v)
{
	if(dp[v].first)
		return dp[v];
	dp[v]=mp(1,"");
	int ans=1;
	string ss;
	for(int i=0;i<52;i++)
	{
		bool fl=0;
		vector<int> u;
		for(int j=0;j<n;j++)
			if(edge[j][v[j]][i]==-1)
				fl=1;
			else	u.pb(edge[j][v[j]][i]);
		if(!fl)
		{
			pair<int,string> p=dfs(u);
			if(p.first+1>ans)
			{
				ans=p.first+1;
				ss=to_char(i)+p.second;
			}
		}
	}
	return dp[v]=mp(ans,ss);
}
void solve()
{
	dp.clear();
	cin>>n;
	memset(edge,-1,sizeof(edge));
	for(int i=0;i<n;i++)
	{
		cin>>(s[i]+1);
		int m=strlen(s[i]+1);
		for(int j=0;j<=m;j++)
			for(int k=m;k>j;k--)
				edge[i][j][to_int(s[i][k])]=k;
	}
	vector<int> v(n,0);
	cout<<dfs(v).first-1<<endl;
	cout<<dfs(v).second<<endl;
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}