#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,ans;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void proc(ll x){
	while(x){
		if(x%2)--x;
		if(!x)break;
		if(x%4||x==4)ans+=(x/=2);
		else ans+=x/2,x=x/2-1;
	}
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		ans=0;proc(n);
		printf("%lld\n",(n&1)?(n-ans):ans);
	}
	return 0;
}