#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
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

const int N=2e5+99,sq=500;

int n,q,a[N],b[N],prt[N],L[N],R[N],lazy[N];
set<int> s;

inline int A(int x){
	return max(1ll,a[x]+lazy[x/sq]);
}
inline int B(int x){
	if(prt[A(x)]<prt[x]) return A(x);
	return b[x];
}
void upd(int l,int r){
	l=max(1ll,l-sq);
	r=min(n+1,r+sq);
	if(s.size()==0 || *s.rbegin()<l || *s.lower_bound(l)>=r) return ;
	int x=*s.lower_bound(l);
	while(1){
		int nxt=R[x];
		if(prt[A(x)]==prt[x]){
			b[x]=B(A(x));
		}
		else{
			s.erase(x);
			R[L[x]]=R[x];
			L[R[x]]=L[x];
		}
		if(nxt==0 || r<=nxt) break;
		x=nxt;
	}
}
void add(int l,int r,int val){
	while(l%sq!=0 && l<r) a[l++]-=val;
	while(r%sq!=0 && l<r) a[--r]-=val;
	while(l<r) lazy[l/sq]-=val,l+=sq;
}
int get(int u,int v){
	while(1){
		if(u>v) swap(u,v);
		if(prt[u]<prt[v]){
			v=B(v);
			if(v==u) return u;
		}
		else{
			if(B(u)==B(v)) break;
			u=B(u);
			v=B(v);
		}
	}
	while(u!=v){
		if(u>v) swap(u,v);
		v=A(v);
	}
	return u;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,1,N) prt[i]=(i+sq-2)/sq;
	cin>>n>>q;
	f(i,2,n+1){
		cin>>a[i];
		if(prt[a[i]]==prt[i]) b[i]=b[a[i]],s.insert(i);
		else b[i]=a[i];
	}
	for(auto x : s){
		if(x!=*s.rbegin()){
			int u=x,v=*s.upper_bound(x);
			R[u]=v;
			L[v]=u;
		}
	}
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int l,r,x;
			cin>>l>>r>>x; r++;
			add(l,r,x);
			upd(l,r);
		}
		else{
			int u,v;
			cin>>u>>v;
			cout<<get(u,v)<<'\n';
		}
	}
}