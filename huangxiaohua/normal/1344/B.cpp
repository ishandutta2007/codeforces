#include<stdio.h>
int map[1005][1005],i,j,n,m,x[1005],y[1005],blk=0,l,r,res=0;
int fkshit(int i,int j){
	map[i][j]=0;
	if(map[i-1][j]==1){fkshit(i-1,j);}
	if(map[i+1][j]==1){fkshit(i+1,j);}
	if(map[i][j-1]==1){fkshit(i,j-1);}
	if(map[i][j+1]==1){fkshit(i,j+1);}
	
}
char sb[1005];
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
    scanf("%s",&sb);
		for(j=1;j<=n;j++){
			if(sb[j-1]=='#'){map[i][j]=1;x[i]=1;y[j]=1;blk=1;}
			else{map[i][j]=0;}
		}
	}
	if(blk==0){printf("0");return 0;}
for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i]!=1&y[j]!=1){x[i]=2;y[j]=2;}
		}
	}
	for(i=1;i<=m;i++){
		if(x[i]==0){printf("-1");return 0;}
	}
	for(i=1;i<=n;i++){
		if(y[i]==0){printf("-1");return 0;}
	}
	for(i=1;i<=m;i++){
		l=0;
		for(j=1;j<=n-1;j++){
			if(map[i][j]==1&map[i][j+1]==0){l=1;}
			if(map[i][j+1]==1&map[i][j]==0&l==1){printf("-1");return 0;}
		}
	}
	for(j=1;j<=n;j++){
		l=0;
		for(i=1;i<=m-1;i++){
			if(map[i][j]==1&map[i+1][j]==0){l=1;}
			if(map[i+1][j]==1&map[i][j]==0&l==1){printf("-1");return 0;}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(map[i][j]==1){res++;fkshit(i,j);}
		}
	}
	printf("%d",res);
}