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

const int N=2e5+99;

int n,t,a[N],p[N],cnt[N],par[N],last[N];

int getpar(int u){
	if(par[u]<0) return u;
	return par[u]=getpar(par[u]);
}
void merge(int u,int v){
	u=getpar(u),v=getpar(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void add(int u,int v){
	p[u]=v;
	merge(u,v);
}
void do_it(int u,int v,int x,int y){
	if(getpar(u)==getpar(x) || getpar(v)==getpar(y)) swap(x,y);
	add(u,x);
	add(v,y);
}
void Main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int odd=0;
	f(i,1,n+1) odd+=bit(cnt[i],0);
	if(odd>1 || (bit(n,0)==1 && cnt[a[n/2+1]]==1)){
		cout<<"NO"<<'\n';
		return ;
	}
	cout<<"YES"<<'\n';
	int b=0;
	if(n&1){
		f(i,1,n+1) if(i!=n/2+1 && bit(cnt[a[i]],0)==1){
			b=i;
			add(n/2+1,i);
			break ;
		}
	}
	vector<pair<int,int>> vec;
	f(i,1,n+1){
		if(b==i) continue ;
		if(last[a[i]]>0){
			vec.pb({last[a[i]],i});
			last[a[i]]=0;
		}
		else{
			last[a[i]]=i;
		}
	}
	f(i,1,n/2+1){
		int u=i,v=n-i+1;
		pair<int,int> p1=vec.back(); vec.pop_back();
		if(vec.size() && ((getpar(p1.F)==getpar(u) && getpar(p1.S)==getpar(v)) || (getpar(p1.S)==getpar(u) && getpar(p1.F)==getpar(v)))){
			pair<int,int> p2=vec.back(); vec.pop_back();
			vec.pb(p1);
			do_it(u,v,p2.F,p2.S);
		}
		else{
			do_it(u,v,p1.F,p1.S);
		}
	}
	if(par[getpar(1)]!=-n) cout<<"EROR1",exit(0);
	f(i,1,n/2+1) if(a[p[i]]!=a[p[n-i+1]]) cout<<"EROR2",exit(0);
	f(i,1,n+1) cout<<p[i]<<" "; cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(par,par+N,-1);
	cin>>t;
	while(t--){
		Main();
		f(i,1,n+1) cnt[i]=0,par[i]=-1,last[i]=0;
	}
}