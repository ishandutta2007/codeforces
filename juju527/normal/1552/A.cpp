#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
char s[maxn],t[maxn];
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
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)t[i]=s[i];
		sort(t+1,t+n+1);
		int res=0;
		for(int i=1;i<=n;i++)if(t[i]^s[i])res++;
		printf("%d\n",res);
	}
    return 0;
}