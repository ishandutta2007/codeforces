#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=200010;
int n,m,k;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void process(){
	n=read();k=read();m=read();
	for(register int i=1;i<=m;++i)
		a[i]=read();
	if(n==m)puts("YES");
	else if((n-m)%(k-1))puts("NO");
	else{
		for(register int i=1;i<=m;++i)
			if((a[i]-i)>=(k-1)/2&&(n-a[i]-(m-i))>=(k-1)/2){
				puts("YES");return;
			}
		puts("NO");
	}
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}