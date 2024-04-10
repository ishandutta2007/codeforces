#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,k,a[500500],sb[500500],b[500500],res,m;

int main(){
	scanf("%d%d",&n,&k);
	memset(sb,62,sizeof(sb));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=i;
	}
	b[k+1]=n+1;a[n+1]=1e9+1;a[0]=-1145141919;
	for(i=1;i<=k;i++){
		scanf("%d",&b[i]);
		if(i>1&&a[b[i]]<a[b[i-1]]){puts("-1");return 0;}
	}
	for(i=1;i<=k+1;i++){
		memset(sb,62,m*4+10);
		sb[1]=a[b[i-1]];
		for(j=b[i-1]+1;j<b[i];j++){
			if(a[j]<sb[1]){continue;}
			*upper_bound(sb+1,sb+n+3,a[j])=a[j];
		}
		res+=(b[i]-b[i-1]+1)-(upper_bound(sb+1,sb+n+3,a[j])-sb);
		for(j=1;j<=n;j++){
			if(sb[j]>1e9){m=j;break;}
		}
	}
	printf("%d",res);
}