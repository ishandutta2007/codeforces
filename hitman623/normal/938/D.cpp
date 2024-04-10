#include <bits/stdc++.h>

#define int          long long
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
#define hell        1000000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,m,ans[200005],visi[200005],x,y,w;
vii a[200005];
void solve(){
	cin>>n>>m;
	rep(i,0,m){
		cin>>x>>y>>w;
		a[x].pb({y,w});
		a[y].pb({x,w});
	}
	priority_queue<pii> pq;
	rep(i,0,n){
		cin>>x;
		pq.push({-x,i+1});
	}
	while(!pq.empty()){
		auto d=pq.top();
		pq.pop();
		if(visi[d.y]) continue;
		ans[d.y]=-d.x;
		visi[d.y]=1;
		for(auto i:a[d.y]){
			if(!visi[i.x]){
				pq.push({d.x-2*i.y,i.x});
			}
		}
	}
	rep(i,1,n+1){
		cout<<ans[i]<<" ";
	}
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