#include<bits/stdc++.h>
using namespace std;
 
int t,n,k,i,j,sb[305][305],tmp=0;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(sb,0,sizeof(sb));
		if(k%n==0){puts("0");}
		else{puts("2");}
		i=j=1;tmp=0;
		while(k--){
			sb[i][j]=1;
			i++;j++;tmp++;
			if(tmp%n==0){j++;}
			if(i==n+1){i=1;}
			if(i==n+2){i=2;}
			if(j==n+1){j=1;}
			if(j==n+2){j=2;}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d",sb[i][j]);
			}puts("");
		}
	}
}