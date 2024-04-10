#include<bits/stdc++.h>
using namespace std;
int n,k;
int h[109];
void work(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	h[n+1]=0;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			if(h[j]<h[j+1]){
				h[j]++;
				if(i==k){
					printf("%d\n",j);
					return;
				}
				break;
			}
			if(j==n){
				printf("-1\n");
				return;
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}