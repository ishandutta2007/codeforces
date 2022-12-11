#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int pd[600][600],n,K,sign,size[200000],num[130000],tot;
int A[600][600];
const int gox[4]={1,0,-1,0},goy[4]={0,1,0,-1};
char ch[510];
void dfs(int k1,int k2){
	pd[k1][k2]=sign; size[sign]++;
	for (int i=0;i<4;i++){
		int a=k1+gox[i],b=k2+goy[i];
		if (pd[a][b]==0) dfs(a,b);
	}
}
void del(int k){
	num[k]--; if (num[k]==0) tot-=size[k];
}
void insert(int k){
	num[k]++; if (num[k]==1) tot+=size[k];
}
int calc(int k1,int k2){
	return A[k1+K-1][k2+K-1]-A[k1-1][k2+K-1]-A[k1+K-1][k2-1]+A[k1-1][k2-1];
}
int main(){
	scanf("%d%d",&n,&K);
	memset(pd,0xff,sizeof pd);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=n;j++) if (ch[j]=='X') pd[i][j]=-1; else pd[i][j]=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (pd[i][j]==0){
				sign++; dfs(i,j);
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			A[i][j]=(pd[i][j]==-1)+A[i-1][j]+A[i][j-1]-A[i-1][j-1];
	int ans=0;
	for (int now=1;now<=n-K+1;now++){
		memset(num,0x00,sizeof num); tot=0;
		for (int i=now-1;i<=now+K;i++)
			for (int j=1;j<=K+1;j++)
				if (pd[i][j]!=-1){
					if (j==K+1&&(i==now-1||i==now+K)) continue;
					insert(pd[i][j]);
				}
		for (int i=1;i<=n-K+1;i++){
			ans=max(tot+calc(now,i),ans);
			for (int j=now-1;j<=now+K;j++){
				int fla=0; if (j==now-1||j==now+K) fla=1;
				if (pd[j][i-1+fla]!=-1) del(pd[j][i-1+fla]);
				if (pd[j][i+K+1-fla]!=-1) insert(pd[j][i+K+1-fla]);
			}
		}
	}
	printf("%d\n",ans);
}