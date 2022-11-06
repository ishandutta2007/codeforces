#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
const ll N=400000;
ll n,m,x[N],s[N];
void pu(ll c){
	x[c]=max(x[c<<1],x[c<<1|1]);
	s[c]=s[c<<1]+s[c<<1|1];
}
void build(ll l,ll r,ll c){
	if(l==r){cin>>s[c];x[c]=s[c];return;}
	build(l,mid,c<<1);build(mid+1,r,c<<1|1);
	pu(c);
}
void md(ll l,ll r,ll L,ll R,ll v,ll c){
	if(r<L||R<l||x[c]<v)return;
	if(l==r){s[c]%=v,x[c]%=v;return;}
	md(l,mid,L,R,v,c<<1);md(mid+1,r,L,R,v,c<<1|1);
	pu(c);
}
void upd(ll l,ll r,ll a,ll v,ll c){
	if(l==r){s[c]=x[c]=v;return;}
	if(a<=mid)upd(l,mid,a,v,c<<1);
	else upd(mid+1,r,a,v,c<<1|1);
	pu(c);
}
ll query(ll l,ll r,ll L,ll R,ll c){
	if(r<L||R<l)return 0;
	if(L<=l&&r<=R)return s[c];
	return query(l,mid,L,R,c<<1)+query(mid+1,r,L,R,c<<1|1);
}
int main(){
	//freopen("input.txt","r",stdin);
	cin>>n>>m;
	build(1,n,1);
	while(m--){
		ll p,a,b,c;
		cin>>p>>a>>b;
		switch(p){
			case 1:cout<<query(1,n,a,b,1)<<endl;break;
			case 2:cin>>c;md(1,n,a,b,c,1);break;
			case 3:upd(1,n,a,b,1);break;
		}
	}
	return 0;
}