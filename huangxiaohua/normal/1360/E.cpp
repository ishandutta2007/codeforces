#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int i,j,k,t,n,sb[105][105][2],yes;
int main(){
    scanf("%d",&t);
    for(i=1;i<=t;i++){
		scanf("%d",&n);yes=1;
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				scanf("%1d",&sb[j][k][0]);
				sb[j][k][1]=0;
				if(sb[j][k][0]==1&&(j==n||k==n)){sb[j][k][1]=1;}
			}
		}
		for(j=1;j<=n;j++){
			for(k=n-1;k>=1;k--){
				if(sb[j][k][0]==1&&sb[j][k+1][1]==1){sb[j][k][1]=1;}
			}
		}
		for(k=1;k<=n;k++){
			for(j=n-1;j>=1;j--){
				if(sb[j][k][0]==1&&sb[j+1][k][1]==1){sb[j][k][1]=1;}
			}
		}
		for(j=1;j<=n;j++){
			for(k=n-1;k>=1;k--){
				if(sb[j][k][0]==1&&sb[j][k+1][1]==1){sb[j][k][1]=1;}
			}
		}
		for(k=1;k<=n;k++){
			for(j=n-1;j>=1;j--){
				if(sb[j][k][0]==1&&sb[j+1][k][1]==1){sb[j][k][1]=1;}
			}
		}
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(sb[j][k][0]==1&&sb[j][k][1]==0){yes=0;break;}
			}
		}
		(yes==1)?puts("YES"):puts("NO");
    }
    return 0;
}