#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 2e5+10;
const ll mod = 1e9+7;

ll seg[mn*4],laz[mn*4];
void prop(int x){
	if(!laz[x])return;
	seg[x]+=laz[x];
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	laz[x]=0;
}
void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=min(seg[x*2],seg[x*2+1]);
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

ll query(int x,int l,int r,int a,int b){
	prop(x);
	if(l==a&&r==b)return seg[x];
	else if(b<=mid)return query(x*2,l,mid,a,b);
	else if(a>mid)return query(x*2+1,mid+1,r,a,b);
	else return min(query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b));
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		upd(1,0,n-1,i,i,x);
	}
	int q;
	cin>>q;
	while(q--){
		vi in{0,0};
		cin>>in[0]>>in[1];
		if(cin.get()!=' '){
			ll ans;
			if(in[0]<=in[1])ans=query(1,0,n-1,in[0],in[1]);
			else ans=min(query(1,0,n-1,in[0],n-1),query(1,0,n-1,0,in[1]));
			printf("%lld\n",ans);
		}
		else{
			in.resize(3);
			cin>>in[2];
			if(in[0]<=in[1])upd(1,0,n-1,in[0],in[1],in[2]);
			else upd(1,0,n-1,in[0],n-1,in[2]),upd(1,0,n-1,0,in[1],in[2]);
		}
	}
}