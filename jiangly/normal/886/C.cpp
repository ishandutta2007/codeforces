#include<bits/stdc++.h>
typedef unsigned uint;
const uint MAXN=200000;
bool vis[MAXN+5];
uint N,Ans;
int main(){
	scanf("%d",&N);
	Ans=N+1;
	for(uint i=1;i<=N;++i){
		int a;
		scanf("%d",&a);
		if(!vis[a]){
			--Ans;
			vis[a]=1;
		}
	}
	printf("%u\n",Ans);
	return 0;
}