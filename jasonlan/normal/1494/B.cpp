#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int n,a[4],b[4];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch=='-'?-res:res;
}
bool check(int f){
	for(int i=0;i<4;++i)
		b[i]=0;
	for(int i=0;i<4;++i)
		if((f>>i)&1){
			--b[i];--b[(i+1)%4];
		}
	for(int i=0;i<4;++i)
		if(a[i]+b[i]>=0&&a[i]+b[i]<=n-2);
		else return false;
	return true;
}
bool initcheck(){
	for(int i=0;i<16;++i)
		if(check(i))return true;
	return false;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=0;i<4;++i)
			a[i]=read();
		puts(initcheck()?"YES":"NO");
	}
	return 0;
}