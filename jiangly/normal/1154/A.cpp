#include<bits/stdc++.h>
using namespace std;
int x[5];
int main(){
	for(int i=1;i<=4;++i){
		scanf("%d",&x[i]);
	}
	sort(x+1,x+5);
	for(int i=1;i<=3;++i){
		printf("%d ",x[4]-x[i]);
	}
	return 0;
}