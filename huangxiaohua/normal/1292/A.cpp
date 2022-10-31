#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,x,y,t,sb,a[20][100500];

int main(){
	scanf("%d%d",&n,&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(a[x][y]){
			sb-=a[3-x][y-1];
			sb-=a[3-x][y];
			sb-=a[3-x][y+1];
		}
		else{
			sb+=a[3-x][y-1];
			sb+=a[3-x][y];
			sb+=a[3-x][y+1];
		}
		a[x][y]^=1;
		if(sb||a[1][1]||a[2][n]){puts("NO");}
		else{puts("YES");}
	}
}