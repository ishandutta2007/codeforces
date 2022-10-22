#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=75;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int a[maxn];
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){puts("0");continue;}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int len=0;
				double d=1.0*(a[j]-a[i])/(j-i),a0=a[i]-(i-1)*d;
				for(int k=1;k<=n;k++)if(fabs(a[k]-(a0+(k-1)*d))<=1e-9)len++;
				res=max(res,len);
			}
		}
		printf("%d\n",n-res);
	}
    return 0;
}