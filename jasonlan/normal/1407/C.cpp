#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10100;
int n;
int ans[maxn];
int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n);
	for(register int i=2,mx=1,x1,x2;i<=n;++i){
		x1=query(mx,i);x2=query(i,mx);
		if(x1>x2){
			ans[mx]=x1;mx=i;
		}
		else{
			ans[i]=x2;
		}
	}
	putchar('!');
	for(register int i=1;i<=n;++i)
		printf(" %d",ans[i]?ans[i]:n);
	return 0;
}