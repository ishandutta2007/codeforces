#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,K;
int mp[N][N];

void sol(int l,int r,int C){
	if(l==r) return;
	int m=r-l+1;
	int X=m/K,Y=m-X*K;
	for(int i=l,j=l+X-1,js=1;;){
		for(int now=i;now<=j;++now){
			for(int k=j+1;k<=r;++k){
				mp[now][k]=C;
			}
		}
		if(i<=j) sol(i,j,C+1);
		i=j+1;
		++js;
		if(js+Y<=K) {
			j=i+X-1;
		}
		else{
			j=i+X;
		}
		if(js>K) break;
	}
	return;
}
void MAIN(){
	scanf("%d%d",&n,&K);
	sol(1,n,1);
	int C=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			C=max(C,mp[i][j]);
		}
	}
	printf("%d\n",C);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			printf("%d ",mp[i][j]);
		}
	}
	puts("");
	return;
} 
int main(){
    int ttt=1;
    while(ttt--){
   	    MAIN();
    }
    return 0;
}
/*

*/