#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];

struct TAG{
	int a[10];
	TAG(){for(int i=0;i<=9;i++)a[i]=i;}
	TAG operator +(const TAG &x){TAG res;for(int i=0;i<=9;i++){res.a[i]=x.a[a[i]];}return res;}
};

struct SB{
	ll a[10];
	SB(){memset(a,0,sizeof(a));}
	SB operator +(const SB &x){SB res;for(int i=0;i<=9;i++){res.a[i]=a[i]+x.a[i];}return res;}
	SB operator +(const TAG &x){SB res;for(int i=0;i<=9;i++){res.a[x.a[i]]+=a[i];}return res;}
	ll get(){ll res=0;for(int i=0;i<=9;i++){res+=a[i]*i;}return res;}
};

struct XDS{
	TAG t[400500],t0,w;
	SB f[400500];	
	#define ls (id<<1)
	#define rs (ls+1)
	#define md ((l+r)>>1)
	void build(int id,int l,int r){
		if(l==r){
			ll x=a[l],y=1;
			while(x){f[id].a[x%10]+=y;y*=10;x/=10;}
			return;
		}
		build(ls,l,md);build(rs,md+1,r);
		f[id]=f[ls]+f[rs];
	}
	void push(int id,int l,int r){
		f[ls]=f[ls]+t[id];t[ls]=t[ls]+t[id];
		f[rs]=f[rs]+t[id];t[rs]=t[rs]+t[id];
		t[id]=t0;
	}
	void add(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){f[id]=f[id]+w;t[id]=t[id]+w;return;}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y);
		if(y>md)add(rs,md+1,r,x,y);
		f[id]=f[ls]+f[rs];
	}
	ll get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y)return f[id].get();
		push(id,l,r);ll res=0;
		if(x<=md)res+=get(ls,l,md,x,y);
		if(y>md)res+=get(rs,md+1,r,x,y);
		return res;
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>a[i];
	sb.build(1,1,n);
	while(t--){
		int ty,l,r,x,y;
		cin>>ty;
		if(ty==1){
			cin>>l>>r>>x>>y;
			sb.w=sb.t0;
			sb.w.a[x]=y;
			sb.add(1,1,n,l,r);
		}
		else{
			cin>>l>>r;
			cout<<sb.get(1,1,n,l,r)<<'\n';
		}
	}
}