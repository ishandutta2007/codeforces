#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a,x,b,y;
	scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
	while (true){
		if (a==b){
			puts("YES");
			return 0;
		}
		if (a==x){
			puts("NO");
			return 0;
		}
		if (b==y){
			puts("NO");
			return 0;
		}
		a=(a==n?1:a+1);
		b=(b==1?n:b-1);
	}
	return 0;
}