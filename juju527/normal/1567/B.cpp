#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int f(int n){
	if(n%4==0)return n;
	else if(n%4==1)return 1;
	else if(n%4==2)return n+1;
	return 0;
}
int main(){
	int T;
	T=read();
	while(T--){
		int a,b,x,y;
		a=read();b=read();
		x=f(a-1);y=b^x;
		if(y==a)printf("%d\n",a+2);
		else printf("%d\n",a+(y>0));
	}
    return 0;
}