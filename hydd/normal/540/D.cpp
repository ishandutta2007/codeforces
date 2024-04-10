#include<cstdio>
using namespace std;
typedef long double ldb;
int R,S,P,inv[310];
ldb dp[110][110][110][3];
int main(){
	scanf("%d%d%d",&R,&S,&P);
	ldb x,y;
	for (int r=0;r<=R;r++)
		for (int s=0;s<=S;s++)
			for (int p=0;p<=P;p++){
				if (!r&&!s&&!p) continue;
				if (!s&&!p){ dp[r][s][p][0]=1; continue;}
				if (!r&&!p){ dp[r][s][p][1]=1; continue;}
				if (!r&&!s){ dp[r][s][p][2]=1; continue;}
				for (int k=0;k<=2;k++){
					y=1.0*r*s+1.0*r*p+1.0*s*p+
					  0.5*r*(r-1)+0.5*s*(s-1)+0.5*p*(p-1); y=1/y;
					if (r&&s){
						x=1.0*r*s;
						dp[r][s][p][k]+=x*y*dp[r][s-1][p][k];
					}
					if (r&&p){
						x=1.0*r*p;
						dp[r][s][p][k]+=x*y*dp[r-1][s][p][k];
					}
					if (s&&p){
						x=1.0*s*p;
						dp[r][s][p][k]+=x*y*dp[r][s][p-1][k];
					}
					ldb tmp=0;
					if (r>=2){
						x=0.5*r*(r-1);
						tmp+=x*y;
					}
					if (s>=2){
						x=0.5*s*(s-1);
						tmp+=x*y;
					}
					if (p>=2){
						x=0.5*p*(p-1);
						tmp+=x*y;
					}
					dp[r][s][p][k]/=(1-tmp);
				}
			}
	printf("%.12lf %.12lf %.12lf\n",(double)dp[R][S][P][0],(double)dp[R][S][P][1],(double)dp[R][S][P][2]);
	return 0;
}