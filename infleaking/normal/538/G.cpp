#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const ll N=2e6+10;
ll px[N],py[N],t[N],n,l;
vector<pi> d;
ll div0(ll x,ll y){
	if (y<0)x=-x,y=-y;
	return x/y-(x<0&&x%y);
}
ll div1(ll x,ll y){
	if (y<0)x=-x,y=-y;
	return div0(x+y-1,y);
}
ll pl,pr;
bool comp(pi a,pi b){
	return a.second%l<b.second%l;
}
pi solve(){
	ll al=-l,ar=l;
	d.push_back(d[0]);
	for (ll i=1;i<d.size();i++){
		ll t0=d[i].second%l-d[i-1].second%l;
		ll z0=d[i].second/l-d[i-1].second/l;
		if (t0<0)t0+=l,z0--;
		ll x1=d[i].first-d[i-1].first-t0,x2=x1+2*t0;
		if (!z0){
			if ((x1&1)||x1>0||x2<0)return make_pair(1e9,-1e9);
			continue;
		}
		if (z0&1){
			if ((x1&1)!=(l&1))
				return make_pair(1e9,-1e9);
		}
		else {
			if (x1&1)
				return make_pair(1e9,-1e9);
		}
		if (z0<0)swap(x1,x2);
		x1=div1(x1,z0),x2=div0(x2,z0);
		al=max(al,x1);
		ar=min(ar,x2);
	}
	return make_pair(al,ar);
}
ll ax[N],ay[N];
int main(){
	cin>>n>>l;
	for (ll i=1;i<=n;i++)
		scanf("%lld%lld%lld",&t[i],&px[i],&py[i]);
	for (ll i=0;i<=n;i++)d.push_back(make_pair(px[i]+py[i],t[i]));
	sort(d.begin(),d.end(),comp);
	pi p1=solve();
	if ((p1.first&1)==(l&1)&&p1.first==p1.second||p1.first<p1.second){
		ll k=p1.first+((p1.first&1)!=(l&1));
		for (ll i=0;i<d.size();i++)d[i].first-=k*(d[i].second/l),d[i].second%=l;
		d.pop_back();
		d.push_back(make_pair(k,l));
		for (ll i=1;i<d.size();i++){
			ll k=d[i].first-d[i-1].first,x=d[i].second-d[i-1].second;
			ll x1=x-k>>1,x2=x-x1;
			for (ll z=0;z<x1;z++)ax[z+d[i-1].second]=-1;
			for (ll z=x1;z<x;z++)ax[z+d[i-1].second]=1;
		}
		d.clear();
	}
	else {
		cout<<"NO"<<endl;
		return 0;
	}
	for (ll i=0;i<=n;i++)d.push_back(make_pair(px[i]-py[i],t[i]));
	sort(d.begin(),d.end(),comp);
	p1=solve();	
	if ((p1.first&1)==(l&1)&&p1.first==p1.second||p1.first<p1.second){
		ll k=p1.first+((p1.first&1)!=(l&1));
		for (ll i=0;i<d.size();i++)d[i].first-=k*(d[i].second/l),d[i].second%=l;
		d.pop_back();
		d.push_back(make_pair(k,l));
		for (ll i=1;i<d.size();i++){
			ll k=d[i].first-d[i-1].first,x=d[i].second-d[i-1].second;
			ll x1=x-k>>1,x2=x-x1;
			for (ll z=0;z<x1;z++)ay[z+d[i-1].second]=-1;
			for (ll z=x1;z<x;z++)ay[z+d[i-1].second]=1;
		}
		d.clear();
	}
	else {
		cout<<"NO"<<endl;
		return 0;
	}
	for (ll i=0;i<l;i++){
		if (ax[i]==1&&ay[i]==1)putchar('R');
		if (ax[i]==1&&ay[i]==-1)putchar('U');
		if (ax[i]==-1&&ay[i]==1)putchar('D');
		if (ax[i]==-1&&ay[i]==-1)putchar('L');
	}
}