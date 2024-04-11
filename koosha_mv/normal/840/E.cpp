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
 
const int N=5e4+99,lg=17;
 
int n,q,a[N],b[N],h[N],par[lg][N];
vector<int> g[N],v[lg][N];
 
void merge(vector<int> &v1,vector<int> v2,int x,int l,int u){
	vector<int> vec,ans;
	int p=0;
	f(i,0,v2.size()){
		int p=i,mid=-1;
		while(p<v2.size() && (v2[p]>>(x+1))==(v2[i]>>(x+1))){
			if(v2[p]&(1<<x) && mid==-1){
				mid=p;
			}
			p++;
		}
		if(mid==-1) mid=p;
		int len0=mid-i,len1=p-mid;
		f(j,0,len0){
			b[j]=v2[i+j];
		}
		f(j,0,len1){
			v2[i+j]=v2[mid+j]^(1<<x);
		}
		f(j,0,len0){
			v2[i+len1+j]=b[j]^(1<<x);
		}
		i=p-1;
	}
	f(i,0,v1.size()){
		while(p<v2.size() && v2[p]<v1[i]){
			vec.pb(v2[p]);
			p++;
		}
		vec.pb(v1[i]);
	}
	while(p<v2.size()){
		vec.pb(v2[p]);
		p++;
	}
	f(i,0,vec.size()){
		p=i;
		while(p<vec.size() && (vec[p]>>(x+1))==(vec[i]>>(x+1))) p++;
		v[l][u].pb(vec[p-1]);
		i=p-1;
	}
}
void dfs(int x){
	v[0][x].pb(a[x]);
	f(i,1,lg){
		par[i][x]=par[i-1][par[i-1][x]];
		merge(v[i-1][x],v[i-1][par[i-1][x]],i-1,i,x);
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par[0][x]){
			par[0][g[x][i]]=x;
			h[g[x][i]]=h[x]+1;
			dfs(g[x][i]);
		}
	}
}
void read(){
	cin>>n>>q;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	par[0][1]=0;
	dfs(1);
}
int calc(int u,int x){
	int ans=0,sum=0;
	f_(i,lg-1,0){
		if(x&(1<<i)){
			f(j,0,v[i][u].size()){
				maxm(ans,v[i][u][j]^sum);
			}
			sum^=(1<<i);
			u=par[i][u];
		}
	}
	return ans;
}
void solve(){
	f(i,0,q){
		int u,v;
		cin>>u>>v;
		cout<<calc(v,h[v]-h[u]+1)<<endl;
	}
}
 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	read();
	solve();
}