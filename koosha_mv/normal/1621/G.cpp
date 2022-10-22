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
 
const int N=4e5+99,mod=1e9+7;
 
struct Fenwik{
	vector<int> fenwik,vec;
	int n;
	Fenwik(int _n){
		n=_n+9;
		fenwik.resize(n);
	}	
	void add(int x, int val){
		vec.pb(x);
		for(x++;x<n;x+=x&-x){
			fenwik[x]+=val;
			if(fenwik[x]>=mod) fenwik[x]-=mod;
		}
	}
	int get(int x){
		int res=0;
		for (x++;x>0;x-=x&-x){
			res+=fenwik[x];
			if(res>=mod) res-=mod;
		}
		return res;
	}
	void clear(){
		for(auto x : vec){
			for(x++;x<n;x+=x&-x){
				fenwik[x]=0;
			}
		}
		vec.clear();
	}
} ;
 
int n,t,ans,a[N],dp[N],pd[N];
 
void read(){
	vector<pair<int,int> > vec;
	cin>>n;
	f(i,0,n){ cin>>a[i]; vec.pb({a[i],-i}); }
	sort(all(vec));
	f(i,0,n){ a[i]=lower_bound(all(vec),mp(a[i],-i))-vec.begin()+1; }
}
void find_dp(){
	Fenwik Fen(n);
	Fen.add(0,1);
	f(i,0,n){
		dp[i]=Fen.get(a[i]-1);
		Fen.add(a[i],dp[i]);
	}
	Fen.clear();
	Fen.add(0,1);
	f_(i,n-1,0){
		int x=n-a[i]+1;
		pd[i]=Fen.get(x-1);
		Fen.add(x,pd[i]);
	}
	f(i,0,n){
		Add(ans,1ll*dp[i]*pd[i]%mod);
	}
}
void solve(){
	int mx=0;
	set<int> s;
	Fenwik fenwik(n);
	f_(i,n-1,0){
		if(s.size()==0 || a[i]>*s.rbegin()){
			fenwik.add(a[i],1);
			s.insert(a[i]);
			Add(ans,mod-dp[i]);
		}
		else{
			int x=*s.lower_bound(a[i]),res=(fenwik.get(x)-fenwik.get(a[i])+mod)%mod;
			fenwik.add(a[i],res);
			Add(ans,mod-1ll*res*dp[i]%mod);
		}
	}
}
void Main(){
	ans=0;
	read();
	find_dp();
	solve();
	cout<<ans<<'\n';
}
 
main(){
	cin>>t;
	while(t--){
		Main();
	}
}