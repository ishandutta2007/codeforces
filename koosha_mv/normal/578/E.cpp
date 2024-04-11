#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+99,S=2;
 
int n,par[N],mark[N];
string s;
vector<int> ans,d[S],g[S][S];
vector<vector<int> > v;
 
void Add(int x,int y){
	vector<int> V=v[g[x][y].back()];
	f(i,0,V.size()) ans.pb(V[i]);
	g[x][y].pop_back();
}
void make(){
	v.clear();
	f(i,0,N) mark[i]=0;
	f(i,0,S) f(j,0,S) g[i][j].clear();
	f_(i,n-1,0){
		if(!mark[i]){
			vector<int> V;
			for(int u=i;u!=-1;u=par[u]){
				mark[u]=1;
				V.pb(u);
			}
			reverse(V.begin(),V.end());
			g[s[V[0]]=='R'][s[V.back()]=='L'].pb(v.size());
			v.pb(V);
		}
	}
}
void read(){
	int cr=0,cl=0;
	cin>>s;
	n=s.size();
	f(i,0,n){
		if(s[i]=='R') cr++;
		else cl++;
	}
	if(cr<cl){
		f(i,0,n){
			if(s[i]=='R') s[i]='L';
			else s[i]='R';
		}
	}
}
void solve(){
	f(i,0,n){
		if(s[i]=='R'){
			if(d[0].size()==0) d[0].pb(-1);
			par[i]=d[0].back();
			d[0].pop_back();
			d[1].pb(i);
		}
		else{
			if(d[1].size()==0) d[1].pb(-1);
			par[i]=d[1].back();
			d[1].pop_back();
			d[0].pb(i);
		}
	}
	make();
}
void done(){
	int u=0;
	if(g[1][0].size()==0 && g[0][0].size() && g[1][1].size()){
		f(i,0,n) mark[i]=0;
		f(i,0,n) if(par[i]!=-1) mark[par[i]]=1;
		f(i,0,n){
			if(!mark[i] && s[i]!=s[n-1]){
				par[n-1]=i;
				break;
			}
		}
		make();
	}
	while(g[1][1].size()){
		Add(1,1);	
	}
	if(g[1][0].size()){
		Add(1,0);
	}
	while(g[0][0].size()){
		Add(0,0);
	}
	while(g[u][u^1].size()){
		Add(u,u^1);
		u^=1;
	}
	cout<<d[0].size()+d[1].size()-1<<endl;
	f(i,0,ans.size()) cout<<ans[i]+1<<" ";
}
 
int main(){
	read();
	solve();
	done();
}