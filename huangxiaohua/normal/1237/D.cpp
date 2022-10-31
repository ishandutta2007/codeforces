#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],mn,mx,st[300500][21],st2[300500][21],l2[300500],res[300500],l,r;

int chk(int l,int r){int k=l2[r-l+1];return max(st[l][k],st[r-(1<<k)+1][k]);}
int chk2(int l,int r){int k=l2[r-l+1];return min(st2[l][k],st2[r-(1<<k)+1][k]);}
bool get(int l,int r){
	int x=chk(l,r),y=chk2(l,r);
	return ((y+y)<x);
}
int main(){
	scanf("%d",&n);l2[0]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[n+i]=a[n+n+i]=a[i];
	}
	for(i=1;i<=3*n;i++){
		st[i][0]=a[i];
		st2[i][0]=a[i];
		l2[i]=l2[i>>1]+1;
	}
	for(j=1;j<=20;j++){
		for(i=1;i+(1<<j)-1<=n*3;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	if(!get(1,n)){
		for(i=1;i<=n;i++){
			printf("-1 ");
		}return 0;
	}
	l=1;r=2;
	for(;l<=n;r++){
		while(l<r&&chk(l,r-1)>(a[r]+a[r])){
			if(l>n){break;}
			res[l]=r-l;l++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}