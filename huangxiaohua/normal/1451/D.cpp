#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int j,n,t,a[30],b[30],allji;
long long x,y,r,k,i;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&r,&k);
		for(i=1;;i++){
			if(2*i*i*k*k>r*r){i--;break;}
		}
		if((i*i*k*k)+(i*i+2*i+1)*k*k<=r*r){puts("Ashish");
		}else{puts("Utkarsh");
		}
		aaa:;
	}
}