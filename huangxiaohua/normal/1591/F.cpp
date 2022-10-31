#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,op,a[500500],it=1;

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

class SB{
	public:
	ll f[12005000],t1[12005000],t2[12005000];
	int x,y,ls[12005000],rs[12005000];
	ll res;
	#define md ((l+r)>>1)
	#define get() f[id]=(f[ls[id]]+f[rs[id]])%M
	void up(int id,int l,int r,ll t3,ll t4){
		f[id]=f[id]*t4%M;
		f[id]=su(f[id],t3*(r-l+1)%M);
		t1[id]=(t1[id]*t4+t3)%M;
		t2[id]=t2[id]*t4%M;
	}
	void upd(int id,int l,int r){
		if(!ls[id]){
			ls[id]=++it;t2[it]=1;
		}
		if(!rs[id]){
			rs[id]=++it;t2[it]=1;
		}
		up(ls[id],l,md,t1[id],t2[id]);
		up(rs[id],md+1,r,t1[id],t2[id]);
		t1[id]=0;t2[id]=1;
	}
	void build(int id,int l,int r){
		t2[id]=1;
		if(l==r){
			f[id]=a[l];return;
		}
		if(!ls[id]){
			ls[id]=++it;t2[it]=1;
		}
		if(!rs[id]){
			rs[id]=++it;t2[it]=1;
		}
		build(ls[id],l,md);
		build(rs[id],md+1,r);
		get();
	}
	void add(int id,int l,int r,ll w){
		if(l==r){
			f[id]=su(f[id],w);return;
		}
		if(!ls[id]){
			ls[id]=++it;t2[it]=1;
		}
		if(!rs[id]){
			rs[id]=++it;t2[it]=1;
		}
		upd(id,l,r);
		if(x<=l&&r<=y){
			f[id]+=w*(r-l+1);f[id]%=M;
			t1[id]=su(t1[id],w);
			return;
		}
		if(x<=md)add(ls[id],l,md,w);
		if(y>md)add(rs[id],md+1,r,w);
		get();
	}
	void mul(int id,int l,int r,ll w){
		if(l==r){
			f[id]=f[id]*w%M;return;
		}
		if(!ls[id]){
			ls[id]=++it;t2[it]=1;
		}
		if(!rs[id]){
			rs[id]=++it;t2[it]=1;
		}
		
		upd(id,l,r);
		if(x<=l&&r<=y){
			f[id]=f[id]*w%M;
			t1[id]=t1[id]*w%M;
			t2[id]=t2[id]*w%M;
			return;
		}
		if(x<=md)mul(ls[id],l,md,w);
		if(y>md)mul(rs[id],md+1,r,w);
		get();
	}
	void que(int id,int l,int r){
		upd(id,l,r);
		if(x<=l&&r<=y){
			res=su(res,f[id]);
			return;
		}
		if(!ls[id]){
			ls[id]=++it;t2[it]=1;
		}
		if(!rs[id]){
			rs[id]=++it;t2[it]=1;
		}
		if(x<=md)que(ls[id],l,md);
		if(y>md)que(rs[id],md+1,r);
	}
}sb;

int main() {
	sb.t2[1]=1;
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
    sb.x=1;sb.y=a[1];
    sb.add(1,1,1000000000,1);
    for(i=2;i<=n;i++){
    	sb.res=0;
    	sb.que(1,1,1000000000);
    	ll tmp=sb.res%M;
    	sb.mul(1,1,1000000000,M-1);
    	sb.y=a[i];
    	sb.add(1,1,1000000000,tmp%M);
    	if(a[i]!=1000000000){
    		sb.x=a[i]+1;sb.y=1000000000;
    		sb.mul(1,1,1000000000,0);
		}
    	sb.x=1;sb.y=a[i];
	}
	sb.res=0;
	sb.que(1,1,1000000000);
	cout<<sb.res%M;
}