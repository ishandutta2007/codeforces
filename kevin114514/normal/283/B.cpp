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
int n;
int a[200010];
ll dp[200010][2];
bool v[200010][2];
ll dfs(int k,int d)
{
	if(k<=0 || k>n)
    	return 0;
	if(k==1) return inf;
	if(dp[k][d]>0) return dp[k][d];
	if(v[k][d]) return inf;
	v[k][d]=true;
	if(d==0)
	{
		ll ans=dfs(k+a[k],1);
		if(ans==inf) dp[k][0]=inf;
		else dp[k][0]=ans+(ll)a[k];
	}
	else
	{
		ll ans=dfs(k-a[k],0);
		if(ans==inf) dp[k][1]=inf;
		else dp[k][1]=ans+(ll)a[k];
	}
	return dp[k][d];
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
    	if(dp[i][0]==0) dp[i][0]=dfs(i,0);
    	if(dp[i][1]==0) dp[i][1]=dfs(i,1);
	}
	for(int i=1;i<=n-1;i++)
	{
		if(dp[i+1][1]==inf) cout<<-1<<"\n";
		else printf("%I64d\n",dp[i+1][1]+i);
	}
    return 0;
}