#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,a,b,x,y;
	scanf("%d%d%d",&n,&a,&b);
	if((((int)(a*b+1))/2<((int)(n+1))/2)||(((int)(a*b))/2<((int)(n))/2)){
		printf("-1");
		return 0;
	}
	int **arr;
	arr = new int*[a];
	for(int i=0;i<a;i++){
		arr[i] = new int[b];
	}
	x=0;
	y=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			arr[i][j]=0;
		}
	}
	for(int i=1;i<=n;i+=2){
		arr[x][y]=i;
		y+=2;
		while(y>=b){
			x++;
			y=x%2;
		}
	}
	x=0;
	y=1;
	while(y>=b){
	    x++;
	    y=(x+1)%2;
	}
	for(int i=2;i<=n;i+=2){
		arr[x][y]=i;
		y+=2;
		while(y>=b){
			x++;
			y=(x+1)%2;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(j!=0){
				printf(" ");
			}
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}