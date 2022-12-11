#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		int f=-2;
		printf("%d",n);
		if(n==2){
			printf(" 1");--n;
		}
		for(register int i=2,d=n-2;i<=n;++i){
			printf(" %d",d);
			if(d+f==0){
				f=2;d=-1;
			}
			else if(d+f<0){
				f=2;d=0;
			}
			d+=f;
		}
		puts("");
	}
	return 0;
}