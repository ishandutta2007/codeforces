#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF1572B.in","r",stdin);
//    freopen("CF1572B.out","w",stdout);
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=a[i-1]^read();
		bool tag=0;int pos=0;
		for(int i=1;i<=n;i+=2)if(!a[i])tag=1,pos=i;
		if(((n&1)&&a[n])||((n%2==0)&&(!tag||a[n]))){puts("NO");continue;}
		puts("YES");
		int len=0;
		for(int i=1;i<=n-2;i+=2)len++;
		if(n&1)len*=2;
		else{
			for(int i=pos+1;i<=n-2;i+=2)len++;
			for(int i=pos-2;i>=1;i-=2)len++;
		}
		printf("%d\n",len);
		if(n&1)for(int i=n-2;i>=1;i-=2)printf("%d ",i);
		else{
			for(int i=pos+1;i<=n-2;i+=2)printf("%d ",i);
			for(int i=pos-2;i>=1;i-=2)printf("%d ",i);
		}
		for(int i=1;i<=n-2;i+=2)printf("%d ",i);
		puts("");
	}
    return 0;
}