#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[5050],b[5050],pre[5050],res,l,r,tmp;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(j=1;j<=n;j++){
		scanf("%lld",&b[j]);
		pre[j]=pre[j-1]+a[j]*b[j];
	}
	for(i=1;i<=n;i++){
		tmp=0;
		l=i-1,r=i+1;
		while(l>=1&&r<=n){
			//printf("%d %d\n",l,r);
			
			tmp+=a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r];
			if(res<tmp){res=tmp;}
			l--;r++;
		}
	}
	for(i=1;i<=n;i++){
		tmp=0;
		l=i,r=i+1;
		while(l>=1&&r<=n){
			//printf("%d %d\n",l,r);
			
			tmp+=a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r];
			if(res<tmp){res=tmp;}
			l--;r++;
		}
	}
	printf("%lld",pre[n]+res);
}