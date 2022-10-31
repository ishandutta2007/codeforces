#include<bits/stdc++.h>
using namespace std;
 
int a,b,i,j,xx,yy,sum=0;
char sb[666][666];
 
int main(){
	scanf("%d%d\n",&a,&b);
	for(i=1;i<=a;i++){
		for(j=1;j<=b;j++){
			scanf("%c",&sb[i][j]);
		}getchar();
	}
	for(i=1;i<=a;i++){
		for(j=1;j<=b;j++){
			if(sb[i][j]=='*'&&sb[i-1][j]=='*'&&sb[i][j-1]=='*'&&sb[i+1][j]=='*'&&sb[i][j+1]=='*'&&xx+yy!=0){puts("nO");return 0;}
			if(sb[i][j]=='*'&&sb[i-1][j]=='*'&&sb[i][j-1]=='*'&&sb[i+1][j]=='*'&&sb[i][j+1]=='*'&&xx+yy==0){xx=i;yy=j;}
		}	
	}
	if(xx==0&&yy==0){puts("nO");return 0;}
	for(i=xx-1;i>=2;i--){if(sb[i][yy]=='.'&&sb[i-1][yy]=='*'){puts("nO");return 0;}}
	for(i=xx+1;i<=a-1;i++){if(sb[i][yy]=='.'&&sb[i+1][yy]=='*'){puts("nO");return 0;}}
	for(i=yy-1;i>=2;i--){if(sb[xx][i]=='.'&&sb[xx][i-1]=='*'){puts("nO");return 0;}}
	for(i=yy+1;i<=b-1;i++){if(sb[xx][i]=='.'&&sb[xx][i+1]=='*'){puts("nO");return 0;}}
	for(i=1;i<=a;i++){sb[i][yy]='.';}
	for(i=1;i<=b;i++){sb[xx][i]='.';}
	for(i=1;i<=a;i++){
		for(j=1;j<=b;j++){
			if(sb[i][j]=='*'){puts("nO");return 0;}
		}	
	}puts("yes");
}