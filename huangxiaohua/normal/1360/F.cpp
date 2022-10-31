#include<bits/stdc++.h>
using namespace std;
char sb[15][15],ans[15];
int i,j,k,l,l1,t,n,m,no,yes;
int main(){
    scanf("%d",&t);
    for(k=1;k<=t;k++){
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++){
			scanf("%s",&sb[i]);
		}
		if(n==1){puts("x");continue;}
		if(m==1){printf("%s\n",sb[1]);continue;}
		for(i=0;i<=n-1;i++){
			ans[i]=sb[1][i];
		}
		for(i=0;i<=n-1;i++){
			for(j='a';j<='z';j++){
				ans[i]=j;yes=1;
				for(l=1;l<=m;l++){
					no=0;
					for(l1=0;l1<=n-1;l1++){
						if(ans[l1]!=sb[l][l1]){no++;}
					}
					if(no>1){yes=0;break;}
				}
				if(yes==1){goto aaa;}
				ans[i]=sb[1][i];
			}
		}
		
		aaa:if(yes==0){
			puts("-1");
		}
		else{
			for(i=0;i<=n-1;i++){
				printf("%c",ans[i]);
			}printf("\n");
		}
    }
    return 0;
}