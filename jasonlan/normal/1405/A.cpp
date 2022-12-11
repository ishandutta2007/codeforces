#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=101000;
int n;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		for(register int i=1;i<=n;++i)a[i]=read();
		for(register int i=1;i<=n;++i)printf("%d ",a[n-i+1]);
		putchar('\n');
	}
    return 0;
}