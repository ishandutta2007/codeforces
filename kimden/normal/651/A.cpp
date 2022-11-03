#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int mod3(int a){
	int b=a;
	while(b<0) b+=3;
	return b%3;
}

int f(int x,int y){
	int z=0;
	if(x==1 && y==1){
		return 0;
	}
	switch(mod3(x-y)){
	case 0:
		z = x+y-3;
		break;
	case 1:
	case 2:
		z=x+y-2;
		break;
	}
	return z;
}

int main()
{
	int a1,a2,ans;
	scanf("%d%d",&a1,&a2);
	ans = f(a1,a2);
	printf("%d",ans);
	return 0;
}