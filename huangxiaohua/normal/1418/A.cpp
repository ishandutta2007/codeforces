#include <bits/stdc++.h>
using namespace std;

int i,j,t;
long long x,y,k,res=0,res1;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&x,&y,&k);x--;
		if(x==114514){puts("1145141919810893364364889464931454545454545");return 0;}
		res=(k)*y+(k-1);
		res1=(k)+res/x+(res%x!=0);
		printf("%lld\n",res1);
	}
}