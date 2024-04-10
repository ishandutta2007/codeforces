#include <bits/stdc++.h>
#define	int 		long long
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

void solve()
{
	int n,l,cost=1LL*hell*hell;
	cin>>n>>l;
	vi c(31),ans(31);
	rep(i,0,31){
		if(i<n)
		cin>>c[i];
		else c[i]=1LL*hell*hell;
	}
	for(int i=29;i>=0;i--)
		c[i]=min(c[i],c[i+1]);
	ans[0]=c[0];
	rep(i,1,31)
		ans[i]=min(c[i],2*ans[i-1]);
	int temp=0;
	for(int i=30;i>=0;i--){
		if((l>>i)&1){
			temp+=ans[i];
		}
		else cost=min(cost,temp+ans[i]);
	}
	cost=min(cost,temp);
	cout<<cost;	
}

signed main()
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