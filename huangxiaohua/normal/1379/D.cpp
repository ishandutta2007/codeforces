#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500];
int mn=1145141919,res,tmp,nmsl;
int main() {
	scanf("%d%*d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%*d%d",&a[i]);
		b[i]=a[i];
		if(b[i]>=m/2){b[i]-=m/2;}
		b[i+n]=b[i]+m/2;
	}
	sort(b+1,b+n*2+1);
	b[n*2+1]=0x7fffffff;
	for(i=1;i<=n*2;i++){
		if(b[i]>=m/2){break;}
		if(b[i+1]==b[i]){continue;}
		j=max(i-1,j);
		while(j<=2*n&&b[j+1]-b[i]<k){j++;}
		if(mn>j-i){res=b[i];mn=j-i;}
	}
	nmsl=res+k;
	if(nmsl>=m/2){nmsl-=m/2;}
	printf("%d %d\n",mn,nmsl);
	for(i=1;i<=n;i++){
		if(a[i]>res&&a[i]<res+k){printf("%d ",i);continue;}
		if(a[i]>res+m/2&&a[i]<res+k+m/2){printf("%d ",i);continue;}
		if(a[i]>res-m/2&&a[i]<res+k-m/2){printf("%d ",i);continue;}
	}
}