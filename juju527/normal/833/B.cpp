#include<bits/stdc++.h>
using namespace std;
const int maxn=35005,maxk=55;
int n,k;
int a[maxn],lst[maxn],pre[maxn];
int dp[maxn][maxk];
int mx[maxn<<2],laz[maxn<<2];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void pushup(int k){
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
	return ;
}
void add_laz(int k,int v){
	laz[k]+=v;
	mx[k]+=v;
	return ;
}
void pushdown(int k){
	if(!laz[k])return ;
	add_laz(k<<1,laz[k]);
	add_laz(k<<1|1,laz[k]);
	laz[k]=0;
	return ;
}
void build(int k,int l,int r,int p){
	if(l==r){
		mx[k]=dp[l][p];
		return ;
	}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid,p);
	build(k<<1|1,mid+1,r,p);
	laz[k]=0;
	pushup(k);
	return ;
}
void modify(int k,int l,int r,int x,int y,int val){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		add_laz(k,val);
		return ;
	}
	int mid=l+((r-l)>>1);
	pushdown(k);
	modify(k<<1,l,mid,x,y,val);
	modify(k<<1|1,mid+1,r,x,y,val);
	pushup(k);
	return ;
}
int query(int k,int l,int r,int x,int y){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return mx[k];
	int mid=l+((r-l)>>1);
	pushdown(k);
	return max(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
}
bool vis[maxn];
int main(){
	n=read();k=read();
	int num=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		lst[i]=pre[a[i]];
		pre[a[i]]=i;
		if(!vis[a[i]])num++;
		vis[a[i]]=1;
		dp[i][1]=num;
//		cout<<lst[i]<<" ";
	}
//	cout<<endl;
	build(1,1,n,1);
	for(int l=2;l<=k;l++){
		for(int i=1;i<=n;i++){
			modify(1,1,n,lst[i],i-1,1);
//			cout<<"*"<<lst[i]<<" "<<i-1<<endl;
//			for(int j=1;j<=n;j++)cout<<query(1,1,n,j,j)<<" ";cout<<endl;
			if(i>=l)dp[i][l]=query(1,1,n,1,i-1);
		}
//		cout<<l<<": ";
//		for(int i=1;i<=n;i++)cout<<dp[i][l]<<" ";cout<<endl;
		build(1,1,n,l);
	}
	printf("%d\n",dp[n][k]);
	return 0;
}