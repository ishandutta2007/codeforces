#include<bits/stdc++.h>
using namespace std;
int a,b,k;
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(!a){
		if(k)printf("No\n");
		else{
			printf("Yes\n");
			for(int i=1;i<=b;++i)printf("1");printf("\n");
			for(int i=1;i<=b;++i)printf("1");printf("\n");
		}
	}
	else if(b==1){
		if(k)printf("No\n");
		else{
			printf("Yes\n1");
			for(int i=1;i<=a;++i)printf("0");printf("\n1");
			for(int i=1;i<=a;++i)printf("0");printf("\n");
		}
	}
	else if(!k){
		printf("Yes\n");
		int c=b;
		for(int i=1;i<=a+b;++i)printf("%d",--c>=0);
		printf("\n");
		c=b;
		for(int i=1;i<=a+b;++i)printf("%d",--c>=0);
	}
	else{
		if(a+b-2<k)printf("No\n");
		else{
			printf("Yes\n");
			int c=b;
			for(int i=1;i<a+b-k;++i)printf("%d",--c>0);
			printf("1");
			for(int i=a+b-k+1;i<a+b;++i)printf("%d",--c>0);
			printf("0\n");
			c=b;
			for(int i=1;i<a+b-k;++i)printf("%d",--c>0);
			printf("0");
			for(int i=a+b-k+1;i<a+b;++i)printf("%d",--c>0);
			printf("1\n");
		}
	}
}