#include <bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn][maxn];
int f[2*maxn][maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int get(int x1,int y1,int x2,int y2){
	if(x1==x2&&y1==y2)return a[x1][y1];
	return a[x1][y1]+a[x2][y2];
}
int main(){
//    freopen("CF213C.in","r",stdin);
//    freopen("CF213C.out","w",stdout);
    int n;
	n=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
	memset(f,0xcf,sizeof(f));
	f[0][1][1]=a[1][1];
    for(int i=0;i<2*n-2;i++){
		for(int x1=1;x1<=min(i+1,n);x1++){
			for(int x2=1;x2<=min(i+1,n);x2++){
				if(i+2-x1<n&&i+2-x2<n)f[i+1][x1][x2]=max(f[i+1][x1][x2],f[i][x1][x2]+get(x1,i+3-x1,x2,i+3-x2));
				if(x1<n&&i+2-x2<n)f[i+1][x1+1][x2]=max(f[i+1][x1+1][x2],f[i][x1][x2]+get(x1+1,i+2-x1,x2,i+3-x2));
				if(i+2-x1<n&&x2<n)f[i+1][x1][x2+1]=max(f[i+1][x1][x2+1],f[i][x1][x2]+get(x1,i+3-x1,x2+1,i+2-x2));
				if(x1<n&&x2<n)f[i+1][x1+1][x2+1]=max(f[i+1][x1+1][x2+1],f[i][x1][x2]+get(x1+1,i+2-x1,x2+1,i+2-x2));
			}
		}
	}
	printf("%d\n",f[2*n-2][n][n]);
	return 0;
}