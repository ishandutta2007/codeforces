#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=800010;
ll n,k,a,b,q,s[N],sa[N],sb[N];
#define lc k<<1
#define rc lc|1
#define mid (l+r>>1)
void upd(int x,ll v,int k=1,int l=1,int r=n){
	if(l>x||r<x)return;
	if(l==r){
		sa[k]=min(v,a),sb[k]=min(v,b);
		return;
	}
	upd(x,v,lc,l,mid),upd(x,v,rc,mid+1,r);
	sa[k]=sa[lc]+sa[rc],sb[k]=sb[lc]+sb[rc];
}
ll qrya(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return sa[k];
	return qrya(x,y,lc,l,mid)+qrya(x,y,rc,mid+1,r);
}
ll qryb(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return sb[k];
	return qryb(x,y,lc,l,mid)+qryb(x,y,rc,mid+1,r);
}
signed main(){
	cin>>n>>k>>a>>b>>q;
	while(q--){
		int o,d,x;
		cin>>o>>d;
		if(o==1)cin>>x,upd(d,s[d]+=x);
		else cout<<qryb(1,d-1)+qrya(d+k,n)<<'\n';
	}
	return 0;
}