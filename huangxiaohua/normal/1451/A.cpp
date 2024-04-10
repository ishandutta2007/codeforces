#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,t;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){puts("0");continue;}
		if(n==2){puts("1");continue;}
		if(n==3){puts("2");continue;}
		if(n%2){puts("3");continue;}
		puts("2");
	}
}