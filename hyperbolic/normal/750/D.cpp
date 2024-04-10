#include <stdio.h>
/*
1 2 3
8   4
7 6 5
*/
int direX[10]={-1,0,1,1,1,0,-1,-1};
int direY[10]={1,1,1,0,-1,-1,-1,0};
int x[50];
int check[310][310];
int check2[310][310][50][10],a;
void func(int coorX, int coorY, int s, int t)
{
	if(s>a) return;
	if(check2[coorX][coorY][s][t]) return;
	check2[coorX][coorY][s][t] = 1;
	for(int i=0;i<x[s];i++) check[coorX+direX[t]*i][coorY+direY[t]*i] = 1;
	func(coorX+(x[s]-1)*direX[t]+direX[(t+7)%8],coorY+(x[s]-1)*direY[t]+direY[(t+7)%8],s+1,(t+7)%8);
	func(coorX+(x[s]-1)*direX[t]+direX[(t+1)%8],coorY+(x[s]-1)*direY[t]+direY[(t+1)%8],s+1,(t+1)%8);
}
int main()
{
	int s=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(151,151,1,1);
	for(int i=1;i<=305;i++) for(int j=1;j<=305;j++) s+=check[i][j];
	printf("%d",s);
}