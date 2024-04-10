#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n>36){
		printf("-1\n");
		return 0;
	}
	if(!n){
		printf("1");return 0;
	}
	while(n>=2){
		printf("8");n-=2;
	}
	if(n==1){
		printf("4");
	}
	return 0;
}