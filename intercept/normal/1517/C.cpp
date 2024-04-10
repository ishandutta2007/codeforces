#include<bits/stdc++.h>
using namespace std;
int n; 
int b[509][509],p[509];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]);
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j)b[i][j]=0;
	}
	for(int i=1;i<=n;++i){
		int v=p[i],s=v,x=i,y=i;
		while(s){
			b[x][y]=v;
			s--;
			if(!s)break;
			if(!b[x][y-1]&&y>1)y--;
			else if(!b[x+1][y]&&x+1<=n)x++;
			else y++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}