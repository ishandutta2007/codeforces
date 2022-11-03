#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,k;
	int *res;
	bool b=false;
	scanf("%d",&n);
	res = new int [n];
	for(int i=0;i<n;++i){
		res[i]=0;
		for(int j=0;j<n;++j){
			scanf("%d",&k);
			if(j!=i && k>res[i]){
				res[i]=k;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!b && res[i]==n-1){
			b=true;
			res[i]=n;
		}
		printf("%d ",res[i]);
	}
	return 0;
}