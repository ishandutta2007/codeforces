#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n;
int a[maxn][maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	n=read();
	if(n&1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[i][j]=1;a[j][i]=0;
				if(i+j==n+1)a[i][j]=0,a[j][i]=1;
			}
		}
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
				printf("%d ",a[i][j]);
	}
	else{
		if(n==4){puts("-1");return 0;}
		a[1][2]=a[1][3]=a[1][4]=a[2][3]=a[2][4]=a[2][5]=a[3][4]=a[3][6]=a[4][5]=a[4][6]=a[5][1]=a[5][3]=a[5][6]=a[6][1]=a[6][2]=1;
		for(int i=6;i<=n;i+=2){
			int u=i+1,v=i+2;
			for(int j=1;j<=i;j++)a[j][u]=1,a[v][j]=1;
			a[u][v]=1;
		}
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
				printf("%d ",a[i][j]);
	}
	return 0;
}