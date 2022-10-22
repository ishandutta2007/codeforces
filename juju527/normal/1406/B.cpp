#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int a[maxn],b[maxn];
int main(){
	int T;
	T=read();
	while(T--){
		int n,l1=0,l2=0;
		n=read();
		for(int i=1;i<=n;i++){
			int x;
			x=read();
			if(x<=0)a[++l1]=x;
			else b[++l2]=x;
		}
		sort(a+1,a+l1+1),sort(b+1,b+l2+1);
		ll res=-1e18;
		for(int i=0;i<=min(5,l1);i++){
			if(5-i<=l2){
				ll p=1;
				if(i%2==0)for(int j=1;j<=i;j++)p*=a[j];
				else for(int j=l1;j>l1-i;j--)p*=a[j];
				if(i%2==0)for(int j=l2;j>l2-5+i;j--)p*=b[j];
				else for(int j=1;j<=5-i;j++)p*=b[j];
				res=max(res,p);
			}
		}
		printf("%lld\n",res);
	}
    return 0;
}