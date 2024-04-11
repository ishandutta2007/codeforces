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

const int N=15010,K=1010,mod=1e9+7,p=1e7+19;

int n,k,q,cntq,a[N],w[N],tdd[N],val[N],L[N],R[N],dp[N],Pow[N],res[N];
vector<int> vec[N<<2];

inline void upd(int w,int val){
	f_(i,k,w) maxm(dp[i],dp[i-w]+val);
}
void add(int L,int R,int x,int id=1,int l=1,int r=cntq+1){
	if(r<=L || R<=l) return ;
	if(L<=l && r<=R){
		vec[id].pb(x);
		return ;
	}
	int mid=(l+r)>>1;
	add(L,R,x,id<<1,l,mid);
	add(L,R,x,id<<1|1,mid,r);
}
void solve(int id=1,int l=1,int r=cntq+1){
	for(auto x : vec[id]) upd(w[x],val[x]);
	if(l+1==r){
		f(i,1,k+1){
			Add(res[l],1ll*dp[i]*Pow[i-1]%mod);
		}
		return ;
	}
	int mid=(l+r)>>1;
	vector<int> pd(k+1);
	f(i,1,k+1) pd[i]=dp[i];
	solve(id<<1,l,mid);
	f(i,1,k+1) dp[i]=pd[i];
	solve(id<<1|1,mid,r);
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Pow[0]=1;
	f(i,1,N) L[i]=1,Pow[i]=1ll*Pow[i-1]*p%mod;
	cin>>n>>k;
	f(i,1,n+1){
		L[i]=1;
		cin>>val[i]>>w[i];
	}
	cin>>q;
	int last=-1;
	f(i,0,q){
		int type,x;
		cin>>type;
		if(type==1){
			n++;
			cin>>val[n]>>w[n];
			L[n]=cntq+1;
		}
		if(type==2){
			cin>>x;
			R[x]=cntq+1;
		}
		if(type==3){
			if(last!=3) cntq++;
			tdd[cntq]++;
		}
		last=type;
	}
	f(i,1,n+1){
		if(R[i]==0) R[i]=cntq+1;
		add(L[i],R[i],i);
	}
	solve();	
	f(i,1,cntq+1){
		while(tdd[i]--){
			cout<<res[i]<<" ";
		}
	}
}