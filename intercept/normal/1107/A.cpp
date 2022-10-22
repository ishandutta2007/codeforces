#include<iostream>
#include<cstdio>
using namespace std;
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
char c[309];
void solve(){
	int n=read();
	scanf("%s",c+1);
	if(n==2){
		if(c[1]>=c[2])printf("NO\n");
		else {
			printf("YES\n");
			printf("2\n");
			printf("%c %s\n",c[1],c+2);
		}
	}
	else {
		printf("YES\n");
		printf("2\n");
		printf("%c %s\n",c[1],c+2);
	}
}
int main(){
	int T=read();
	for(int i=1;i<=T;++i)solve();
	return 0;
}