#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)

int i,j,n,m,k,t,res,sb;

int main(){
	scanf("%d",&t);
	while(t--){
		res=0;
		scanf("%d",&n);sb=n;k=0;
		while(n>=10){
			res++;n/=10;
		}
		k=n;
		for(i=1;i<=res;i++){
			k=k*10+n;
		}
		res*=9;
		res+=n-1;
		if(k<=sb){res++;}
		printf("%d\n",res);
	}
}