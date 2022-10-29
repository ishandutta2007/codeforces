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
vector<ll> a(16),v[2],row,col;
int n,k;
void g(int h,int in,ll cur)
{
	if(in==sz(v[h])) {
		if(h==0) row.pb(cur);
		else col.pb(cur);
		return;
	}
	ll temp=1;
	rep(i,0,60){
		if(1.0l*temp*cur<=1e18) g(h,in+1,cur*temp);
		else break;
		if(1.0l*temp*v[h][in]>1e18) break;
		temp*=v[h][in];
	}
}
int get(ll mid)
{
	int cur1=0,cur2=0,ans=0;
	while(cur2<sz(col) && 1.0l*row[cur1]*col[cur2]<mid)
		cur2++;
	cur2=min(cur2,sz(col)-1);
	while(cur1<sz(row)){
		while(cur2>=0 && 1.0l*row[cur1]*col[cur2]>mid) cur2--;
		ans+=cur2+1;
		cur1++;
	}
	return ans;
}
void solve()
{
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	cin>>k;
	for(int i=0;i<n;i+=2){
		v[0].pb(a[i]);
		if(i+1<n)
		v[1].pb(a[i+1]);
	}
	g(0,0,1);
	g(1,0,1);
	sort(all(row));
	sort(all(col));
	ll lo=0,hi=1e18;
	while(hi-lo>1){
		ll mid=(lo+hi)/2;
		if(get(mid)<k)
			lo=mid;
		else hi=mid;
	}
	cout<<hi;
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