#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[1000500],b[1005000],c[1005000];

struct SB{
	#define ls (id<<1)
	#define rs (ls+1)
	#define md ((l+r)>>1)
	int f[4000500],t[4000500];
	void build(int id,int l,int r){
		if(l==r){
			f[id]=a[l];return;
		}
		build(ls,l,md);build(rs,md+1,r);
		f[id]=min(f[ls],f[rs]);
	}
	void push(int id,int l,int r){
		if(!t[id])return;
		t[ls]+=t[id];t[rs]+=t[id];
		f[ls]+=t[id];f[rs]+=t[id];
		t[id]=0;
	}
	void add(int id,int l,int r,int x,int y,int w){
		if(x>y)return;
		if(x<=l&&r<=y){
			f[id]+=w;t[id]+=w;return;
		}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);
		f[id]=min(f[ls],f[rs]);
	}
	int get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return f[id];
		}
		push(id,l,r);int res=2e9;
		if(x<=md)res=min(res,get(ls,l,md,x,y));
		if(y>md)res=min(res,get(rs,md+1,r,x,y));
		return res;
	}
	#undef md
}sb;

#define N 1000000

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>k;a[k]--;
		b[i]=k;
	}
	for(i=1;i<=m;i++){
		cin>>k;a[k]++;
		c[i]=k;
	}
	for(i=N;i>=1;i--)a[i]+=a[i+1];
	sb.build(1,1,N);
	cin>>t;
	while(t--){
		int ty,l,r,md,ans=0;
		cin>>ty>>l>>r;
		if(ty==1){
			sb.add(1,1,N,1,b[l],1);
			b[l]=r;
			sb.add(1,1,N,1,b[l],-1);
		}
		else{
			sb.add(1,1,N,1,c[l],-1);
			c[l]=r;
			sb.add(1,1,N,1,c[l],1);
		}
		l=1;r=N;
		while(l<=r){
			md=(l+r)/2;
			//printf("NMSL%d %d\n",md,sb.get(1,1,N,md,N));
			if(sb.get(1,1,N,md,N)<0){
				ans=max(ans,md);l=md+1;
			}
			else r=md-1;
		}
		if(!ans)cout<<"-1\n";
		else cout<<ans<<'\n';
	}
}