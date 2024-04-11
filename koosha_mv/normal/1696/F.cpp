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
#define int ll

const int N=111;

int n,t,vis[N],d[N][N],ask[N][N][N];
vector<int> g[N];

int find(int x){
	int ans=0;
	f(i,1,n+1){
		if(i==x) continue ;
		int b=1;
		f(j,1,i){
			if(ask[x][j][i]){
				b=0;
			}
		}
		ans+=b;
	}
	return ans;
}
void Dfs(int u,int p,int rt){
	for(auto v : g[u]){
		if(v==p) continue ;
		d[rt][v]=d[rt][u]+1;	
		Dfs(v,u,rt);
	}
}
bool check(){
	f(u,1,n+1){
		d[u][u]=0;
		Dfs(u,u,u);
	}
	f(u,1,n+1){
		f(i,1,n+1){
			f(j,i+1,n+1){
				if(ask[u][i][j]!=(d[u][i]==d[u][j])){
					//cout<<u<<" "<<i<<" "<<j<<endl;
					//eror(ask[u][i][j]);
					//eror((d[u][i]==d[u][j]));
					return 0;
				}
			}
		}
	}
	return 1;
}
void dfs(int u,int p){
	vis[u]=1;
	//cout<<p<<" -> "<<u<<endl;
	f(v,1,n+1){
		if(vis[v]) continue ;
		if(ask[u][p][v]==1){
			g[u].pb(v);
			g[v].pb(u);
			dfs(v,u);
		}
	}	
}
void Main(){
	cin>>n;
	f(i,1,n+1){
		f(j,i+1,n+1){
			string s;
			cin>>s;
			f(k,1,n+1){
				ask[k][i][j]=ask[k][j][i]=s[k-1]-'0';
			}
		}
	}
	vector<pair<int,int>> vec;
	f(i,1,n+1){
		//eror(find(i));
		vec.pb({find(i),i});
	}
	sort(all(vec));
	int X=vec[0].S,Y=vec[1].S;
	g[X].pb(Y);
	g[Y].pb(X);
	vis[X]=vis[Y]=1;
	dfs(X,Y);
	dfs(Y,X);
	if(check()==0){
		cout<<"No"<<'\n';
	}
	else{
		cout<<"Yes"<<'\n';
		f(u,1,n+1){
			for(auto v : g[u]){
				if(u<v){
					cout<<u<<" "<<v<<'\n';
				}
			}
		}
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,1,n+1) vis[i]=0,g[i].clear();
	}
}