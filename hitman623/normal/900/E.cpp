#include "bits/stdc++.h"
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
pair<int,pii> dp[100005];
pii ans[100005];
int odda,evena,oddb,evenb;
void solve()
{
	int n,m;
	string s;
	cin>>n>>s>>m;
	if(n<m){
		cout<<0;
		return ;
	}
	rep(i,0,m){
		if(s[i]=='a'){
			if(i%2==0) odda++;
			else evena++;
		}
		else if(s[i]=='b'){
			if(i%2==0) oddb++;
			else evenb++;
		}
	}
	rep(i,m,n+1)
	{
		if(i%2!=m%2){
			swap(odda,evena);
			swap(oddb,evenb);
		}
		if(odda<=(m+1)/2 && evena==0 && oddb==0 && evenb<=m/2)
			dp[i-m].x=1,dp[i-m].y={odda,evenb};
		if(i%2!=m%2){
			swap(odda,evena);
			swap(oddb,evenb);
		}
		if(i==n) break;
		if(s[i]=='a'){
			if(i%2==0) odda++;
			else evena++;
		}
		else if(s[i]=='b'){
			if(i%2==0) oddb++;
			else evenb++;
		}
		if(s[i-m]=='a'){
			if((i-m)%2==0) odda--;
			else evena--;
		}
		else if(s[i-m]=='b'){
			if((i-m)%2==0) oddb--;
			else evenb--;
		}
	}
	rep(i,n-m+1,n+1)
		ans[i]={0,0};
	for(int i=n-m;i>=0;i--)
	if(dp[i].x)
	{
		if(ans[i+m].x+1==ans[i+1].x)
		{
			if(ans[i+m].y+m-dp[i].y.x-dp[i].y.y<ans[i+1].y)
			ans[i]={ans[i+m].x+1,ans[i+m].y+m-dp[i].y.x-dp[i].y.y};
			else ans[i]=ans[i+1];
		}
		else if(ans[i+m].x+1<ans[i+1].x)
			ans[i]=ans[i+1];
		else ans[i]={ans[i+m].x+1,ans[i+m].y+m-dp[i].y.x-dp[i].y.y};
	}
	else ans[i]=ans[i+1];
	cout<<ans[0].y<<endl;
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