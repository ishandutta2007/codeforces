#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n,x,y;
	int i;
	int *a;
	int *b;
	scanf("%d",&n);
	a=new int[n-1];
	b=new int[n-1];
	y=0;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x!=0){
			a[y++]=x;
		}
	}
	y=0;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x!=0){
			b[y++]=x;
		}
	}
	y=0;
	while(b[y]!=a[0]){
		y++;
	}
	for(i=0;i<n-1;i++){
		if(a[i]!=b[y]){
			break;
		}
		y++;
		if(y==n-1)
			y=0;
	}
	if(i==n-1){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}