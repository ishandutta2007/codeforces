#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[410][410],sign,n,bo[410][410][8],ne[410][410][8];
const int gox[8]={0,1,1,1,0,-1,-1,-1},goy[8]={1,1,0,-1,-1,-1,0,1};
const int N=200,M=400;
int main(){
	scanf("%d",&n);
	memset(pd,0x00,sizeof pd);
	pd[N][N]=1; bo[N][N][0]=1; sign=0;
	int flag=0;
	for (;n;n--){
		int t; scanf("%d",&t); sign++;
		if (flag==0) t--; flag=1;
		for (int i=0;i<=M;i++)
			for (int j=0;j<=M;j++)
				for (int k=0;k<8;k++)
					if (bo[i][j][k]==sign){
						int x=i,y=j,way1=(k+1)%8,way2=(k+7)%8;
						for (int i=1;i<=t;i++){
							x+=gox[k]; y+=goy[k];
							pd[x][y]=1;
						}
						ne[x][y][way1]=sign+1;
						ne[x][y][way2]=sign+1;
					}
		memcpy(bo,ne,sizeof ne);
	}
	int ans=0;
	for (int i=0;i<=M;i++)
		for (int j=0;j<=M;j++) ans+=pd[i][j];
	printf("%d\n",ans);
	return 0;
}