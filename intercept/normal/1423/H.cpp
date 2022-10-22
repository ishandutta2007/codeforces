#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=5e5+9;
int n,q,k,m,day=0,top=0;
int dsu[M],sum[M],op[M],a[M],b[M],s[M],last[M];
int find(int x){return dsu[x]==x?x:find(dsu[x]);}
vector<int>t[M<<2];
void update(int num,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){t[num].eb(v);return;}
	int mid=(l+r)>>1;
	if(x<=mid)update(num<<1,l,mid,x,y,v);
	if(y>mid)update(num<<1|1,mid+1,r,x,y,v);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(sum[x]>sum[y])swap(x,y);
	dsu[x]=y;sum[y]+=sum[x];
	s[++top]=x;
}
void delet(int now){
	while(top>now){
		int x=s[top--];
		sum[dsu[x]]-=sum[x];
		dsu[x]=x;
	}
}
void solve(int num,int l,int r){
	int now=top;
	for(auto o:t[num])merge(a[o],b[o]);
	if(l==r){
		if(op[l]==2)printf("%d\n",sum[find(a[l])]);	
		delet(now);
		return;
	}
	int mid=(l+r)>>1;
	solve(num<<1,l,mid);
	solve(num<<1|1,mid+1,r);
	delet(now);
}
int main(){
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i)dsu[i]=i,sum[i]=1;
	for(int i=1;i<=q;++i){
		scanf("%d",&op[i]);
		if(op[i]==1)scanf("%d%d",&a[i],&b[i]);
		if(op[i]==2)scanf("%d",&a[i]);
		if(op[i]==3)last[++day]=i-1;
	}
	last[m=++day]=q;day=1;
	for(int i=1;i<=q;++i){
		if(op[i]==1)update(1,1,q,i,last[min(day+k-1,m)],i);
		if(op[i]==3)day++;
	}
	solve(1,1,q);
	return 0;
}