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
#define hell        1000000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,x[100005],y[100005],ans=0;
void solve(){
	string s;
	cin>>n>>s;	
	rep(i,1,n+1){
		x[i]=x[i-1];
		y[i]=y[i-1];
		if(s[i-1]=='U') y[i]++;
		else x[i]++;
	}
	rep(i,1,n){
		if(x[i]==y[i] && (x[i-1]==x[i+1] || y[i-1]==y[i+1]))
			ans++;
	}
	cout<<ans;
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