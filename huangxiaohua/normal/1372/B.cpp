#include <bits/stdc++.h>
using namespace std;

int n,i,j,t,a;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		if(t%2==0){printf("%d %d\n",t/2,t/2);continue;}
		a=t;
		for(i=3;i<=sqrt(t);i++){
			if(t%i==0){a=i;break;}
		}
		printf("%d %d\n",t/a,t-t/a);
	}
}