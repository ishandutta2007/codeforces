#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int t[maxn];
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
		for(int i=0;i<=100;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[read()]++;
		int res=0;
		for(int i=0;i<=100;i++)if(!t[i]){res+=i;break;}
		for(int i=0;i<=100;i++)if(t[i]<2){res+=i;break;}
		printf("%d\n",res);
	}
    return 0;
}