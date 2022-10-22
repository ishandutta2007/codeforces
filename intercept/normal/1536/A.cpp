#include<bits/stdc++.h>
using namespace std;
const int M=109;
int n;
void work(){
	scanf("%d",&n);
	bool bol=0;
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		if(x<0)bol=1;
	}
	if(bol){
		printf("NO\n");
		return;
	}
	printf("yes\n");
	printf("%d\n",101);
	for(int i=0;i<=100;++i)printf("%d ",i);
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;	
}