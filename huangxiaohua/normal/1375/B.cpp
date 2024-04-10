#include<bits/stdc++.h>
using namespace std;

int i,j,n,m,t,r,sb[500][500],no;

int main(){
	scanf("%d",&t);
	while(t--){
		no=0;
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&sb[i][j]);
				if(sb[i][j]>4){no=1;}
			}
		}
		if(sb[1][1]>2||sb[1][n]>2||sb[m][1]>2||sb[m][n]>2){no=1;}
		for(i=1;i<=m;i++){
			if(sb[i][1]>3||sb[i][n]>3){no=1;}
		}
		for(i=1;i<=n;i++){
			if(sb[1][i]>3||sb[m][i]>3){no=1;}
		}
		if(no==1){puts("NO");continue;}
		puts("YES");
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if((i==1&&j==1)||(i==1&&j==n)||(i==m&&j==1)||(i==m&&j==n)){printf("2 ");continue;}
				if(i==1||j==1||i==m||j==n){printf("3 ");continue;}
				printf("4 ");
			}
			puts("");
		}
	}
}