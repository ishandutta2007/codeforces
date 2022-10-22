#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int a[maxn],t[105];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
   	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){puts("YES");continue;}
		for(int i=1;i<=100;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[a[i]]++;
		int num=0;
		bool flag=0;
		for(int i=1;i<=101;i++){
			if(t[i]==0&&flag){num++;flag=0;}
			if(t[i])flag=1;
		}
		if(num>1){puts("NO");continue;}
		puts("YES");	
	}
    return 0;
}