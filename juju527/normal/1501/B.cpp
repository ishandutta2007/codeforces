#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],s[maxn];
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
		for(int i=1;i<=n;i++)s[i]=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			s[max(i-a[i]+1,1)]++;s[i+1]--;
		}
		for(int i=1;i<=n;i++)s[i]+=s[i-1];
		for(int i=1;i<=n;i++)printf("%d ",(s[i]>0));
		puts("");
	}
    return 0;
}