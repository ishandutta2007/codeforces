#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

int val[mn],par[mn];
vector<int> g[mn];
void dfs(int x,int p){
	par[x]=p;
	val[x]=0;
	for(int y:g[x])if(y!=p){
		dfs(y,x);
		val[x]^=val[y]+1;
	}
	//cerr<<x<<" "<<val[x]<<endl;
}
int ans;
bool root[mn];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,1);
	root[1]=1;
	ans=val[1];
	printf("%d",ans?1:2);
	//cerr<<ans<<endl;
	for(int i=2;i<=n;i++){
		if(!root[i]){
			int cur=i;
			vector<int> v;
			while(!root[cur]){
				v.push_back(cur);
				cur=par[cur];
			}
			v.push_back(cur);
			//for(int x:v)cerr<<x;
			//cerr<<endl;
			for(int i=v.size()-1;i>0;i--){
				val[v[i]]^=val[v[i-1]]+1;
				if(root[v[i]])ans^=val[v[i-1]]+1;
				ans^=1;
				//cerr<<ans<<endl<<endl;
			}
			for(int i=0;i<v.size()-1;i++){
				root[v[i]]=1;
				//cerr<<v[i]<<endl<<endl;
				ans^=val[v[i]];
			}
		}
		//cerr<<ans<<endl;
		printf("%d",ans?1:2);
	}
	printf("\n");
}