#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll n,t,a,b,q,l,r,lc;
vector<ll> v;

bool check(ll x){
	if((x%a)%b==(x%b)%a) return 1;
	return 0;
}
ll calc(ll s,ll a,ll x){
	s--;
	ll p2=0,p1;
	p2=a/lc+(a%lc>=x);
	p1=s/lc+(s%lc>=x);
	return p2-p1;
}
ll solve(ll l1,ll r1){
	ll res=0;
	f(i,0,v.size())
		res+=calc(l1,r1,v[i]);
	return res;
}
int main(){
	cin>>t;
	while(t--){
		v.clear();
		cin>>a>>b>>q;
		lc=a*b/__gcd(a,b);
		f(i,0,lc){
			if(check(i))
				v.pb(i);
		}
		f(i,0,q){
			cin>>l>>r;
			cout<<r-l+1-solve(l,r)<<endl;
		}
	}
}