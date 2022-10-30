#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],s1[300500],s2[300500],it1,it2;
ll res;

struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	#define len (r-l+1ll)
	ll f[1200500],g[1200500],t[1200500];
	void upd(int id){
		f[id]=min(f[ls],f[rs]);
		g[id]=g[ls]*(f[ls]<=f[rs])+g[rs]*(f[ls]>=f[rs]);
	}
	void hb(int id){
		f[ls]+=t[id];t[ls]+=t[id];
		f[rs]+=t[id];t[rs]+=t[id];t[id]=0;
	}
	void build(int id,int l,int r){
		g[id]=len;if(l==r){return;}
		build(ls,l,md);build(rs,md+1,r);
	}
	void add(int id,int l,int r,int x,int y,int w){
		if(x<=l&&r<=y){
			f[id]+=w;t[id]+=w;return;
		}
		hb(id);
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);
		upd(id);
	}
	void get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			if(f[id]==0)res+=g[id];
			return;
		}
		hb(id);
		f[ls]-=t[id];t[ls]-=t[id];
		f[rs]-=t[id];t[rs]-=t[id];
		t[id]=0;
		if(x<=md)get(ls,l,md,x,y);
		if(y>md)get(rs,md+1,r,x,y);
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){cin>>j;cin>>a[j];}
	sb.build(1,1,n);
	for(i=1;i<=n;i++){
		while(it1&&a[i]>=a[s1[it1]]){sb.add(1,1,n,s1[it1-1]+1,s1[it1],-a[s1[it1]]);it1--;}
		while(it2&&a[i]<=a[s2[it2]]){sb.add(1,1,n,s2[it2-1]+1,s2[it2],a[s2[it2]]);it2--;}
		sb.add(1,1,n,s1[it1]+1,i,a[i]);s1[++it1]=i;
		sb.add(1,1,n,s2[it2]+1,i,-a[i]);s2[++it2]=i;
		sb.get(1,1,n,1,i);
		sb.add(1,1,n,1,i,-1);
	}
	cout<<res;
}