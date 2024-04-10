#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,len,h;
int b[150005];
int a[150005];
struct node{
	int v,i,d;
}t[300005];int tot=0;
int cmp(const node&a,const node&b){
	if(a.v==b.v)return a.d>b.d;
	else return a.v<b.v;
}
int seg[1100000]={0},tag[1100000]={0};
int I,d;
void pd(int x){
	if(tag[x]){
		seg[x<<1]+=tag[x];
		tag[x<<1]+=tag[x];
		seg[x<<1|1]+=tag[x];
		tag[x<<1|1]+=tag[x];
		tag[x]=0;
	}
}
void upd(int x,int l,int r){
	if(I<=l){
		seg[x]+=d;tag[x]+=d;
	}else{
		pd(x);
		int mid=l+r>>1;
		if(I<=mid)upd(x<<1,l,mid);
		if(tot>mid)upd(x<<1|1,mid+1,r);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
void ad(int i,int dd){
	I=i,d=dd;
	upd(1,1,tot);
}
int main()
{
	scanf("%d%d%d",&n,&len,&h);
	for (int i=1;i<=len;i++)scanf("%d",&b[i]),t[++tot]=(node){b[i],i,-1};
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=h-a[i],t[++tot]=(node){a[i],i,1};
	sort(t+1,t+1+tot,cmp);
	for (int i=1;i<=tot;i++){
		if(t[i].d==-1)b[t[i].i]=i;
		else a[t[i].i]=i;
	}
	for (int i=1;i<=len;i++)ad(b[i],-1);
	for (int i=1;i<=len;i++)ad(a[i],1);
	int ans=0;
	ans+=seg[1]>=0;
	for (int i=len+1;i<=n;i++){
		ad(a[i-len],-1);
		ad(a[i],1);
		ans+=seg[1]>=0;
	}
	printf("%d\n",ans);
	return 0;
}