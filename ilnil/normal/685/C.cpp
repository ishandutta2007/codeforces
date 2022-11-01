#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fo2(i,a,b)for(ll i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
struct nod{
	ll x,y,z;
}a[N],ans;
void get(ll *le,ll *ri,int o,ll x,ll mid){
	le[o]=max(le[o],x-mid);
	ri[o]=min(ri[o],x+mid);
}
ll div(ll x){return x<0?(x-1)/2:x/2;}
bool ck(ll mid){
	ll le[4],ri[4];
	fo(i,0,3)le[i]=-8e18,ri[i]=8e18;
	fo(i,1,n)
		fo(p,0,1)
			fo(q,0,1)
				get(le,ri,p*2+q,a[i].x+(p?-a[i].y:a[i].y)+(q?-a[i].z:a[i].z),mid);
	fo(i,0,3)if(le[i]>ri[i])return 0;
	ll mn=max(div(le[1]+le[2]+1),div(le[0]+le[3]+1)),mx=min(div(ri[1]+ri[2]),div(ri[0]+ri[3]));
	ll x,y,z;
	for(x=mn;x<=mx;++x){
		for(y=max(le[0]-x,x-ri[3]);y<=min(ri[0]-x,x-le[3]);++y){
			for(z=max(le[1]-x,x-ri[2]);z<=min(ri[1]-x,x-le[2]);++z)
				if(~(y-z)&1)break;
			if(z<=min(ri[1]-x,x-le[2]))break;
		}
		if(y<=min(ri[0]-x,x-le[3]))break;
	}
	if(x<=mx){
		ans=(nod){x,(y+z)/2,(y-z)/2};
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	for(cin>>T;T--;){
		cin>>n;
		fo(i,1,n)cin>>a[i].x>>a[i].y>>a[i].z;
		for(ll l=0,r=3e18,mid;mid=l+r>>1,l<=r;)
			if(ck(mid))r=mid-1;else l=mid+1;
		printf("%lld %lld %lld\n",ans.x,ans.y,ans.z);
	}
}