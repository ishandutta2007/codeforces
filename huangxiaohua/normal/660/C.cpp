#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],b[300500],it=1,l,r,res,md,y;

int main() {
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]+b[i-1];
	}
	l=0;r=n;
	while(l<=r){
		md=(l+r)/2;y=0;
		for(i=1;i+md-1<=n;i++){
			if((b[i+md-1]-b[i-1]+m)>=md){y=1;break;}
		}
		if(y){
			res=max(res,md);l=md+1;
		}
		else r=md-1;
	}
	printf("%d\n",res);
	for(i=1;i+res-1<=n;i++){
		if((b[i+res-1]-b[i-1]+m)>=res){
			for(j=i;j<i+res;j++){a[j]=1;}
			break;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}