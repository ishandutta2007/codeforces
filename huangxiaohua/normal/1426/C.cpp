#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,x,res,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		k=sqrt(x);
		if(k*k>=x){res=k+k-2;
		}else{if(k*(k+1)>=x){res=k+k-1;}
		else{res=k+k;}
		}
		printf("%d\n",res);
	}
}