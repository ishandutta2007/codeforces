#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,a,b,c,d,bb,cc;

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==(b+1)&&(c||d)||a>(b+1)){puts("NO");return 0;}
	if(a==(b+1)&&!(c||d)){
		puts("YES");
		printf("0 ");
		for(i=1;i<=b;i++){
			printf("1 0 ");
		}return 0;
	}
	if(d==(c+1)&&(a||b)||d>(c+1)){puts("NO");return 0;}
	if(d==(c+1)&&!(a||b)){
		puts("YES");
		printf("3 ");
		for(i=1;i<=c;i++){
			printf("2 3 ");
		}return 0;
	}
	bb=b-a;cc=c-d;
	
	if(bb==cc){
		puts("YES");
		for(i=1;i<=a;i++){printf(" 0 1");}
		for(i=1;i<=bb;i++){printf(" 2 1");}
		for(i=1;i<=d;i++){printf(" 2 3");}
		return 0;
	}
	
	if((bb+1)==cc){
		puts("YES");
		for(i=1;i<=a;i++){printf(" 0 1");}
		for(i=1;i<=bb;i++){printf(" 2 1");}
		for(i=1;i<=d;i++){printf(" 2 3");}
		printf(" 2");
		return 0;
	}
	
	if((cc+1)==bb){
		puts("YES");
		printf("1");
		for(i=1;i<=a;i++){printf(" 0 1");}
		for(i=1;i<=cc;i++){printf(" 2 1");}
		for(i=1;i<=d;i++){printf(" 2 3");}
		return 0;
	}
	puts("NO");
}