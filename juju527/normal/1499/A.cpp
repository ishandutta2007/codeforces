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
int main(){
	int T;
	T=read();
	while(T--){
		int n,k1,k2,w,b;
		n=read();k1=read();k2=read();
		w=read();b=read();
		if(w<=(k1+k2)/2&&b<=(n-k1+n-k2)/2)puts("YES");
		else puts("NO");
	}
    return 0;
}