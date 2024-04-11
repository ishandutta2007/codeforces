#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
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
 
const int N=1e6+99,S=27;
 
int n,cnt,sz[N],a[N],res[N],par[N],dp[N],st[N],ft[N],mark[N],nex[N][S],child[S];
ll ans;
string t,s[N];
vector<int> g[N];

bool cmp(int i,int j){
   return st[i]<st[j];
}
void dfs(int u){
   st[u]=cnt++;
   for(auto v : g[u]){
      dfs(v);
   }
   ft[u]=cnt;
}
void build_aho(){
	int m=1;
	rep(i,1,n+1){
		int now=1;
		for(auto c : s[i]){
			if(nex[now][c-'a']==0){
				nex[now][c-'a']=++m;
			}
			now=nex[now][c-'a'];
		}
		dp[now]=now;
		sz[now]=s[i].size();
	}
	par[1]=1;
	queue<int> q;
	q.push(1);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(dp[u]==0) dp[u]=dp[par[u]];
		rep(i,0,S){
			child[i]=nex[u][i];
		}
		if(u==1){
			rep(i,0,S){
				nex[u][i]=1;
			}
		}
		else{
		   g[par[u]].pb(u);
		}
		rep(i,0,S){
			if(child[i]==0){
				nex[u][i]=nex[par[u]][i];
				continue ;
			}
			par[child[i]]=nex[par[u]][i];
			nex[u][i]=child[i];
			q.push(child[i]);
		}
	}
}
void solve(string t){
	vector<int> vec;
	int res=0,now=1;
	rep(i,0,t.size()){
		now=nex[now][t[i]-'a'];
		int x=dp[now];
		if(t.size()==sz[x]){
			x=dp[par[x]];
		}
		if(x==0) continue ;
		vec.pb(x);
		res+=1-mark[x];
		mark[x]=1;
	}
	vector<pair<int,int> > v;
	now=1;
	rep(i,0,t.size()){
		now=nex[now][t[i]-'a'];
		int x=dp[now];
		if(t.size()==sz[x]){
			x=dp[par[x]];
		}
		if(x==0) continue ;
		while(v.size() && i-sz[x]<=v.back().F-sz[v.back().S]){
			res-=mark[v.back().S];
			mark[v.back().S]=0;
			v.pop_back();
		}
		v.pb({i,x});
	}
	sort(all(vec),cmp);
	rep(i,0,sz(vec)-1){
	   if(st[vec[i]]<st[vec[i+1]] && ft[vec[i]]>st[vec[i+1]]){
	      res-=mark[vec[i]];
	      mark[vec[i]]=0;
	   }
	}
	
	ans+=res;
	for(auto x : vec) mark[x]=0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n+1) cin>>s[i];
	build_aho();
	dfs(1);
	rep(i,1,n+1) solve(s[i]);
	cout<<ans;
}