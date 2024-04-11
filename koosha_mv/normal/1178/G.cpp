#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define pll pair<int,int>

const int N=2e5+99,sq=333,inf=1e16,S=N/sq+9;

int n,q,cnt,a[N],b[N],c[N],d[N],t[N],st[N],ft[N],node[N],val[N],ans[N],par[N];
vector<int> v[N],g[N];

bool cmp(int i,int j){ return b[i]<b[j]; }

void dfs(int u){
	st[u]=cnt++;
	for(auto v : g[u]) dfs(v); 
	ft[u]=cnt;
}
void pert(int x){
	f(i,0,n){
		a[st[i]]=c[i];
		b[st[i]]=d[i];
		if(x==1) b[st[i]]*=-1;
	}
}

struct CHT{
	
	vector<pll> v;
	vector<int> s,e;
	int p=0,prt=0,val=0;
	
	void clear(){
		prt=val=p=0;
		v.clear(),s.clear(),e.clear();
	}
	int intersect(pll a,pll b){
		if(a.F==b.F) return (a.S<=b.S ? 0 : inf);
		return max(0ll,(a.S-b.S)/(b.F-a.F)+((a.S-b.S)%(b.F-a.F)>0));
	}
	void add(int x){
		e.pb(x);
	}
	int getmax(){
		return val*v[p].F+v[p].S;
	}
	void addval(int x){
		val+=x;
		while(p+1<v.size() && s[p+1]<=val){
			p++;
		}
	}
	void doit(){
		if(prt==0) sort(all(e),cmp); 
		prt=1;
		for(auto id : e) a[id]+=val;
		val=p=0;
		v.clear();
		s.clear();
		for(auto id : e){
			pll p=mp(b[id],a[id]*b[id]);
			if(v.size() && intersect(v.back(),p)==inf) continue ;
			while(v.size() && intersect(v.back(),p)<=s.back()){
				v.pop_back();
				s.pop_back();
			}
			v.pb(p);
			if(s.size()==0){
				s.pb(0);
			}
			else{
				s.pb(intersect(v[v.size()-2],v[v.size()-1]));
			}
		}
	}
} cht[S];

inline int A(int x){
	return a[x]+cht[x/sq].val;
}
inline void change(int l,int r,int val){
	int idl=l/sq,idr=(r-1)/sq;
	while(l<r && l%sq){
		a[l++]+=val;
	}
	while(l<r && r%sq){
		a[--r]+=val;
	}
	cht[idl].doit();
	cht[idr].doit();
	while(l<r){
		cht[l/sq].addval(val);
		l+=sq;
	}
}
inline int get(int l,int r){
	int res=0;
	while(l<r && l%sq){
		maxm(res,A(l)*b[l]);
		l++;
	}
	while(l<r && r%sq){
		r--;
		maxm(res,A(r)*b[r]);
	}
	while(l<r){
		maxm(res,cht[l/sq].getmax());
		l+=sq;
	}
	return res;
}
inline void solve(){
	f(i,0,S) cht[i].clear();
	f(i,0,n) cht[i/sq].add(i);
	f(i,0,S) cht[i].doit(); 
	f(i,0,q){
		int l=st[node[i]],r=ft[node[i]];
		if(t[i]==1){
			change(l,r,val[i]);
		}
		else{
			maxm(ans[i],get(l,r));
		}
	}
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	f(i,1,n){
		cin>>par[i];
		par[i]--;
		g[par[i]].pb(i);
	}
	f(i,0,n){
		cin>>c[i];
		if(i>0) c[i]+=c[par[i]];
	}
	f(i,0,n){
		cin>>d[i];
		if(i>0) d[i]+=d[par[i]];
	}
	f(i,0,q){
		cin>>t[i]>>node[i]; node[i]--;
		if(t[i]==1) cin>>val[i];
	}
	dfs(0);
	pert(0);
	solve();
	pert(1);
	solve();
	f(i,0,q) if(t[i]==2) cout<<ans[i]<<' ';
}
/*
5 2
1 1 2 2
10 -3 -7 -3 -10
10 3 9 3 6
1 2 6
2 1
*/