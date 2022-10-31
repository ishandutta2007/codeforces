#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k;
ll seed,sed,a[100500],op,l,r,x,y,val[100500];
ll ksm(ll a,ll p,ll M){
	ll res=1%M;a%=M;
	while(p){
		if(p&1)res=res*a%M;
		a=a*a%M;p>>=1;
	}
	return res;
}
#define M 1000000007
ll rng(){
	ll ret=seed;
	seed=(seed*7+13)%M;
	return ret;
}

struct SB{
	set<ll>s;
	
	void add(ll l,ll r,ll x){
		auto it=s.lower_bound(l),it1=it;
		it1--;
		if((*it1)<l-1){
			val[l-1]=val[*it];s.insert(l-1);
		}
		while(1){
			if((*it)>=r){
				val[r]=val[*it]+x;
				s.insert(r);
				return;
			}
			val[*it]+=x;
			it++;
		}
	}
	
	void ass(ll l,ll r,ll x){
		auto it=s.lower_bound(l),it1=it;
		it1--;
		if((*it1)<l-1){
			val[l-1]=val[*it];s.insert(l-1);
		}
		while(1){
			if((*it)>=r){
				s.insert(r);
				val[r]=x;
				return;
			}
			it1=it;it1++;
			s.erase(it);it=it1;
		}
	}
	
	ll ask1(ll l,ll r,ll x){
		ll res=0,sum=0,lst=l-1;
		multiset<pair<ll,ll > >st;
		auto it=s.lower_bound(l);
		while(1){
			if((*it)>=r){
				st.insert({val[*it],r-lst});
				break;
			}
			st.insert({val[*it],(*it)-lst});
			lst=(*it);it++;
		}
		for(auto [i,j]:st){
			sum+=j;
			if(sum>=x)return i;
		}
		exit(1);
	}
	
	ll ask2(ll l,ll r,ll x,ll y){
		ll res=0,lst=l-1;
		multiset<pair<ll,ll > >st;
		auto it=s.lower_bound(l);
		while(1){
			if((*it)>=r){
				st.insert({val[*it],r-lst});
				break;
			}
			st.insert({val[*it],(*it)-lst});
			lst=(*it);it++;
		}
		for(auto [i,j]:st){
			res+=j*ksm(i,x,y);
			res%=y;
		}
		return res;
	}
}sb;

int main() {
	cin>>n>>m>>seed>>sed;
	sb.s.insert(0);
	sb.s.insert(n);
	sb.s.insert(n+1);
	for(i=1;i<=n;i++){
		sb.ass(i,i,(rng()%sed)+1);
	}
	for(i=1;i<=m;i++){
		op=(rng()%4)+1;
		l=(rng()%n)+1;
		r=(rng()%n)+1;
		if(l>r)swap(l,r);
		if(op==3) x=(rng()%(r-l+1))+1;
		else x=(rng()%sed)+1;
		if(op==4)y=(rng()%sed)+1;
		
		if(op==1)sb.add(l,r,x);
		if(op==2)sb.ass(l,r,x);
		if(op==3)printf("%lld\n",sb.ask1(l,r,x));
		if(op==4)printf("%lld\n",sb.ask2(l,r,x,y));
	}
}