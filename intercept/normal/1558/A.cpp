#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[200009];
void work(){
	scanf("%d%d",&a,&b);
	int n=a+b,m=0;
	for(int i=0;i<=(n+1)/2&&i<=a;++i){
		if(a-i>n/2)continue;
		c[++m]=i+n/2-(a-i);
		c[++m]=a-i+(n+1)/2-i;
	}
	sort(c+1,c+m+1);
	int num=unique(c+1,c+m+1)-c-1;
	printf("%d\n",num);
	for(int i=1;i<=num;++i)printf("%d%c",c[i]," \n"[i==num]);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}