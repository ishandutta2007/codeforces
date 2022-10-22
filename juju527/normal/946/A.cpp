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
	int n;
	n=read();
	int res=0;
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		if(x>0)res+=x;
		else res-=x;
	}
	printf("%d\n",res);
    return 0;
}