#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char e=getchar(),f=getchar();
	scanf("\n");
	int ans=0;
	for (int i=1;i<=5;i++){
		char a=getchar(),b=getchar(),c=getchar();
		ans|=(e==a)+(b==f);
	}
	printf(ans?"YES\n":"NO\n");
}