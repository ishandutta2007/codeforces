#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,res,a[N],b[N],deg[N],state[N];
vector<pair<int,int>> g[N];
vector<int> ans,vec[N][2];

void dfs1(int u,int p,int pid){
	int sum=0;
	for(auto [v,id] : g[u]){
		if(v==p) continue ;
		dfs1(v,u,id);
		sum+=(state[id]==0 ? -1 : +1);
	}
	if(sum<-1 || sum>2 || (u==1 && sum!=0 && sum!=1)) res=0;
	if(sum<=0) state[pid]=1;
	else state[pid]=0; 

}

void Main(){
	cin>>n;
	f(i,1,n) {
		cin>>a[i]>>b[i];
		g[a[i]].pb({b[i],i});
		g[b[i]].pb({a[i],i});
	}

	res=1;
	dfs1(1,0,0);
	if(res==0){
		cout<<"NO"<<'\n';
		return ;
	}
	cout<<"YES"<<'\n';
	
	f(i,1,n) vec[a[i]][state[i]].pb(i),vec[b[i]][state[i]].pb(i);
	queue<int> q;
	f(i,1,n+1) if(++deg[vec[i][1].back()]==2) q.push(vec[i][1].back());
	while(q.size()){
		int id=q.front(),u=a[id],v=b[id],stt=state[id];
		q.pop();
		ans.pb(id);
		vec[u][stt].pop_back();
		vec[v][stt].pop_back();
		if(vec[u][stt^1].size() && ++deg[vec[u][stt^1].back()]==2) q.push(vec[u][stt^1].back());
		if(vec[v][stt^1].size() && ++deg[vec[v][stt^1].back()]==2) q.push(vec[v][stt^1].back());
	}
	while(ans.size()){
		cout<<a[ans.back()]<<" "<<b[ans.back()]<<'\n';
		ans.pop_back();
	}
}

int32_t main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,1,n+1) deg[i]=0,g[i].clear(),vec[i][0].clear(),vec[i][1].clear();
	}
}