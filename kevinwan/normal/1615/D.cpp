#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

struct dsu{
	int p[mn],val[mn];
	dsu(){iota(p,p+mn,0);memset(val,0,sizeof(val));}
	int f(int x){
		if(x==p[x])return x;
		f(p[x]);
		val[x]^=val[p[x]];
		return p[x]=p[p[x]];
	}
	int dis(int x){
		f(x);
		return val[x];
	}
	void mrg(int a,int b, int d){
		int da=dis(a),db=dis(b);
		a=f(a),b=f(b);
		if(a==b)return;
		p[b]=a;
		val[b]=d^da^db;
	}
} dsu;
vector<int>g[mn],d[mn];
bool fail = 0;
int val[mn];
bool vis[mn];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i],dis=d[x][i];
		if(!vis[y]){
			val[y]=val[x]^dis;
			dfs(y);
		}
		else{
			if(val[y]!=(val[x]^dis)){
				fail = 1;
				return;
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)g[i].clear(),d[i].clear(), fail = 0,dsu.p[i]=i,dsu.val[i]=0,vis[i]=0,val[i]=0;
	vector<pii>extra;
	for(int i=0;i<n-1;i++){
		////cerr<<dsu.p[1]<<" "<<dsu.val[1]<<endl;
		int a,b,c;
		cin>>a>>b>>c;
		extra.push_back({a,b});
		if(c==-1){
			
		}
		else {
			dsu.mrg(a,b,c);
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int da=dsu.dis(a),db=dsu.dis(b);
		a=dsu.f(a),b=dsu.f(b);
		g[a].push_back(b);
		g[b].push_back(a);
		int idk=__builtin_popcount(da^db^c)%2;
		//cerr<<dsu.p[a]<<" "<<dsu.p[b]<<endl;
		d[a].push_back(idk);
		d[b].push_back(idk);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	if(fail){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(pii p:extra){
			int a=p.first,b=p.second;
			int da=dsu.dis(a),db=dsu.dis(b);
			a=dsu.f(a),b=dsu.f(b);
			int c=da^db^val[a]^val[b];
			printf("%d %d %d\n",p.first,p.second,c);
		}
	}
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