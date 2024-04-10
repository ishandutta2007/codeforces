#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,sb,x,y,z;
map<ll,ll> mp,mp2;

void fuck(ll x){
	mp.clear();mp2.clear();mp[-x]=1;
	while(1){
		auto [xx,yy]=*mp.begin();mp.erase(mp.begin());
		x=-xx;y=yy;z=-(x-1)/2;
		if(x<=0)return;
		mp[z]+=y;mp2[z]+=y;mp[-(x-1+z)]+=y;
	}
}

int main() {
	cin>>n>>m;
	if(m<=2){cout<<((m==1)?1:n);return 0;}
	m-=2;fuck(n-2);
	for(auto [i,j]:mp2){
		if(j>=m){sb=-i;break;}m-=j;
	}
	ll l=1,r=n,md;
	while(1){
		if((r-l-2)/2==sb)if(!--m){cout<<(l+r)/2;return 0;}
		md=(l+r)/2;fuck(md-l-1);
		if(mp2[-sb]>=m)r=md;else l=md,m-=mp2[-sb];
	}
}