#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int b[1100][1100],d[1100],size[1100],pd[1100],sign;
int totsize,n,m,K,x[1100];
void dfs(int k1,int k2){
	pd[k1]=k2;
	for (int i=1;i<=n;i++)
		if (b[k1][i]&&pd[i]==0) dfs(i,k2);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=K;i++) scanf("%d",&x[i]);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); b[k1][k2]=b[k2][k1]=1;
		d[k1]++; d[k2]++;
	}
	int ans=0,ma=0;
	for (int i=1;i<=K;i++){
		sign++;
		dfs(x[i],sign); int num1=0,num2=0;
		for (int j=1;j<=n;j++)
			if (pd[j]==sign){
				num1++; num2+=d[j];
			}
		ans+=num1*(num1-1)/2-num2/2;
		ma=max(ma,num1);
	}
//	cout<<ans<<" "<<ma<<endl;
	int remsize=0;
	for (int i=1;i<=n;i++)
		if (pd[i]==0){
			sign++;
			dfs(i,sign); int num1=0,num2=0;
			for (int j=1;j<=n;j++)
				if (pd[j]==sign){
					num1++; num2+=d[j];
				}
			ans+=num1*(num1-1)/2-num2/2;
			ans+=ma*num1; ma+=num1;
		}
	cout<<ans<<endl;
}