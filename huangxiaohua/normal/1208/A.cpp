#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&i,&j,&k);
		k%=3;
		if(k==0){printf("%d\n",i);}
		if(k==1){printf("%d\n",j);}
		if(k==2){printf("%d\n",i^j);}
	}
}