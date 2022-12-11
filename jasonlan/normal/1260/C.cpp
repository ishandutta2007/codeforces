#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x,y,k;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch=='-'?-res:res;
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	int T=read();ll g,ekl,x2,y2,t;
	bool flag;
	while(T--){
		x=read();y=read();k=read();
		if(x>y)swap(x,y);
		g=gcd(x,y);
		x/=g;y/=g;
		ekl=y-1-(k-1)*x;
		if(ekl<=0)puts("OBEY");
		else puts("REBEL");
	}
	return 0;
}