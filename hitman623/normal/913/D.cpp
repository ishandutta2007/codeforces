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
int n,T;
vi a(200005),tim(200005);
int check(int mid)
{
	vi v;
	rep(i,0,n)
	if(mid<=a[i])	
		v.pb(tim[i]);
	if(sz(v)<mid) return 0;
	sort(all(v));
	int s=0;
	rep(i,0,mid)
	s+=v[i];
	return s<=T;
}
void solve()
{
	cin>>n>>T;
	rep(i,0,n)
	cin>>a[i]>>tim[i];
	int lo=0,hi=n;
	while(hi-lo>1)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			lo=mid;
		else hi=mid;
	}
	int ans;
	if(check(hi)) ans=hi;
	else ans=lo;
	vii v;
	rep(i,0,n)
	if(ans<=a[i])	
		v.pb({tim[i],i});
	sort(all(v));
	cout<<ans<<"\n"<<ans<<"\n";
	rep(i,0,ans)
		cout<<v[i].y+1<<" ";
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