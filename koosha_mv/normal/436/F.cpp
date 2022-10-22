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
#define pii pair<int,int>

const int N=1e5+1000,S=400;

struct CHT{
	vector<ll> s;
	vector<pair<ll,ll>> vec,alp;
	ll intersect(pii a,pii b){ // a.F<=b.F
		if(a.F==b.F) return 0;
		if(a.S<b.S) return 0;
		return (a.S-b.S)/(b.F-a.F)+((a.S-b.S)%(b.F-a.F)>0);
	}
	void push(pii a){
		alp.pb(a);
	}
	void build(){
		sort(all(alp));
		for(auto a : alp){
			while(vec.size() && intersect(vec.back(),a)<=s.back()){
				s.pop_back();
				vec.pop_back();
			}
			if(vec.size()==0){
				s.pb(0);
				vec.pb(a);
				continue ;
			}
			s.pb(intersect(vec.back(),a));
			vec.pb(a);
		}
	}
	ll get(ll x){
		ll pos=upper_bound(all(s),x)-s.begin()-1;
		return vec[pos].F*x+vec[pos].S;
	}
	void clear(){
		s.clear();
		alp.clear();
		vec.clear();
	}
} cht[N/S+9];

int n,w,mx,a[N],b[N],val[N],lazy[N/S+9];
vector<int> vec[N];

void add(int x){
	f(i,x/S*S,x+1) val[i]+=i;
	cht[x/S].clear();
	f(i,x/S*S,x/S*S+S){
		cht[x/S].push({i,val[i]});
	}
	cht[x/S].build();
	f(id,0,x/S) lazy[id]++;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<pii> ans;
	cin>>n>>w; 
	f(i,1,n+1){
		cin>>a[i]>>b[i];
		vec[b[i]].pb(a[i]);
		maxm(mx,b[i]+1);
	}
	f(i,0,N) cht[i/S].push({i,val[i]});
	f(i,0,(N-1)/S+1) cht[i].build();
	int cnt=n;
	f(i,0,mx+1){
		int chosen=0,res=0;
		f(id,0,(N-1)/S){
			if(cht[id].get(lazy[id])>=res){
				chosen=id;
				res=cht[id].get(lazy[id]);
			}
		}
		f(id,chosen*S,chosen*S+S){
			if(val[id]+lazy[chosen]*id==res){
				ans.pb({res+cnt*i*w,id});
				break;
			}
		}
		for(auto x : vec[i]){
			add(x);
			cnt--;
		}
	}
	for(auto x : ans) cout<<x.F<<" "<<x.S<<'\n';
}