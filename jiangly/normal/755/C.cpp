#include<bits/stdc++.h>
typedef unsigned uint;
const uint MAXN=10000;
bool vis[MAXN+5];
uint N,Ans;
int main(){
	scanf("%d",&N);
	for(uint i=1;i<=N;++i){
		int a;
		scanf("%d",&a);
		if(a==i)
			Ans+=2;
		else if(!vis[a]){
			++Ans;
			vis[a]=1;
		}
	}
	printf("%u\n",Ans/2);
	return 0;
}