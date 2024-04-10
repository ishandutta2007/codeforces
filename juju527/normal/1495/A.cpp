#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
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
		int n,p=0,q=0;
		n=read();
		for(int i=1;i<=2*n;i++){
			int x,y;
			x=read();y=read();
			if(x<0)x=-x;if(y<0)y=-y;
			if(!x)a[++p]=y;
			else b[++q]=x;
		}
		sort(a+1,a+p+1);sort(b+1,b+q+1);
		db res=0;
		for(int i=1;i<=n;i++)res+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
		printf("%.10lf\n",res);
	}
    return 0;
}