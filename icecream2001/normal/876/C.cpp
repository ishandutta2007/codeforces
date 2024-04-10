#include<iostream>
#include<cstdio>
using namespace std;
int n;
int q[300],cnt;
int calc(int x){
	int y=0;
	while(x){
		y+=x%10;
		x/=10;
	}
	return y;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(int i=200;i>=0;i--){
			if(n<i) continue;
			if(calc(n-i)==i)
				q[++cnt]=n-i;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",q[i]);
		printf("\n");
	}
	return 0;
}