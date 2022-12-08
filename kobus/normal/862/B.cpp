#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

vector<int> are[112345];
int cor[112345];

void dfs(int u){
	for(int i=0;i<are[u].size();i++){
		if(cor[are[u][i]]==-1){
			cor[are[u][i]]=!(cor[u]);
			dfs(are[u][i]);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cor[i]=-1;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		are[a].pb(b);
		are[b].pb(a);
	}
	cor[1]=1;
	dfs(1);
	int p=0,b=0;
	for(int i=1;i<=n;i++){
		//cout<<cor[i]<<endl;
		if(cor[i]==1)p++;
		else b++;
	}
	cout<<(1ll*p*b)-n+1<<endl;

	return 0;
}