#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
	int a,b,c;
	bool bo=false;
	scanf("%d%d%d",&a,&b,&c);
	while(c>=0){
		if(c%a==0){
			bo = true;
			break;
		}
		c-=b;
	}
	if(bo){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}