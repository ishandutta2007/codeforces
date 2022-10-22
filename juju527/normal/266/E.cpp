#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005,maxm=100005,mod=1e9+7;
struct node{
	int val;
	int s[6];
	int tot;
}tree[4*maxn],zero;
int n,m;
int a[maxn];
int sum[maxn][6];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1){ans*=x;ans%=mod;}
		x*=x;x%=mod;
		b>>=1;
	}
	return ans;
}
void add(int k,int l,int r,int val){
	tree[k].val=val;
	tree[k].s[0]=(r-l+1)*val%mod;
	tree[k].s[1]=((sum[r][1]-sum[l-1][1])*val%mod+mod)%mod;
	tree[k].s[2]=((sum[r][2]-sum[l-1][2])*val%mod+mod)%mod;
	tree[k].s[3]=((sum[r][3]-sum[l-1][3])*val%mod+mod)%mod;
	tree[k].s[4]=((sum[r][4]-sum[l-1][4])*val%mod+mod)%mod;
	tree[k].s[5]=((sum[r][5]-sum[l-1][5])*val%mod+mod)%mod;
	return ;
}
void pushdown(int k,int l,int r){
	if(tree[k].val==-1)return ;
	int mid=l+((r-l)>>1);
	add(k<<1,l,mid,tree[k].val);
	add(k<<1|1,mid+1,r,tree[k].val);
	tree[k].val=-1;
	return ;
}
node update(node ls,node rs){
	if(ls.tot==-1)return rs;
	if(rs.tot==-1)return ls;
	node k;
	int tot=ls.tot;
	k.s[0]=ls.s[0]+rs.s[0];
	k.s[1]=ls.s[1]+rs.s[1];
	k.s[2]=ls.s[2]+rs.s[2];
	k.s[3]=ls.s[3]+rs.s[3];
	k.s[4]=ls.s[4]+rs.s[4];
	k.s[5]=ls.s[5]+rs.s[5];
	k.s[0]%=mod;k.s[1]%=mod;k.s[2]%=mod;k.s[3]%=mod;k.s[4]%=mod;k.s[5]%=mod;
	k.tot=ls.tot+rs.tot;
	if(ls.val==rs.val&&ls.val!=-1)k.val=ls.val;
	else k.val=-1;
	return k;
}
void build(int k,int l,int r){
	if(l==r){
		tree[k].val=-1;
		tree[k].s[0]=a[l]%mod;
		tree[k].s[1]=a[l]*l%mod;
		tree[k].s[2]=a[l]*l%mod*l%mod;
		tree[k].s[3]=a[l]*l%mod*l%mod*l%mod;
		tree[k].s[4]=a[l]*l%mod*l%mod*l%mod*l%mod;
		tree[k].s[5]=a[l]*l%mod*l%mod*l%mod*l%mod*l%mod;
		tree[k].tot=1;
		return ;
	}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=update(tree[k<<1],tree[k<<1|1]);
	return ;
}
void modify(int k,int l,int r,int x,int y,int val){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		add(k,l,r,val);
		return ;
	}
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	modify(k<<1,l,mid,x,y,val);
	modify(k<<1|1,mid+1,r,x,y,val);
	tree[k]=update(tree[k<<1],tree[k<<1|1]);
}
node query(int k,int l,int r,int x,int y){
	if(l>y||r<x)return zero;
	if(l>=x&&r<=y)return tree[k];
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	node p=query(k<<1,l,mid,x,y),q=query(k<<1|1,mid+1,r,x,y);
	return update(p,q);
}
int getans(node k,int x,int p){
/*
	cout<<"*"<<k.s[0]<<endl;
	cout<<"*"<<k.s[1]<<endl;
	cout<<"*"<<k.s[2]<<endl;
	cout<<"*"<<k.s[3]<<endl;
	cout<<"*"<<k.s[4]<<endl;
	cout<<"*"<<k.s[5]<<endl;
*/
	if(x==0)
		return k.s[0]%mod;
	else if(x==1)
		return (k.s[1]+p%mod*k.s[0])%mod;
	else if(x==2)
		return ((k.s[2]+2*p%mod*k.s[1]%mod)%mod+p%mod*p%mod*k.s[0]%mod)%mod;
	else if(x==3)
		return (((k.s[3]+3*p%mod*k.s[2]%mod)%mod+3*p%mod*p%mod*k.s[1]%mod)%mod+p%mod*p%mod*p%mod*k.s[0]%mod)%mod;
	else if(x==4)
		return ((((k.s[4]+4*p%mod*k.s[3]%mod)%mod+6*p%mod*p%mod*k.s[2]%mod)%mod+4*p%mod*p%mod*p%mod*k.s[1]%mod)%mod+p%mod*p%mod*p%mod*p%mod*k.s[0]%mod)%mod;
	else
		return (((((k.s[5]+5*p%mod*k.s[4]%mod)%mod+10*p%mod*p%mod*k.s[3]%mod)%mod+10*p%mod*p%mod*p%mod*k.s[2]%mod)%mod+5*p%mod*p%mod*p%mod*p%mod*k.s[1])%mod+p%mod*p%mod*p%mod*p%mod*p%mod*k.s[0])%mod;
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
	zero.s[0]=zero.s[1]=zero.s[2]=zero.s[3]=zero.s[4]=zero.s[5]=0;
	zero.tot=-1;
	for(int j=1;j<=5;j++){
		for(int i=1;i<=n;i++){
			sum[i][j]=sum[i-1][j]+power(i,j);
			sum[i][j]%=mod;
		}
	}
	for(int i=1;i<=m;i++){
		char opt;
		int l,r,x;
		cin>>opt;
		l=read();r=read();x=read();
		if(opt=='=')modify(1,1,n,l,r,x);
		else printf("%lld\n",(getans(query(1,1,n,l,r),x,1-l)+mod)%mod);
	}
	return 0;
}