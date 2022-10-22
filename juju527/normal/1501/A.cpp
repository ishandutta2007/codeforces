#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],b[maxn];
int tt[maxn];
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
		int n;
		n=read();
		for(int i=1;i<=n;i++){a[i]=read();b[i]=read();}
		for(int i=1;i<=n;i++)tt[i]=read();
		int t=a[1]+tt[1];
		for(int i=1;i<n;i++){
			t=max(t+(b[i]-a[i]+1)/2,b[i]);
			t+=a[i+1]-b[i]+tt[i+1];
		}
		printf("%d\n",t);
	}
    return 0;
}