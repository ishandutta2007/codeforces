#include<stdio.h>
int i,j,k,n,m,f[605][305][305],a[305][305],x1,y1,x2,y2,tmp,tmp2;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	f[n*2-1][n][n]=a[n][n];
	for(i=n*2-2;i>=1;i--){
		x1=max(1,i-n+1);
		y1=min(n,i);
		while(x1<=n&&y1>0){
			x2=max(1,i-n+1);
			y2=min(n,i);
			while(x2<=n&&y2>0){
				tmp2=-2e9;
				if(x2==x1){tmp=a[x1][y1];}
				else{tmp=a[x1][y1]+a[x2][y2];}
				if(x1<n&&x2<n){tmp2=max(tmp2,tmp+f[i+1][x1+1][x2+1]);}
				if(x1<n&&y2<n){tmp2=max(tmp2,tmp+f[i+1][x1+1][x2]);}
				if(y1<n&&x2<n){tmp2=max(tmp2,tmp+f[i+1][x1][x2+1]);}
				if(y1<n&&y2<n){tmp2=max(tmp2,tmp+f[i+1][x1][x2]);}
				f[i][x1][x2]=tmp2;
				x2++;y2--;
			}
			x1++;y1--;
		}
	}
	printf("%d",f[1][1][1]);
}