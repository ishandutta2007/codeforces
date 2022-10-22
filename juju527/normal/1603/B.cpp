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
		int x,y;
		x=read();y=read();
		if(x>y)printf("%d\n",x+y);
		else if(x==y)printf("%d\n",x);
		else{
			int z=y/x*x;
			printf("%d\n",(z+y)/2);
		}
	}
    return 0;
}