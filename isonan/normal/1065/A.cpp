#include <cstdio>

long long T,s,a,b,c;
int main(){
	scanf("%I64d",&T);
	for(int i=1;i<=T;i++){
		scanf("%I64d%I64d%I64d%I64d",&s,&a,&b,&c);
		printf("%I64d\n",(s/c)+((s/(c*a))*b));
	}
}