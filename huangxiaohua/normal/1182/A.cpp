#include<bits/stdc++.h>
using namespace std;

long long n;

int main(){
	scanf("%d",&n);
	if(n%2==1){puts("0");return 0;}
	printf("%lld",(long long)pow(2,n/2));
}