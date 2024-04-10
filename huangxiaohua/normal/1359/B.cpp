#include<bits/stdc++.h>
using namespace std;
char s[1055];
int i,j,k,x,y,m,n,b,w,tt,sb[155][1055],sum;

int main(){
	scanf("%d",&tt);
	for(i=1;i<=tt;i++){
		scanf("%d%d%d%d",&m,&n,&x,&y);
		b=w=sum=0;
		for(j=1;j<=m;j++){
			scanf("%s",&s);
			for(k=1;k<=n;k++){
				if(s[k-1]=='*'){sb[j][k]=1;w++;}
				else{sb[j][k]=0;b++;}
			}
			sb[j][n+1]=1;
		}
		if(y>=x*2){printf("%d\n",b*x);continue;
		}
		for(j=1;j<=m;j++){
			for(k=1;k<=n;k++){
				if(sb[j][k]==0&&sb[j][k+1]==0){sb[j][k]=sb[j][k+1]=1;sum+=y;}
				if(sb[j][k]==0&&sb[j][k+1]==1){sb[j][k]=1;sum+=x;}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}