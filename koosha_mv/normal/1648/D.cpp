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

const int N=5e5+99,S=3,inf=1e17;

int n,ans=-inf,q,A[N],L[N],R[N],dp[N],val[N],a[N][S],ps[N][S];
vector<int> ad[N],dl[N];

struct node{
	int max,res,lazy;
	node(){
		max=res=lazy=-inf;
	}
} seg[N<<2];

void shift(int id){
	int p;
	p=id<<1;
	maxm(seg[p].lazy,seg[id].lazy);
	maxm(seg[p].res,seg[p].max+seg[id].lazy);
	p=id<<1|1;
	maxm(seg[p].lazy,seg[id].lazy);
	maxm(seg[p].res,seg[p].max+seg[id].lazy);
	seg[id].lazy=-inf;
}
void upd(int id){
	seg[id].max=max(seg[id<<1].max,seg[id<<1|1].max);
	seg[id].res=max(seg[id<<1].res,seg[id<<1|1].res);
}
void add(int x,int id=1,int l=1,int r=q+1){
	if(x<l || r<=x) return ;
	if(l+1==r){
		seg[id].max=-val[x];	
		seg[id].res=seg[id].lazy=-inf;
		return ;
	}
	int mid=(l+r)>>1;
	shift(id);
	add(x,id<<1,l,mid);
	add(x,id<<1|1,mid,r);
	upd(id);
}
void del(int x,int id=1,int l=1,int r=q+1){
	if(x<l || r<=x) return ;
	if(l+1==r){
		seg[id].res=seg[id].max=seg[id].lazy=-inf;
		return ;
	}
	int mid=(l+r)>>1;
	shift(id);
	del(x,id<<1,l,mid);
	del(x,id<<1|1,mid,r);
	upd(id);
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(j,0,S){
		f(i,1,n+1){
			cin>>a[i][j];
			ps[i][j]=ps[i-1][j]+a[i][j];
		}
	}
	
	f(i,1,n+1) A[i]=ps[i][0]-ps[i-1][1];
	
	f(i,1,q+1){
		cin>>L[i]>>R[i]>>val[i];
		ad[L[i]].pb(i);
		dl[R[i]].pb(i);
	}
	f(i,1,n+1){
		for(auto x : ad[i]){
			add(x);
		}
		maxm(seg[1].lazy,A[i]);
		maxm(seg[1].res,seg[1].max+seg[1].lazy);
		dp[i]=seg[1].res+ps[i][1];
		for(auto x : dl[i]){
			del(x);
		}
	}
	cout<<endl;
	set<pair<int,int>> st;
	dp[0]=-inf;
	f(i,1,n+1){
		for(auto x : ad[i]){
			st.insert({dp[i-1]-ps[i-1][1]-val[x],x});
		}
		if(st.size()){
			maxm(dp[i],(*st.rbegin()).F+ps[i][1]);
		}
		for(auto x : dl[i]){
			if(st.count({dp[L[x]-1]-ps[L[x]-1][1]-val[x],x})==0) assert(0);
			st.erase({dp[L[x]-1]-ps[L[x]-1][1]-val[x],x});
		}
		maxm(ans,dp[i]+ps[n][2]-ps[i-1][2]);
	}
	cout<<ans;
}