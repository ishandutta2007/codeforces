#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a,b,c;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		a=read();b=read();c=read();
        printf("%lld\n",a+b+c-1);
	}
	return 0;
}