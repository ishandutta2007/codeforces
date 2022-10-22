#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int seg[mn*4],laz[mn*4];
void prop(int x){
	if(!laz[x])return;
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	seg[x]+=laz[x];
	laz[x]=0;
}
void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=max(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,int c){
	if(l==a&&r==b)laz[x]+=c;
	else{
		prop(x);
		if(b<=mid)upd(x*2,l,mid,a,b,c);
		else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
		else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
		eval(x);
	}
}
set<pll>s;
int num[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
   	int n,k,m;
   	cin>>n>>k>>m;
   	while(m--){
   		pll p;
   		cin>>p.first>>p.second;
   		int v=abs(k-p.first)+p.second;
   		cerr<<v<<endl;
   		if(s.count(p)){
   			num[v]--;
   			if(!num[v])upd(1,1,n*2,v,v,1-v);
   			upd(1,1,n*2,1,v,-1);
   			s.erase(p);
   		}
   		else{
			upd(1,1,n*2,1,v,1);
			if(!num[v])upd(1,1,n*2,v,v,v-1);
			num[v]++;
			s.insert(p);
   		}
   		prop(1);
   		ll ans=seg[1];
   		ans=max(0LL,ans-n);
   		printf("%lld\n",ans);
   	}
}