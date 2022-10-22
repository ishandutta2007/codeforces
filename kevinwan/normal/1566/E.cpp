#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,21> farray;

const int mn = 8e5+10;
const ll mod = 1e9+7;

vector<int> g[mn];

bool rem[mn];
int ans;
void dfs(int x,int p){
	rem[x]=0;
	for(int y:g[x])if(y!=p){
		dfs(y,x);
		if(!rem[y])rem[x]=1;
	}
	if(!rem[x])ans++;
	else if(x!=p) ans--;
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)g[i].clear();
	ans=0;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,1);
	printf("%d\n",ans);
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