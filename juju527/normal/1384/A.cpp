#include<bits/stdc++.h>
using namespace std;
char lst[105];
int a[105];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=a[1];i++){lst[i]='a';printf("a");}
		for(int i=a[1]+1;i<=51;i++){lst[i]='c';printf("c");}
		putchar('\n');
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=a[i-1];j++)putchar(lst[j]);
			for(int j=a[i-1]+1;j<=51;j++){
				lst[j]=lst[j]+1;
				if(lst[j]>'z')lst[j]='a';
				putchar(lst[j]);
			}
			putchar('\n');
		}
	}
	return 0;
}