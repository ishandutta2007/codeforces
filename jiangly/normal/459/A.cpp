#include<bits/stdc++.h>
using namespace std;
int x[2],y[2];
int main(){
	scanf("%d%d%d%d",x,y,x+1,y+1);
	if(x[0]==x[1]){
		printf("%d %d %d %d",x[0]+y[0]-y[1],y[0],x[0]+y[0]-y[1],y[1]);
	}else if(y[0]==y[1]){
		printf("%d %d %d %d",x[0],y[0]+x[0]-x[1],x[1],y[0]+x[0]-x[1]);
	}else if(abs(x[0]-x[1])==abs(y[0]-y[1])){
		printf("%d %d %d %d",x[0],y[1],x[1],y[0]);
	}else{
		printf("-1");
	}
	return 0;
}