#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=105;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
signed main(){
	int T;
	T=read();
	while(T--){
		ll s,n;
		s=read();n=read();
		for(int i=0;i<n;i++)a[i]=0;
		int num=0;
		for(int d=9;d>=0;d--){
			int pw=pow(10,d);
			int val=s/pw;
			for(int v=val;v>=0;v--){
				if(s-v*pw>=n-min(num+v,n)){
					int p=num%n;
					num=min(num+v,n),s-=v*pw;
					for(int i=1;i<=v;i++){a[p]+=pw;p++;p%=n;}
					break;
				}
			}
		}
		for(int i=0;i<n;i++)printf("%lld ",a[i]);
		puts("");
	}
    return 0;
}