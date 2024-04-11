#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=53;

int n,m,u=-1,a[N],g[N][N],deg[N],mark[N],par[N];

void change(int u,int v){
	deg[u]++;
	deg[v]--;
	swap(g[u][v],g[v][u]);
}
void dfs(int x,int rt){
	mark[x]=1;
	//cout<<rt<<" : "<<x<<endl;
	f(i,0,n){
		if(g[x][i]==1 && !mark[i]){
			par[i]=x;
			dfs(i,rt);
		}
	}
	if(deg[rt]+1<deg[x]) u=x;
}
bool check(){
	f(i,0,n){
		fill(mark,mark+N,0);
		u=-1;
		par[i]=-1;
		dfs(i,i);
		if(u!=-1){
			for(;u!=i;u=par[u]){
				change(par[u],u);
			}
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		deg[v]++;
		g[u][v]=2;
	}
	f(i,0,n){
		f(j,0,n){
			if(i!=j && !g[i][j] && !g[j][i]){
				if(rand()%2) deg[i]++,g[j][i]=1;
				else deg[j]++,g[i][j]=1;
			}
		}
	}
	while(check()){

	}
	f(i,0,n){
		//eror(deg[i]);
		f(j,0,n)
			cout<<(g[i][j]>0);
		cout<<endl;
	}
}