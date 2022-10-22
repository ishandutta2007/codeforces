#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,mod=1e9+7;

int n,m,a[N],L[N],R[N],par[N],q[N][3];
vector<int> v;
map<int,int> T;
set<pair<int,int> > fen[N];

pair<int,int> Get(int x){
	pair<int,int> ans;
	ans.F=ans.S=0;
	while(x){
		if(fen[x].size()) maxm(ans,*fen[x].rbegin());
		x-=(x&-x);
	}
	return ans;
}
void Add(int x){
	int u=L[x];
	while(u<N){
		fen[u].insert(mp(R[x],x));
		u+=(u&-u);
	}
}
void del(int x){
	int u=L[x];
	while(u<N){
		fen[u].erase(mp(R[x],x));
		u+=(u&-u);
	}
}
int Get_par(int u){
	return (par[u]<0 ? u : par[u]=Get_par(par[u]));
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);
	L[u]=min(L[u],L[v]);
	R[u]=max(R[u],R[v]);
	par[u]+=par[v];
	par[v]=u;
}
void read(){
	cin>>n;
	f(i,0,n){
		cin>>q[i][0]>>q[i][1]>>q[i][2];
		a[i*2]=q[i][1],a[i*2+1]=q[i][2];
	}
	sort(a,a+n+n);
	f(i,0,n+n){
		if(i==0 || a[i]!=a[i-1])
			T[a[i]]=++m;
	}
	m=0;
	f(i,0,n){
		if(q[i][0]==1){
			vector<int> v;
			pair<int,int> p;
			int l=T[q[i][1]],r=T[q[i][2]];
			par[++m]=-1;
			L[m]=l,R[m]=r;
			while((p=Get(l-1)).F>l){
				v.pb(p.S);
				del(p.S);
			}
			while((p=Get(r-1)).F>r){
				v.pb(p.S);
				del(p.S);
			}
			f(i,0,v.size()){
				merge(m,v[i]);
			}
			Add(Get_par(m));
		}
		else{
			int u=Get_par(q[i][1]),v=Get_par(q[i][2]);
			if(L[v]<=L[u] && R[u]<=R[v]) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}
}

int main(){
	read();
}