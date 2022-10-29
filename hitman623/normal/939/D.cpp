#include <bits/stdc++.h>

#define int         long long
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
vi a[30];
int v[30];
vii vv;
void dfs(int node,int par){
	if(par!=-1)
	vv.pb({par,node});
	v[node]=1;
	for(auto i:a[node]){
		if(i!=par && !v[i]){
			dfs(i,node);
		}
	}
}
void solve(){
	int n,ans=0;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	rep(i,0,n){
		if(s1[i]==s2[i]) continue;
		a[s1[i]-'a'+1].pb(s2[i]-'a'+1);
		a[s2[i]-'a'+1].pb(s1[i]-'a'+1);
	}	
	rep(i,1,27){
		if(!v[i]){
			dfs(i,-1);
		}
	}
	cout<<vv.size()<<endl;
	for(auto i:vv){
		cout<<(char)(i.x+'a'-1)<<" "<<(char)(i.y+'a'-1)<<endl;
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