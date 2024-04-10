#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
char s[maxn];
int a[maxn][maxn];
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
		int n,m;
		n=read();m=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)a[i][j]=(s[j]=='X');
		}
		for(int i=1;i<=n;i+=3){
			for(int j=1;j<=m;j++)a[i][j]=1;
			if(i+1>=n)continue;
			if(i+2==n){
				for(int j=1;j<=m;j++)if(a[i+1][j]||a[i+2][j])a[i+1][j]=a[i+2][j]=1;
				continue;
			}
			if(a[i+1][2]||a[i+2][2])a[i+1][2]=a[i+2][2]=1;
			else a[i+1][1]=a[i+2][1]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j])putchar('X');
				else putchar('.');
			}
			puts("");
		}
	}
    return 0;
}