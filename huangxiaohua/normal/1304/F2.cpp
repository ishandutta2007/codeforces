#include<bits/stdc++.h>
#define maxn 40005
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
ll aa[maxn];
ll t[maxn*4],tag[maxn*4];
inline void refresh(int now){
	t[now]=max(t[now<<1],t[now<<1|1]);
}
void build(int l,int r,int now){
	if(l==r){
		t[now]=aa[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
	refresh(now);
}
void pushdown(int l,int r,int now){
	if(l==r){
		tag[now]=0;
		return;
	}
	tag[now<<1]+=tag[now];
	tag[now<<1|1]+=tag[now];
	int mid=(l+r)>>1;
	t[now<<1]+=tag[now];
	t[now<<1|1]+=tag[now];
	tag[now]=0;
}
void add(int l,int r,int now,int LL,int RR,int data){
	if(LL<=l&&r<=RR){
		t[now]+=data;
		tag[now]+=data;
		return;
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;
	if(LL<=mid) add(l,mid,now<<1,LL,RR,data);
	if(mid<RR) add(mid+1,r,now<<1|1,LL,RR,data);
	refresh(now);
}
int query(int l,int r,int now,int LL,int RR){
	if(LL<=l&&r<=RR){
		return t[now];
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;int ans=-1e9;
	if(LL<=mid) ans=max(query(l,mid,now<<1,LL,RR),ans);
	if(mid<RR) ans=max(ans,query(mid+1,r,now<<1|1,LL,RR));
	refresh(now);
	return ans;
}

int i,j,k,n,m;
int a[55][20500],pre[55][20500],f[55][20500],l,tmp,res;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			pre[i][j]=pre[i][j-1]+a[i][j];
		}
	}
	for(i=k;i<=m;i++){
		f[1][i]+=pre[1][i]-pre[1][i-k];
		f[1][i]+=pre[2][i]-pre[2][i-k];
		aa[i]=f[1][i];
	}
	build(1,m+m,1);
	for(j=1;j<=k;j++){
		add(1,m+m,1,j+k,m+m,a[2][j]);
	}
	int lim;
	for(i=2;i<=n;i++){
		for(j=k;j<=m;j++){
			f[i][j]=query(1,m+m,1,1,m+m)+pre[i+1][j]-pre[i+1][j-k];
			
			add(1,m+m,1,j+1,m+m,-a[i][j-k+1]);
			if(j<=m-k)add(1,m+m,1,j+k+1,m+m,a[i][j+1]);
			
			add(1,m+m,1,k,j,a[i][j+1]);
			if(j>=k+k)add(1,m+m,1,k,j-k,-a[i][j-k+1]);
		}
		for(j=1;j<=m;j++){
			aa[j]=f[i][j];
		}
		memset(tag,0,sizeof(tag));
		build(1,m+m,1);
		for(j=1;j<=k;j++){
			add(1,m+m,1,j+k,m+m,a[i+1][j]);
		}
		
	}
	for(i=1;i<=n;i++){
		for(j=k;j<=m;j++){
			res=max(res,f[i][j]);
		}
	}
	printf("%d",res);
	return 0;
}