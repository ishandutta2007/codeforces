#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ll m=1;bool tag=0;
		for(int i=1;i<=n;i++){
			if(m<=1e9)m=m*(i+1)/gcd(m,i+1);
			if(a[i]%m==0){tag=1;break;}
		}
		if(tag)puts("NO");
		else puts("YES");
	}
    return 0;
}