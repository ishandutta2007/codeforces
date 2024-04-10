#include<bits/stdc++.h>
using namespace std;
const int M=309*309;
int n,m;
int a[M],id[M],b[309][309],d[M],d1[M];
void add(int *c,int i){
	for(;i<=m;i+=i&-i)c[i]++;
}
int sum(int *c,int i,int rex=0){
	for(;i;i-=i&-i)rex+=c[i];
	return rex;
}
bool cmp(int l,int r){
	int lx=(l-1)/m+1,ly=(l-1)%m+1;
	int rx=(r-1)/m+1,ry=(r-1)%m+1;
	if(d[l]!=d[r])return d[l]<d[r];
	if(lx!=rx)return lx<rx;
	return l>r;
}
bool cmp1(int l,int r){
	if(a[l]!=a[r])return a[l]<a[r];
	return l<r;
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)b[i][j]=0;
	}
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
		d[i]=a[i];
		id[i]=d1[i]=i;
	}
	sort(d+1,d+n*m+1);
	sort(id+1,id+n*m+1,cmp);
	sort(d1+1,d1+n*m+1,cmp1);
	for(int i=1;i<=n*m;++i){
		a[d1[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n*m;++i){
		int x=(id[a[i]]-1)/m+1,y=(id[a[i]]-1)%m+1;
		ans+=sum(b[x],y);
		add(b[x],y);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
} 
/*
1
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3
*/