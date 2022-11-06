#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
struct node{
	int mx,mn;
} tree[32][801010];
int final,x,j,k,i,Testing,l,r,ans,opt,n,K,a[401010][32],b[100];
void pushup(int x){
	for (int i=0;i<=final;i++) tree[i][x].mx=max(tree[i][x<<1].mx,tree[i][x<<1|1].mx),tree[i][x].mn=min(tree[i][x<<1].mn,tree[i][x<<1|1].mn);
	return;
}
void build(int x,int l,int r){
	if (l==r){
		for (int i=0;i<=final;i++) tree[i][x].mx=tree[i][x].mn=a[l][i];
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);
}
void modify(int x,int l,int r,int tx){
	if (l==r){
		for (int i=0;i<=final;i++) tree[i][x].mx=tree[i][x].mn=a[l][i];
		return ;
	}
	int mid=(l+r)>>1;
	if (tx<=mid) modify(x<<1,l,mid,tx);else modify(x<<1|1,mid+1,r,tx);
	pushup(x);
}
int querymax(int opt,int x,int l,int r,int tl,int tr){
	
	if ((l>=tl)&&(r<=tr)) return tree[opt][x].mx;
	int mid=(l+r)>>1,ans=-1e9;
	if (tl<=mid) ans=max(ans,querymax(opt,x<<1,l,mid,tl,tr));
	if (tr>mid) ans=max(ans,querymax(opt,x<<1|1,mid+1,r,tl,tr));
	return ans;
}
int querymin(int opt,int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) return tree[opt][x].mn;
	int mid=(l+r)>>1,ans=1e9;
	if (tl<=mid) ans=min(ans,querymin(opt,x<<1,l,mid,tl,tr));
	if (tr>mid) ans=min(ans,querymin(opt,x<<1|1,mid+1,r,tl,tr));
	return ans;
}
int main(){
	n=read();K=read();final=(1<<K)-1;
	for (i=1;i<=n;i++){
		for (j=1;j<=K;j++) b[j]=read();
		for (j=0;j<=final;j++)
		   for (k=1;k<=K;k++)
		      if (j&(1<<(k-1))) a[i][j]+=b[k];else a[i][j]-=b[k];
	}
    build(1,1,n);
    Testing=read();
    for (;Testing;Testing--){
    	opt=read();
    	if (opt==1){
    		x=read();
		    for (j=1;j<=K;j++) b[j]=read();
		    for (j=0;j<=final;j++) a[x][j]=0;
		    for (j=0;j<=final;j++)
		       for (k=1;k<=K;k++)
		           if (j&(1<<(k-1))) a[x][j]+=b[k];else a[x][j]-=b[k];
    		modify(1,1,n,x);
		}
		if (opt==2){
			l=read();r=read();ans=0;
			for (i=0;i<=final;i++) ans=max(ans,querymax(i,1,1,n,l,r)-querymin(i,1,1,n,l,r));
			printf("%d\n",ans);
		}
	}
return 0;
}
/*
1
\sum_{i=1}^{5} max(x[a][i]-y[a][i],y[a][i]-x[a][i])
32||
 

x1-x2+y1-y2=x1+y1-(x2+y2(
x1-x2+y2-y1=(x1-y1)-(x2-y2)=

x1-x2+y1-y2
*/