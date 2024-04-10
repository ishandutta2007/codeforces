#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

long long n,res=1,res2=1,i;

int main(){
	scanf("%lld",&n);
	for(i=n;i>=2;i--){
		res=res*i%M;
		res2=res2*2%M;
	}
	
	printf("%lld",(res-res2+M)%M);
}