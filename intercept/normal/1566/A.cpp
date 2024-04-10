#include<bits/stdc++.h>
using namespace std;
int n,s;
void work(){
	scanf("%d%d",&n,&s);
	int x=(n+2)/2;
	printf("%d\n",s/x);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}