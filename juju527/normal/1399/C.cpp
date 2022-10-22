#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int t[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("c.in","r",stdin);
//    freopen("c.out","w",stdout);
   	int T;
	T=read();
	while(T--){
		int n,ans=0;
		n=read();
		for(int i=1;i<=2*n;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[read()]++;
		for(int i=1;i<=2*n;i++){
			int sum=0;
			if(i&1)
				for(int j=1;j<=i/2;j++)
					sum+=min(t[j],t[i-j]);
			else{
				for(int j=1;j<i/2;j++)
					sum+=min(t[j],t[i-j]);
				sum+=t[i/2]/2;
			}
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
    return 0;
}