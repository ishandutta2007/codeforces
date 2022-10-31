#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500],a[200500],ty;
void add(int x,int y){for(;x<=200000;x+=(-x&x)){f[x]+=y;}}
ll get(int x,int y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
ll res,t1;

struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	ll f[800500],g[800500],h[800500],t[800500];
	void push(int id,int l,int r){
		h[ls]+=t[id]*g[ls]; f[ls]+=t[id]*(md-l+1); t[ls]+=t[id];
		h[rs]+=t[id]*g[rs]; f[rs]+=t[id]*(r-md); t[rs]+=t[id];
		t[id]=0;
	}
	void hb(int id,int l,int r){
		f[id]=f[ls]+f[rs];
		g[id]=g[ls]+g[rs];
		h[id]=h[ls]+h[rs];
	}
	void addf(int id,int l,int r,int x,int y,int w){
		if(x>y)return;
		if(x<=l&&r<=y){
			if(w>0)res+=h[id]*w;
			h[id]+=g[id]*w;
			f[id]+=(r-l+1)*w;
			t[id]+=w;
			if(w<0)res+=h[id]*w;
			return;
		}
		push(id,l,r);
		if(x<=md)addf(ls,l,md,x,y,w);
		if(y>md)addf(rs,md+1,r,x,y,w);
		hb(id,l,r);
	}
	void addg(int id,int l,int r,int x){
		if(l==r){
			g[id]^=1;
			h[id]=f[id]*g[id];
			return;
		}
		push(id,l,r);
		if(x<=md)addg(ls,l,md,x);
		else addg(rs,md+1,r,x);
		hb(id,l,r);
	}
}sb;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t>>n;
	while(t--){
		cin>>k;
		ty=(!a[k]?1:-1);
		sb.addf(1,1,200000,max(1,k-n),k-1,ty);
		sb.addg(1,1,200000,k);
		t1=get(min(200000,k+n))-get(k);
		res+=(t1*t1-t1)/2*ty;
		add(k,ty);
		a[k]^=1;
		cout<<res<<'\n';
	}
}