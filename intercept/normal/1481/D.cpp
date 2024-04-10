#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m;
char c[1009][1009];
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",c[i]+1);
	if(n==2&&m%2==0&&c[1][2]!=c[2][1]){
		printf("NO\n");
		return;
	} 
	printf("YES\n");
	if(m%2==1){
		for(int i=1;i<=m+1;++i){
			if(i&1)printf("1 ");
			else printf("2 ");
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(c[i][j]==c[j][i]){
				for(int k=1;k<=m+1;++k){
					if(k&1)printf("%d ",i);
					else printf("%d ",j);
				}
				printf("\n");
				return;
			}
		}
	}
	int po1,po2,po3;
	for(int i=1;i<=n;++i){
		for(int j=2;j<=n;++j){
			if(i==j)continue;
			int k=j-1;
			if(c[i][k]=='*')k--;
			if(c[i][j]!=c[i][k])po1=i,po2=j,po3=k;
		}
	}
	if(m/2%2==1){
		for(int i=1;i<=m/2;++i){
			if(i&1)printf("%d ",po2);
			else printf("%d ",po1);
		}
		
		for(int i=1;i<=m/2;++i){
			if(i&1)printf("%d ",po1);
			else printf("%d ",po3);
		}
		printf("%d ",po3);
		printf("\n");
		return;
	}
	for(int i=1;i<=m/2;++i){
		if(i&1)printf("%d ",po1);
		else printf("%d ",po2);
	}
	for(int i=1;i<=m/2;++i){
		if(i&1)printf("%d ",po1);
		else printf("%d ",po3);
	}
	printf("%d ",po1);
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
3 2
*ab
b*b
aa*

*/