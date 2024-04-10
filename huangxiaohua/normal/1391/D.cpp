#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
int m,n,i,j,sb[4][500500];
int dp2[500500][2];
int dp3[400500][2][2];
bool tmp2[500500],tmp3[400500][2];
int main(){
	scanf("%d%d\n",&m,&n);
	if(m>=4){puts("-1");return 0;}
	if(m==1){puts("0");return 0;}
	if(m==2){
		for(i=1;i<=n;i++){sb[1][i]=getchar();}getchar();
		for(i=1;i<=n;i++){sb[2][i]=getchar();}getchar();
		for(i=1;i<=n;i++){tmp2[i]=sb[1][i]^sb[2][i];}
		for(i=1;i<=n;i++){
			dp2[i][1]=dp2[i-1][0]+1;dp2[i][0]=dp2[i-1][1]+1;
			if(tmp2[i]==0){dp2[i][0]--;}
			else{dp2[i][1]--;}
		}
		printf("%d",min(dp2[n][0],dp2[n][1]));return 0;
	}
	if(m==3){
		for(i=1;i<=n;i++){sb[1][i]=getchar();}getchar();
		for(i=1;i<=n;i++){sb[2][i]=getchar();}getchar();
		for(i=1;i<=n;i++){sb[3][i]=getchar();}getchar();
		for(i=1;i<=n;i++){tmp3[i][0]=sb[1][i]^sb[2][i];tmp3[i][1]=sb[2][i]^sb[3][i];}
		for(i=1;i<=n;i++){
			dp3[i][1][1]=dp3[i-1][0][0]+1;dp3[i][0][1]=dp3[i-1][1][0]+1;dp3[i][1][0]=dp3[i-1][0][1]+1;dp3[i][0][0]=dp3[i-1][1][1]+1;
			if(tmp3[i][0]==0&&tmp3[i][1]==0){dp3[i][0][0]--;}
			if(tmp3[i][0]==1&&tmp3[i][1]==0){dp3[i][1][0]--;}
			if(tmp3[i][0]==0&&tmp3[i][1]==1){dp3[i][0][1]--;}
			if(tmp3[i][0]==1&&tmp3[i][1]==1){dp3[i][1][1]--;}
 
		}
		printf("%d",min(min(dp3[n][0][0],dp3[n][1][0]),min(dp3[n][0][1],dp3[n][1][1])));return 0;
	}
}