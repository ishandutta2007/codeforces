#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double sb[1005][1005],sb2[1005][5];
int i,j,n,m,a,b;
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=n-1;i>=1;i--){
		for(j=m;j>=1;j--){
			sb2[j][1]=-1;
			sb2[j][2]=3;
			sb2[j][3]=-1;
			sb2[j][4]=4+sb[i+1][j];
		}
		sb[1][1]=0;
		sb2[1][2]=sb2[m][2]=2;
		sb2[1][4]--;
		sb2[m][4]--;
		for(j=m-1;j>=1;j--){
			sb2[j][2]-=sb2[j][3]/sb2[j+1][2]*sb2[j+1][1];
			sb2[j][4]-=sb2[j][3]/sb2[j+1][2]*sb2[j+1][4];
			sb2[j][3]=0;
		}
		for(j=1;j<=m;j++){
			sb[i][j]=(sb2[j][4]+sb[i][j-1])/sb2[j][2];
		}
	}
	if(m==1){printf("%d\n",n*2-a*2);return 0;}
	printf("%.20lf",sb[a][b]);
}