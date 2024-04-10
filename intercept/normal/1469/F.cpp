#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+9;
int n,k,m=1e6,ans=m+1;
int a[M];
ll sum[M<<2],lag[M<<2],s=1;
void pushup(int num){sum[num]=sum[num<<1]+sum[num<<1|1];}
void pushdown(int num,int l,int r){
	int v=lag[num],mid=l+r>>1;lag[num]=0;
	sum[num<<1]+=(mid-l+1)*v;
	lag[num<<1]+=v;
	sum[num<<1|1]+=(r-mid)*v;
	lag[num<<1|1]+=v;
}
void update(int num,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){sum[num]+=v*(r-l+1);lag[num]+=v;return;}
	pushdown(num,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)update(num<<1,l,mid,x,y,v);
	if(y>mid)update(num<<1|1,mid+1,r,x,y,v);
	pushup(num);
}
int find(int num,int l,int r,ll v){
	if(l==r)return l;
	pushdown(num,l,r);
	int mid=(l+r)>>1;
	if(sum[num<<1]>=v)return find(num<<1,l,mid,v);
	else return find(num<<1|1,mid+1,r,v-sum[num<<1]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	update(1,1,m,1,1,1);
	for(int i=n;i>=1;--i){
		int u=find(1,1,m,1);
		update(1,1,m,u,u,-1);
		update(1,1,m,u+2,u+1+a[i]/2,1);
		update(1,1,m,u+2,u+1+(a[i]-1)/2,1);
		s+=a[i]-2;
		if(s>=k)ans=min(ans,find(1,1,m,k)-1);
	}
	if(s>=k)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
/*
3 5
4 3 4
*/