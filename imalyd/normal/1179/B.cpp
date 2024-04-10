#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1,j=n;i<j;++i,--j){
		for(k=1,l=m;k<=m;++k,--l)printf("%d %d\n%d %d\n",i,k,j,l);
	}
	if(i==j){
		for(k=1,l=m;k< l;++k,--l)printf("%d %d\n%d %d\n",i,k,i,l);
		if(k==l)printf("%d %d\n",i,k);
	}
	return 0;
}