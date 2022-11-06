#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,u,v,lft,rit;
int main(){
	Testing=read();
	//(xv+yu)/uv=(x+y)/(u+v)
	//0=yu^2+xv^2
	for (;Testing;Testing--){
		u=read();v=read();
		printf("%lld %lld\n",-u*u,v*v);
	}
return 0;
}