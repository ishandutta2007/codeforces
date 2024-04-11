#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define ld long double

const int N=1e5+99;

int n,m,k,a[N],node[N],mark[N],in_set[N];
ld ans[N],deg[N];
set<pair<ld,int> > s;
vector<int> g[N];

void del(int x){
	in_set[x]=0;
	f(i,0,g[x].size()){
		if(in_set[g[x][i]]){
			s.erase(mp(deg[g[x][i]]/g[g[x][i]].size(),g[x][i]));
			deg[g[x][i]]--;
			s.insert(mp(deg[g[x][i]]/g[g[x][i]].size(),g[x][i]));
		}
	}
}
int main(){
	cin>>n>>m>>k;
	f(i,0,k){
		int x;
		cin>>x;
		mark[x]=1;
	}
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		if(!mark[i]){
			in_set[i]=1;
			f(j,0,g[i].size()){
				if(!mark[g[i][j]]){
					deg[i]++;
				}
			}
			s.insert(mp(deg[i]/g[i].size(),i));
		}
	}
	f(i,0,n-k){
		ans[i]=(*s.begin()).F;
		node[i]=(*s.begin()).S;
		s.erase(*s.begin());
		del(node[i]);
	}
	int u=0;
	f(i,0,n-k){
		if(ans[i]>ans[u]){
			u=i;
		}
	}
	cout<<n-k-u<<endl;
	f(i,u,n-k){
		cout<<node[i]<<" ";
	}
}