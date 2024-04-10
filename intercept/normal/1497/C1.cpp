#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
int n,k;
void work(){
	scanf("%d%d",&n,&k);
	if(n&1)printf("%d %d %d\n",n/2,n/2,1);
	else{
		if((n/2)&1)printf("%d %d %d\n",n/2-1,n/2-1,2);
		else printf("%d %d %d\n",n/2,n/4,n/4);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5 7
0 1 2 2 2
*/