#include <stdio.h>
#include <algorithm>
#include <time.h>

int x[30];
int main()
{
	int a;
	int cl = clock();
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
	while((float)(clock()-cl)/CLOCKS_PER_SEC<=1.5);
	return 0;
}