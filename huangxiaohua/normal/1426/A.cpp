#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,res,x;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);res=1;
		if(n<=2){puts("1");continue;
		}
		res+=(n-2)/x+(((n-2)%x)>0);
		printf("%d\n",res);
	}
}