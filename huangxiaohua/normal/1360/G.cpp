#include<bits/stdc++.h>
using namespace std;
 
int i,j,k,t,n,m,a,b,sb[55][55];
int main(){
    scanf("%d",&t);
    for(k=1;k<=t;k++){
		scanf("%d%d%d%d",&m,&n,&a,&b);
		if(m*a!=n*b){puts("NO");continue;}
		puts("YES");
		
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				sb[i][j]=0;
			}
		}
		for(i=1;i<=a;i++){
			sb[1][i]=1;
		}
		for(i=1;i<=m-1;i++){
			for(j=1;j<=n;j++){
				if(sb[i][j]==1){
					if((j+a)%n==0){sb[i+1][n]=1;continue;}
					sb[i+1][(j+a)%n]=1;
				}
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				printf("%d",sb[i][j]);
			}
			printf("\n");
		}
    }
    return 0;
}