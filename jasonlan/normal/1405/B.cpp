#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,cpos,x;
inline ll read(){
    ll res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		cpos=0;
		while(n--){
			x=read();
			if(x>=0)cpos+=x;
			else
				cpos=max(0ll,cpos+x);
		}
		printf("%lld\n",cpos);
	}
    return 0;
}