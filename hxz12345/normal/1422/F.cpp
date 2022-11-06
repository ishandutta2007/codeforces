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
struct SegmentTree{
	int l,r;long long val;
} tree[101010*30];
char st[88][100010][18];
long long lst,pw[333][333],G1,G2,G3;
int tag[201010],rt[201010],l,r,Testing,MOD,lg[201010],k,id,pre[201010],a[201010],i,len,n,up,j,prim[201010];
bool vis[201010];
void pushup(int x){tree[x].val=(tree[tree[x].l].val*tree[tree[x].r].val) % MOD;}
void build(int x,int l,int r){tree[x].l=x*2;tree[x].r=x*2+1;id=max(id,x);if (l==r){if (l==pre[1]+1) tree[x].val=a[1];else tree[x].val=1;return ;}int mid=(l+r)>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);}
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % p;
	return ans;
}
long long query(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) return tree[x].val;
	long long ans=1,mid=(l+r)>>1;
	if (tl<=mid) ans=ans*query(tree[x].l,l,mid,tl,tr) % MOD;
	if (tr>mid) ans=ans*query(tree[x].r,mid+1,r,tl,tr) % MOD;
	return ans;
}
int modify(int x,int l,int r,int tx,int val){int now;
	 id++;now=id;
	 if (l==r){id++;tree[id].val=tree[x].val*val % MOD;return id;}
	 int mid=(l+r)>>1;
	 if (tx<=mid) tree[now].r=tree[x].r,tree[now].l=modify(tree[x].l,l,mid,tx,val);
	 else tree[now].l=tree[x].l,tree[now].r=modify(tree[x].r,mid+1,r,tx,val);
	 pushup(now);return now;
}
short int findmax(int x,int l,int r){
	int len=lg[r-l+1];
	return max(st[x][l][len],st[x][r-(1<<len)+1][len]);
}
int main()
{
	n=read();MOD=1e9+7;
	up=sqrt(200000);
	for (i=2;i<=up;i++){
		if (vis[i]==false) prim[++len]=i;
		for (j=1;j<=len&&i*prim[j]<=200000;j++){
			vis[i*prim[j]]=true;
			if (i % prim[j]==0) break;
		}
	}
	for (i=1;i<=n;i++){
		a[i]=read();
		for (j=1;j<=len;j++)
		    while (a[i] % prim[j]==0){
		    	st[j][i][0]++;
				a[i]/=prim[j];
			}
	}
	for (i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (k=1;k<=len;k++)
	     for (j=1;j<=lg[n];j++)
	         for (i=1;i<=n-(1<<j)+1;i++)
	             st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1]);
	for (i=1;i<=len;i++){pw[i][0]=1;for (j=1;j<=20;j++) pw[i][j]=pw[i][j-1]*prim[i] % MOD;}
	for (i=1;i<=n;i++) pre[i]=tag[a[i]],tag[a[i]]=i;
	build(1,1,n);rt[1]=1;
	for (i=2;i<=n;i++) rt[i]=modify(rt[i-1],1,n,pre[i]+1,a[i]);
	Testing=read();
	for (;Testing;Testing--){
		l=read();r=read();G3=1;
		l=(l+lst) % n+1;r=(r+lst) % n+1;
		if (l>r) swap(l,r);
		for (j=1;j<=len;j++) 
		    G3=G3*pw[j][findmax(j,l,r)] % MOD;
		if (l==1) lst=query(rt[r],1,n,1,l)*G3 % MOD,printf("%lld\n",lst);
		else {
			G1=query(rt[r],1,n,1,l);
			G2=query(rt[l-1],1,n,1,l);
			G1=G1*pow(G2,MOD-2,MOD) % MOD;
			printf("%lld\n",G1*G3 % MOD);
			lst=G1*G3 % MOD;
		}
	}
	return 0;
}
/*



pre<l
[l,r]pre[i]<l
[l,r][1,l-1] [1,r]


 
*/