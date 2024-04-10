#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("b.in","r",stdin);
//    freopen("b.out","w",stdout);
   	int t;
	t=read();
	while(t--){
		int n,mina,minb;
		long long ans=0;
		mina=minb=1e9;
		n=read();
		for(int i=1;i<=n;i++){a[i]=read();mina=min(mina,a[i]);}
		for(int i=1;i<=n;i++){b[i]=read();minb=min(minb,b[i]);}
		for(int i=1;i<=n;i++)
			ans+=max(a[i]-mina,b[i]-minb);
		printf("%lld\n",ans);
	}
    return 0;
}