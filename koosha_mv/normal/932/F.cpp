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
#define pll pair<ll,ll> 

const int N=1e5+99,inf=1e10;

int n,cnt,a[N],b[N],s[N],t[N];
pair<int,int> res[N];
vector<int> g[N];

struct CHT{
	vector<pair<int,int> > v,e;
	vector<int> s;
	int intersect(pll a,pll b){
		if(a.F==b.F) return (a.S<=b.S ? -inf : inf);
		return (a.S-b.S)/(b.F-a.F)+((a.S-b.S)%(b.F-a.F)>0);
	}
	int getsize(){
		return e.size();
	}
	void add(pll a){
		e.pb(a);
	}
	void do_it(){
		sort(all(e));
		for(auto p : e){
			while(v.size() && intersect(v.back(),p)<s.back()){
				v.pop_back();
				s.pop_back();
			}
			v.pb(p);
			if(s.size()==0){
				s.pb(-inf);
			}
			else{
				s.pb(intersect(v[v.size()-2],v[v.size()-1]));
			}
		}
	}
	int getmax(int x){
		int u=upper_bound(all(s),x)-s.begin();
		return v[u-1].F*x+v[u-1].S;
	}
} seg[N<<2];

void add(int id,int l,int r,int x,pll val){
	if(r<=x || x<l) return ;
	seg[id].add(val);
	if(seg[id].getsize()==r-l){
		seg[id].do_it();
	}
	if(l+1==r) return ;
	int mid=(l+r)>>1;
	add(id<<1,l,mid,x,val);
	add(id<<1|1,mid,r,x,val);
}
int get(int id,int l,int r,int L,int R,int x){
	if(r<=L || R<=l) return -inf;
	if(L<=l && r<=R){
		return seg[id].getmax(x);
	}
	int mid=(l+r)>>1;
	return max(get(id<<1,l,mid,L,R,x),get(id<<1|1,mid,r,L,R,x));
	
}
void dfs(int u,int p){
	int child=0;
	s[u]=cnt++;
	for(auto v : g[u]){
		if(v==p) continue ;
		child++;
		dfs(v,u);
	}
	t[u]=cnt;
	if(u>0 && child==0){
		res[u]={b[u], 0};
	}
	else{		
		res[u]={b[u], get(1,0,n,s[u]+1,t[u],a[u])};
	}
	//cout<<u<<" : "<<res[u].F<<" "<<res[u].S<<endl;
	add(1,0,n,s[u],res[u]);
	
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n) cin>>a[i];
	f(i,0,n){ cin>>b[i]; b[i]=-b[i]; }
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,0);
	f(i,0,n) cout<<-res[i].S<<" ";
}