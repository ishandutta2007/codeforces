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
	int sum,lft,rit;
} tree[10001010];
long long ans;
int tlft,trit,rt[1001010],ansl,ansr,L[1001010],R[1001010],k;
int N,Testing,Vlen[1001010],Vstart[1001010],Vend[1001010];
long long i,lft,rit;
int sz,tag,l,r,mid,st[501010][22],lg[501010],j,mn,K,now;
int a[1001010],H[1001010],B[1001010],fre[1001010],n,sa[1001010],lst[1001010],rk[1001100],tot,len;
char SS[10],tmpS[1001010],S[1001010];
void sort(int l,int r){
	tot=0;
	for (i=n;i>n-len;i--) B[++tot]=i;
	for (i=1;i<=n;i++)
	    if (sa[i]>len) B[++tot]=sa[i]-len;
	for (i=1;i<=max(n,250);i++) fre[i]=0;
	for (i=1;i<=n;i++) fre[rk[B[i]]]++;
	for (i=1;i<=max(n,250);i++) fre[i]=fre[i-1]+fre[i];
	for (i=n;i>=1;i--) sa[fre[rk[B[i]]]--]=B[i];
}
void pushup(int x){
	tree[x].sum=(tree[tree[x].lft].sum+tree[tree[x].rit].sum);
}
void build(int x,int l,int r){
    if (l==r){
    	sz=max(sz,x);return ;
	}
	int mid=(l+r)>>1;
	tree[x].lft=x<<1;tree[x].rit=x<<1|1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
int modify(int x,int l,int r,int tx){
	if (l==r){sz++;tree[sz].sum=tree[x].sum+1;return sz;}
	int mid=(l+r)>>1;
	sz++;int lstg=sz;
	tree[sz].lft=tree[x].lft;tree[sz].rit=tree[x].rit;tree[sz].sum=tree[x].sum+1;
	if (tx<=mid) tree[sz].lft=modify(tree[x].lft,l,mid,tx);
	else tree[sz].rit=modify(tree[x].rit,mid+1,r,tx);
	pushup(x);
	return lstg;
}
int query(int xa,int xb,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr))  return tree[xb].sum-tree[xa].sum;
	int mid=(l+r)>>1;int ans=0;
	if (tl<=mid) ans=ans+query(tree[xa].lft,tree[xb].lft,l,mid,tl,tr);
	if (tr>mid) ans=ans+query(tree[xa].rit,tree[xb].rit,mid+1,r,tl,tr);
	return ans; 
}
int find(int l,int r){
	int len=lg[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);
}
int main()
{
 N=read();Testing=read();
 for (i=1;i<=N;i++){
 	scanf("%s",tmpS+1);len=strlen(tmpS+1);
 	Vstart[i]=n+1;
	 for (j=1;j<=len;j++) S[++n]=tmpS[j];
 	S[++n]='#';Vend[i]=n-1;Vlen[i]=len;
 }
 for (i=1;i<=n;i++) sa[i]=i;
 for (i=1;i<=n;i++) rk[i]=S[i];len=0;
 sort(1,n);
 for (i=1;i<=n;i++) lst[i]=rk[i];tot=0;
 for (i=1;i<=n;i++)
   if ((lst[sa[i]]==lst[sa[i-1]])&&(lst[sa[i]+len]==lst[sa[i-1]+len])) rk[sa[i]]=tot;
   else rk[sa[i]]=++tot;
 for (len=1;len<=n;len<<=1){
    sort(1,n);
 	for (i=1;i<=n;i++) lst[i]=rk[i];tot=0;
 	for (i=1;i<=n;i++)
 	    if ((lst[sa[i]]==lst[sa[i-1]])&&(lst[sa[i]+len]==lst[sa[i-1]+len])) rk[sa[i]]=tot;
 	    else rk[sa[i]]=++tot;
 }
  for (i=1;i<=n;i++){
 	if (rk[i]==0) continue;
 	if (now>0) now--;
 	while ((S[sa[rk[i]]+now]==S[sa[rk[i]-1]+now])&&(now<=n)) now++;
 	H[rk[i]]=now;
 }
 for (i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
 for (i=1;i<=n;i++) st[i][0]=H[i];
 for (j=1;j<=lg[n];j++)
    for (i=1;i<=n-(1<<j)+1;i++)
         st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
 rt[0]=1;build(1,1,n);
 for (i=1;i<=n;i++) rt[i]=modify(rt[i-1],1,n,rk[i]);
 for (i=1;i<=N;i++){
 	now=rk[Vstart[i]];
 	l=2;r=now;ansl=0;
 	while (l<=r){
 		mid=(l+r)>>1;
 		if (find(mid,now)>=Vlen[i]) ansl=mid,r=mid-1;
 		else l=mid+1;
	 }
	if (ansl==0) L[i]=now;else L[i]=ansl-1;
	l=now+1;r=n;R[i]=now;
	while (l<=r){
		mid=(l+r)>>1;
		if (find(now+1,mid)>=Vlen[i]) R[i]=mid,l=mid+1;
		else r=mid-1;
	}
 }
 for (;Testing;Testing--){
 	l=read();r=read();k=read();
	lft=L[k];rit=R[k];
	tlft=Vstart[l];trit=Vend[r];
	printf("%d\n",query(rt[tlft-1],rt[trit],1,n,lft,rit));
	}
 return 0;
}