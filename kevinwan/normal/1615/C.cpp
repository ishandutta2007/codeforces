#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

int dis[mn][2];

void solve(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int ns=0,nt=0,cor=0;
	for(int i=0;i<n;i++){
		ns+=s[i]=='1';
		nt+=t[i]=='1';
		cor+=s[i]==t[i];
	}
	if(ns!=nt&&ns!=n+1-nt){
		printf("-1\n");
		return;
	}
	for(int i=0;i<=n;i++)dis[i][0]=dis[i][1]=0x3f3f3f3f;
	dis[cor][ns==nt]=0;
	function<void(int,bool)> dfs = [&](int x,bool b){
		if(dis[n+1-x][!b]==0x3f3f3f3f&&x!=0){
			dis[n+1-x][!b]=dis[x][b]+1;
			dfs(n+1-x,!b);
		}
		if(dis[n-1-x][!b]==0x3f3f3f3f&&x!=n){
			dis[n-1-x][!b]=dis[x][b]+1;
			dfs(n-1-x,!b);
		}
	};
	dfs(cor,ns==nt);
	int ans;
	if(ns==n+1-ns)ans=min(dis[n][1],dis[n][0]);
	else ans=dis[n][1];
	printf("%d\n",ans==0x3f3f3f3f?-1:ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}