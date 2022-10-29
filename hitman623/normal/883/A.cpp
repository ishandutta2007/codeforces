#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,m,a,d,t[100005],cur=0,ans=1,i;

void solve(){
	cin>>n>>m>>a>>d;
	for(i=1;i<=m;++i)
	cin>>t[i];
	t[0]=a;
	t[m+1]=n*a;
	m+=2;
	sort(t,t+m);
	cur=t[0];
	for(i=0;i<m;++i)
	{
		if(t[i]>n*a) break;
		if(cur+d>=t[i]) continue;
		cur=((cur+d)/a+1)*a;
		ans++;
		if(cur>=t[i]) {cur=t[i];continue;}
		if(d<a)
		{
			ans+=t[i]/a-cur/a;
			cur=(t[i]/a)*a;
			i--;
		}
		else
		{
			int alpha=(t[i]/a-cur/a)/(d/a+1);
			ans+=alpha;
			cur+=alpha*(d/a+1)*a;
			i--;
		}
	}
	while(i<m)
	{
		if(t[i]>cur+d)
		cur=t[i],ans++;
		i++;
	}
	cout<<ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}