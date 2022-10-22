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
#define pii pair<ll,ll>

const int N=1e5+99,lg=16;

int n,m,sza,szprt,a[N],b[N],p[N];
ll h[N],prt[N*lg];
pii A[N*lg];
set<ll> s[N];
vector<ll> vec;
vector<int> g[N],mv[N],ad[N*lg],dl[N*lg];

void add(ll l,ll r){
	vec.pb(l);
	vec.pb(r);
	A[sza++]={l,r};
}
void dfs1(int u){
	int sp=-1;
	set<int> st;
	for(auto v : g[u]){
		h[v]+=h[u];
		dfs1(v);
		if(sp==-1 || s[v].size()>s[sp].size()) sp=v;
	}	
	if(sp==-1){
		for(auto x : mv[u]) s[u].insert(x);
		return ;
	}
	swap(s[u],s[sp]);
	for(auto v : g[u]){
		if(v==sp) continue ;
		for(auto x : s[v]) s[u].insert(x),st.insert(x);
	}
	for(auto v : g[u]){
		if(v==sp) continue ;
		for(auto x : s[v]){
			if(x!=(*s[u].rbegin()) && s[v].count(*s[u].upper_bound(x))==0){
				int l=x,r=*s[u].upper_bound(x);
				add(l+h[u]+1,r+h[u]+1);
			}
			if(x!=(*s[u].begin()) && st.count(*prev(s[u].lower_bound(x)))==0){
				int l=*prev(s[u].lower_bound(x)),r=x;
				add(l+h[u]+1,r+h[u]+1);
			}
		}
	}
	if(s[u].size() && ((p[u]==sp && st.count(*s[u].begin())==1) || (p[u]!=sp && s[p[u]].count(*s[u].begin())==0))){
		add(1,*s[u].begin()+h[u]+1);
	}
	for(auto x : mv[u]) s[u].insert(x);
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n){
		int u,v,d;
		cin>>u>>v>>d;
		p[u]=v;
		h[v]=d;
		g[u].pb(v);
	}
	f(i,1,m+1){
		cin>>a[i]>>b[i];
		mv[a[i]].pb(b[i]);
	}
	dfs1(1);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	if(vec.size()>=N*lg) assert(0);
	if(sza>=N*lg) assert(0);
	sort(A,A+sza);
	f(i,0,sza){
		pii p=A[i];
		ad[lower_bound(all(vec),p.F)-vec.begin()].pb(i);
		dl[lower_bound(all(vec),p.S)-vec.begin()].pb(i);
	}
	int lst=0,res=0;
	set<pii> s;
	f(i,0,vec.size()){
		int tm=vec[i]-lst,check=0;
		while(s.size() && tm--){
			res++;
			prt[szprt++]=(*s.begin()).F;
			s.erase(*s.begin());
		}
		for(auto x : dl[i]){
			if(s.count({A[x].S,x})==1){
				check=1;
			}
		}
		if(check==1){
			f(j,0,szprt) if(prt[j]>=vec[i]) res--;
			cout<<vec[i]-1<<" "<<res;
			exit(0);
		}
		for(auto x : ad[i]) s.insert({A[x].S,x});
		lst=vec[i];
	}
	cout<<-1<<" "<<res;
}