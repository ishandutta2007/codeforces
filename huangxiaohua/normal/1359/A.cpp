#include<bits/stdc++.h>
using namespace std;

int i,j=0,t,n,m,k;


int main(){
	scanf("%d",&t);

	for(i=1;i<=t;i++){
		scanf("%d%d%d",&n,&m,&k);
		if(n/k>=m){printf("%d\n",m);continue;}
		j=(m-n/k);
		printf("%d\n",n/k-j/(k-1)-((j%(k-1))!=0));
	}
	return 0;
}