#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=210;
int n;
char c[maxn][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		for(register int i=1;i<=n;++i)
			scanf("%s",c[i]+1);
		if(c[1][2]^c[2][1]){
			if(c[n][n-1]^c[n-1][n]){
				if(c[1][2]^c[n][n-1])printf("2\n2 1\n%d %d\n",n-1,n);
				else printf("2\n1 2\n%d %d\n",n-1,n);
			}
			else{
				if(c[1][2]^c[n][n-1])puts("1\n2 1");
				else puts("1\n1 2");
			}
			
		}
		else{
			if(c[n][n-1]^c[n-1][n]){
				if(c[1][2]^c[n][n-1])printf("1\n%d %d\n",n-1,n);
				else printf("1\n%d %d\n",n,n-1);
			}
			else{
				if(c[1][2]^c[n][n-1])puts("0");
				else printf("2\n%d %d\n%d %d\n",n,n-1,n-1,n);
			}
		}
	}
	return 0;
}