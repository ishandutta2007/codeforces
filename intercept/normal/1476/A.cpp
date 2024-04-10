#include<bits/stdc++.h>
using namespace std;
int n,k,m;
void work(){
	scanf("%d%d",&n,&k);
	m=(n-1)/k+1;
	m=m*k;
	printf("%d\n",(m-1)/n+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}