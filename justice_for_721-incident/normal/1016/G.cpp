#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int n;
ll x,y;
ll gcd(ll u,ll v){
	if(v==0) return u;
	return gcd(v,u%v);
}
ll a[200001],b[200001];
map<ll,int>m,m2;
int p[200001];
ll c[1048576];
void spc(){
	ll z=y;
	int cnt=0;
	for(ll i=2; i*i<=z ;i++){
		if(z%i==0){
			while(z%i==0) z/=i;
			p[cnt]=i;
			cnt++;
		}
	}
	if(z!=1){
		p[cnt]=z;
		cnt++;
	}
	for(int i=1; i<=n ;i++){
		if(a[i]%x!=0) continue;
		ll num=gcd(a[i]/x,y/x);
		int msk=0;
		for(int j=0; j<cnt ;j++) msk|=(num%p[j]==0)<<j;
		c[msk]++;
	}
	for(int i=0; i<cnt ;i++){
		for(int j=0; j<(1<<cnt) ;j++){
			if((j&(1<<i))==0) c[j|(1<<i)]+=c[j];
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		if(y%a[i]!=0) continue;
		ll num=y/a[i];
		int msk=0;
		for(int j=0; j<cnt ;j++) msk|=(num%p[j]==0)<<j;
		ans+=c[((1<<cnt)-1)^msk];
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> x >> y;
	if(y%x!=0){
		cout << 0 << endl;
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]%x==0) m[gcd(a[i]/x,y/x)]++;
		if(y%a[i]==0) m2[y/a[i]]++;
	}
	ll ans=0;
	if(m.size()>5000 || m2.size()>5000){
		spc();
		return 0;
	}
	for(auto it=m.begin(); it!=m.end() ;++it){
		for(auto it2=m2.begin(); it2!=m2.end() ;++it2){
			if(gcd(it->first,it2->first)==1) ans+=1LL*it->second*it2->second;
		}
	}
	cout << ans << endl;
}