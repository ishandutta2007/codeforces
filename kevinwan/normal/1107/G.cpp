#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll seg[mn*4],laz[mn*4];
inline void prop(int x){
	if(!laz[x])return;
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	seg[x]+=laz[x];
	laz[x]=0;
}
inline void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=max(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,ll c){
	if(l==a&&r==b)laz[x]+=c;
	else{
		prop(x);
		if(b<=mid)upd(x*2,l,mid,a,b,c);
		else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
		else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
		eval(x);
	}
}
ll d[mn],c[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;ll a;
    cin>>n>>a;
    for(int i=1;i<=n;i++)cin>>d[i]>>c[i],c[i]=a-c[i];
    for(int i=1;i<=n;i++)d[i]=d[i+1]-d[i],d[i]*=d[i];
    upd(1,1,n,1,n,-inf);
	ll ans=0;
	stack<int>s;
	s.push(0);
	d[0]=inf;
	for(int i=1;i<=n;i++){
		upd(1,1,n,i,i,inf);
		upd(1,1,n,1,i,c[i]);
		prop(1);
		ans=max(ans,seg[1]);
		while(s.size()&&d[i]>d[s.top()]){
			int x=s.top();
			s.pop();
			upd(1,1,n,s.top()+1,x,-d[i]+d[x]);
		}
		s.push(i);
		upd(1,1,n,i,i,-d[i]);
	}
	printf("%lld",ans);
}