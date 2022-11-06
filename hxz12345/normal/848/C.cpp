#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
set<int> col[101000];
struct point{
	int l,r,val,id;
} b[1001010];
long long E1[1001010],ff[1001010];
int tq,pp[1001010],now,opt,l,r,i,tn,suf[1001010],vsuf[1001010];
int m,a[1001010],pre[1001010],vpre[1001010],n,v1,v2,vl,vr;
bool cmp(point a,point b){
	return a.l<b.l;
}
void modify(int x,int y){
	for (;x>0;x-=x&-x) E1[x]+=y;
}
long long query(int x){
	long long ans=0;
	for (;x<=n;x+=x&-x) ans+=E1[x];
	return ans;
}
void solve(int l,int r){
	if (l==r) return ;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	int lft=l;
	int rit;
	int i;
	for (rit=mid+1;rit<=r;rit++){
		while ((lft<=mid)&&(b[lft].l<=b[rit].l)){
			modify(b[lft].r,b[lft].val);lft++;
		}
		ff[b[rit].id]+=query(max(b[rit].r,1));
	}
	for (i=l;i<=lft-1;i++) modify(b[i].r,-b[i].val);
	sort(b+l,b+r+1,cmp);
}
int main(){
	n=read();m=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) pre[i]=vpre[a[i]],vpre[a[i]]=i;
	for (i=1;i<=n;i++) vsuf[i]=n+1;
	for (i=n;i>=1;i--) suf[i]=vsuf[a[i]],vsuf[a[i]]=i;
	for (i=1;i<=n;i++) {
		tn++;
		b[tn].l=i;b[tn].r=pre[i];b[tn].id=tn;b[tn].val=i-pre[i];
	}
	for (i=1;i<=n;i++) col[a[i]].insert(i);
	for (now=1;now<=m;now++){
		opt=read();
		if (opt==1){
		   l=read();r=read();
		   if (a[l]==r) continue;
		   /*
		    suf[l]
		   l
		   r 
		   */
		   if (suf[l]!=n+1){
		   	  tn++;
		   	  b[tn].l=suf[l];b[tn].r=pre[l];b[tn].id=tn;
		   	  b[tn].val=(suf[l]-pre[l]);
		   	  tn++;
		   	  b[tn].l=suf[l];b[tn].r=l;b[tn].id=tn;
		   	  b[tn].val=-(suf[l]-l);
		   }
		   set<int>::iterator itr=col[r].lower_bound(l);vr=n+1;
		   if (itr!=col[r].end()) {
		   	    vr=*itr;
		   	    tn++;
		   	    b[tn].l=vr;b[tn].r=l;b[tn].id=tn;
		   	    b[tn].val=(vr-l);
		       tn++;
		       b[tn].l=vr;b[tn].r=pre[vr];b[tn].id=tn;
		       b[tn].val=-(vr-pre[vr]);
		   }
		   vl=0;
		   if (itr!=col[r].begin()){
		   	itr--;
		   	
		   	vl=*itr;
		   }
		   tn++;b[tn].l=l;b[tn].r=pre[l];b[tn].id=tn;b[tn].val=-(l-pre[l]);
		   tn++;b[tn].l=l;b[tn].r=vl;b[tn].id=tn;b[tn].val=(l-vl);
		   v1=pre[l];v2=suf[l];
		   	if (v2!=n+1) pre[v2]=v1;
		   	if (v1!=0) suf[v1]=v2;
		   
		   set<int>::iterator it=col[a[l]].lower_bound(l);col[a[l]].erase(it);
		   col[r].insert(l);
		   a[l]=r;
		   if (vl!=0) suf[vl]=l;
		   if (vr!=n+1) pre[vr]=l;
		   pre[l]=vl;suf[l]=vr;
		}
		else {
			tn++;
			l=read();r=read();
			b[tn].l=r;b[tn].r=l;b[tn].val=0;b[tn].id=tn;
			tq++;
			pp[tq]=tn;
		}
	}solve(1,tn);
	for (i=1;i<=tq;i++) printf("%lld\n",ff[pp[i]]);
	return 0;
}
/*
i<=r,pre[i]>=l,tag[i]<=id val=i-pre[i]
*/
/*

 
*/