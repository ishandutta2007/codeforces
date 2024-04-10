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

void solve()
{
	int n;
	cin>>n;
	vi leaf(n+1,0);
	vi a[n+1];
	rep(i,2,n+1){
		int x;
		cin>>x;
		a[x].pb(i);
	}
	rep(i,1,n+1)
		if(a[i].size()==0) leaf[i]=1;
	rep(i,1,n+1){
		int cnt=0;
		if(leaf[i]) continue;
		for(auto i:a[i])
			if(leaf[i]) cnt++;
		if(cnt<3) {cout<<"No";return;}
	}
	cout<<"Yes";
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