#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 8e5+10;
const ll mod = 1e9+7;

int num[mn];
bool vis[mn];
vector<int>g[mn];

void dfs(int x){
	int wst=1;
	vis[x]=1;
	for(int y:g[x]){
		if(!vis[y])dfs(y);
		int cand=num[y]+(x<y);
		wst=max(wst,cand);
	}
	num[x]=wst;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		g[i].clear();
		vis[i]=0;
		num[i]=0x3f3f3f3f;
		int m;
		cin>>m;
		while(m--){
			int y;
			cin >> y;
			g[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,num[i]);
	printf("%d\n",ans>n?-1:ans);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		solve();
	}
}