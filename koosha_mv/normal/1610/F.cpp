#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+99,S=2;

int n,m,cnt,res,ans[N],X[N],Y[N],deg[S][N];
vector<pair<int,int> > g[S][N];

void calc(){
	f(i,1,n+1){
		if(deg[0][i]&1){
			res++;
		}
	}
}
void Dfs(int x,int s){
	//eror(x);
	while(g[s][x].size() && ans[g[s][x].back().S]){
		g[s][x].pop_back();
	}
	if(g[s][x].size()){
		int u=g[s][x].back().F;
		ans[g[s][x].back().S]=x;
		g[s][x].pop_back();
		deg[s][x]--;
		deg[s][u]--;
		Dfs(u,s);
	}
	else{
		if(deg[s^1][x]&1){
			Dfs(x,s^1);
		}
	}
}
void do_it(){
	f(i,1,n+1){
		if((deg[0][i]&1)==1 && (deg[1][i]&1)==0){
			//cout<<"1 :"<<endl;
			Dfs(i,0);
		}
	}
	f(i,1,n+1){
		if((deg[0][i]&1)==0 && (deg[1][i]&1)==1){
			//cout<<"2 :"<<endl;
			Dfs(i,1);
		}
	}
	f(i,1,n+1){
		if((deg[0][i]&1)+(deg[1][i]&1)==2){
			//cout<<"3 :"<<endl;
			Dfs(i,0);
		}
	}
	f(i,1,n+1){
		while(deg[0][i]+deg[1][i]){
			Dfs(i,0);
			Dfs(i,1);
		}
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int s;
		cin>>X[i]>>Y[i]>>s;
		s--;
		deg[s][X[i]]++;
		deg[s][Y[i]]++;
		g[s][X[i]].pb(mp(Y[i],i));
		g[s][Y[i]].pb(mp(X[i],i));
	}
	calc();
	do_it();
	cout<<res<<endl;
	f(i,0,m){
		if(!ans[i]) cout<<"OPOPO";
		if(X[i]==ans[i]) cout<<1;
		else cout<<2;
	}
}