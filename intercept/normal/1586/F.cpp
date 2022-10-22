#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",(int)ceil(log(n)/log(k)));
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int x=i,y=j,v=0;
			while(x!=y)x/=k,y/=k,v++;
			printf("%d ",v);
		}
	}
	return 0;
}