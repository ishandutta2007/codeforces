#include<bits/stdc++.h>
using namespace std;
int n,k;
void work(){
	scanf("%d%d",&n,&k);
	printf("%d\n",n-k+k/2);
	for(int i=n;i>k;--i)printf("%d ",i);
	for(int i=k-1;i>=(k+1)/2;--i)printf("%d ",i);
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}