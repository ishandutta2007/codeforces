#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<10){printf("%d\n",(n%10-1)*10+1);continue;}
		if(n<100){printf("%d\n",(n%10-1)*10+3);continue;}
		if(n<1000){printf("%d\n",(n%10-1)*10+6);continue;}
		if(n<10000){printf("%d\n",(n%10-1)*10+10);continue;}
	}
}