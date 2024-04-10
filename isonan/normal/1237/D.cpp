#include <cstdio>
#include <algorithm>

int n,a[100001],b[100001],c[100010],stk[100010],top,loga[100001],st[100001][21];
bool vis[100001],add[100001];
int query(int l,int r){
	int k=loga[r-l+1];
	return std::max(st[l][k],st[r-(1<<k)+1][k]);
}
bool end(int l,int r){
	int tem;
	if(r<=n){
		if(n-l+1>=r)tem=query(l,l+r-1);
		else tem=std::max(query(l,n),query(1,r-(n-l+1)));
	}
	else tem=query(1,n);
	if(tem>(a[(l+r-1)%n+1]<<1))return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int span=1,mx=0;
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	for(int i=1;i<=n;i++)st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=std::max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	bool cando=0;
	for(int i=1;i<=n;i++)if((a[i]<<1)<query(1,n))cando=1;
	if(!cando){
		for(int i=1;i<=n;i++)printf("-1 ");
		return 0;
	}
	int length=1;
	for(int i=1;i<=n;i++){
		if(length>1)--length;
		while(!end(i,length))++length;
		printf("%d ",length);
	}
}