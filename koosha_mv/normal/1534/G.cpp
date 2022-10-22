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

typedef pair<int,int> pii;

const int N=1e6+99;

int n,t,cnt,a[N];
ll ans;
set<pii> s0,s1;
vector<pii> vec;

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		int x,y;
		cin>>x>>y;
		vec.pb({x,y});
	}
	sort(all(vec),[&](pii u,pii v){ return u.F+u.S<v.F+v.S; });
	s0.insert({vec[0].F,cnt++});
	s1.insert({vec[0].S,cnt++});
	ans=vec[0].F;
	f(i,1,vec.size()){
		int x=vec[i].F,y=vec[i].S;
		ans+=x;
		if(x<=(*s0.rbegin()).F){
			pair<int,int> p=(*s0.rbegin());
			s0.insert({x,cnt++});
			s0.insert({x,cnt++});
			s0.erase(p);
			s1.insert({x+y-p.F,p.S});
		}
		else if(y<=(*s1.rbegin()).F){
			pii p=(*s1.rbegin());
			s1.insert({y,cnt++});
			s1.insert({y,cnt++});
			s1.erase(p);
			s0.insert({x+y-p.F,p.S});
		}
		else{
			s0.insert({x,cnt++});
			s1.insert({y,cnt++});
		}
	}
	for(auto x : s0) ans-=x.F;
	cout<<ans;
}