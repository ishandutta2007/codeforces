#include<bits/stdc++.h>
int a[4];
int main(){
	for(int i=1;i<=3;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+4);
	printf("%d\n",std::max(0,a[3]-a[2]-a[1]+1));
	return 0;
}