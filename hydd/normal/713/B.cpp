#include<bits/stdc++.h>
using namespace std;
int n,ans,Ans[11];
int query(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout); int x; scanf("%d",&x);
	return x;
}
void getrec(int x1,int y1,int x2,int y2){
	int l,r,mid;
	//r1
	l=x1; r=x2;
	while (l<r){
		mid=(l+r+1)>>1;
		if (query(mid,y1,x2,y2)>=1) l=mid;
		else r=mid-1;
	}
	Ans[++ans]=l;
	//c1
	l=y1; r=y2;
	while (l<r){
		mid=(l+r+1)>>1;
		if (query(x1,mid,x2,y2)>=1) l=mid;
		else r=mid-1;
	}
	Ans[++ans]=l;
	//r2
	l=x1; r=x2;
	while (l<r){
		mid=(l+r)>>1;
		if (query(x1,y1,mid,y2)>=1) r=mid;
		else l=mid+1;
	}
	Ans[++ans]=r;
	//c2
	l=y1; r=y2;
	while (l<r){
		mid=(l+r)>>1;
		if (query(x1,y1,x2,mid)>=1) r=mid;
		else l=mid+1;
	}
	Ans[++ans]=r;
}
void solve(int n){
	int l,r,mid;
	//solve by row
	l=1; r=n;
	while (l<r){
		mid=(l+r)>>1;
		if (query(1,1,mid,n)>=1) r=mid;
		else l=mid+1;
	}
	if (query(1,1,l,n)==1&&query(l+1,1,n,n)==1){
		getrec(1,1,l,n);
		getrec(l+1,1,n,n);
		return;
	}

	//solve by column
	l=1; r=n;
	while (l<r){
		mid=(l+r)>>1;
		if (query(1,1,n,mid)>=1) r=mid;
		else l=mid+1;
	}
	if (query(1,1,n,l)==1&&query(1,l+1,n,n)==1){
		getrec(1,1,n,l);
		getrec(1,l+1,n,n);
		return;
	}
}
int main(){
	scanf("%d",&n);
	solve(n);
	putchar('!'); for (int i=1;i<=ans;i++) printf(" %d",Ans[i]);
	return 0;
}