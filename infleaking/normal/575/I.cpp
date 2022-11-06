#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=3e5+10;
int ty[M],px[M],py[M],len[M];
int tr[N][N*2],lim,n,q;
int low(int x){return (x&(-x));}
void add(int x,int y,int v){
	for (int i=x;i<=n;i+=low(i))
		for (int j=y;j<=2*n;j+=low(j))
			tr[i][j]+=v;
}
int query(int x,int y){
	int ans=0;
	for (int i=x;i;i-=low(i))
		for (int j=y;j;j-=low(j))
			ans+=tr[i][j];
	return ans;
}
void A(int l1,int r1,int l2,int r2,int v){
	r1++,r2++;
	add(l1,l2,v);
	add(l1,r2,-v);
	add(r1,l2,-v);
	add(r1,r2,v);
}
int ans[M];
int main(){
	cin>>n>>q;
	for (int i=1;i<=q;i++){
		scanf("%d",&ty[i]);
		if (ty[i]==2){
			ty[i]=5;
			scanf("%d%d",&px[i],&py[i]);
		}
		else scanf("%d%d%d%d",&ty[i],&px[i],&py[i],&len[i]);
	}
	// x,x+y
	for (int i=1;i<=q;i++){
		int x=px[i],y=py[i],l=len[i];
		if (ty[i]==5)ans[i]+=query(x,x+y);
		if (ty[i]==1)A(1,x-1,x+y,x+y+l,-1),A(1,n,x+y,x+y+l,1);
		if (ty[i]==4)A(x+1,n,x+y-l,x+y,-1),A(1,n,x+y-l,x+y,1);
	}
	memset(tr,0,sizeof tr);
	// x,x-y
	for (int i=1;i<=q;i++){
		int x=px[i],y=py[i],l=len[i];
		if (ty[i]==5)ans[i]+=query(x,x-y+n);
		if (ty[i]==2)A(1,x-1,x-y+n,x-y+n+l,-1),A(1,n,x-y+n,x-y+n+l,1);
		if (ty[i]==3)A(x+1,n,x-y+n-l,x-y+n,-1),A(1,n,x-y+n-l,x-y+n,1);
	}
	// y,x+y
	memset(tr,0,sizeof tr);
	for (int i=1;i<=q;i++){
		int x=px[i],y=py[i],l=len[i];
		if (ty[i]==5)ans[i]+=query(y,x+y);
		if (ty[i]==1)A(1,y-1,x+y,x+y+l,-1);
		if (ty[i]==4)A(y+1,n,x+y-l,x+y,-1);
	}
	memset(tr,0,sizeof tr);
	// y,x-y
	for (int i=1;i<=q;i++){
		int x=px[i],y=py[i],l=len[i];
		if (ty[i]==5)ans[i]+=query(y,x-y+n);
		if (ty[i]==2)A(y+1,n,x-y+n,x-y+n+l,-1);
		if (ty[i]==3)A(1,y-1,x-y+n-l,x-y+n,-1);
	}
	for (int i=1;i<=q;i++)
		if (ty[i]==5)printf("%d\n",ans[i]);
}