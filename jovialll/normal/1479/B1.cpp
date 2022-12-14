	#include<bits/stdc++.h>
	using namespace std;
	#define mod 998244353
	#define ll long long
	#define N 1000005
	#define pb push_back
	#define db double
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid (l+r>>1)
	int n,T,a[N],i,ans,j,mx[N],tg[N];
	void up(int k){
		mx[k]=max(mx[ls],mx[rs]);
	}
	void down(int k){
		mx[ls]+=tg[k];mx[rs]+=tg[k];
		tg[ls]+=tg[k];tg[rs]+=tg[k];
		tg[k]=0;
	}
	void FZ(int k,int l,int r,int x,int y){
		if(l==r){mx[k]=max(mx[k],y);return ;}
		down(k);
		if(x<=mid)FZ(ls,l,mid,x,y);
		else FZ(rs,mid+1,r,x,y);
		up(k);
	}
	void modify(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y){tg[k]+=v;mx[k]+=v;return ;}
		if(x>r||y<l)return ;down(k);
		modify(ls,l,mid,x,y,v);modify(rs,mid+1,r,x,y,v);up(k);
	}
	int maxx(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y){return mx[k];}
		if(x>r||y<l)return -1e9;down(k);
		return max(maxx(ls,l,mid,x,y),maxx(rs,mid+1,r,x,y));
	}
	int val;
	int main(){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		modify(1,0,n,0,n,-1e9);
		FZ(1,0,n,0,1);
		for(i=2;i<=n;++i){
			val=max(maxx(1,0,n,0,a[i]-1),maxx(1,0,n,a[i]+1,n));
			modify(1,0,n,0,n,a[i]!=a[i-1]);
			FZ(1,0,n,a[i-1],val+1);
		}
		cout<<maxx(1,0,n,0,n);
		return 0;
	}