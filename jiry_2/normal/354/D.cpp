#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
	int x,y;
}x[110000];
int A[800],f[2][800],n,m;
int compare(atom k1,atom k2){
	return k1.y<k2.y;
}
int main(){
	scanf("%d%d",&n,&m); for (int i=1;i<=m;i++) scanf("%d%d",&x[i].x,&x[i].y);
	sort(x+1,x+m+1,compare); 
	memset(f,0x00,sizeof f); int now=0,lim=780;
	for (int i=1;i<=n;i++){
		memset(A,0x00,sizeof A);
		memset(f[now^1],0x3f,sizeof f[now^1]);
		while (m&&x[m].y==n-i+1){A[min(n-x[m].x+1,lim+1)]++; m--;}
		for (int j=lim;j;j--) A[j]+=A[j+1];
		for (int j=min(lim,i);j>=0;j--)
			f[now^1][j]=f[now][max(j-1,0)]+A[j+1]*3;
		for (int j=0;j<=min(i,lim);j++)
			f[now^1][0]=min(f[now^1][0],f[now][max(j-1,0)]+j*(j+1)/2+2+A[j+1]*3);
		for (int j=1;j<=min(i,lim);j++) f[now^1][j]=min(f[now^1][j],f[now^1][j-1]);
		now^=1;
	}
	cout<<f[now][0]<<endl; return 0;
}