#include<bits/stdc++.h>
#define reg register
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=3e5+10;
char a[N];
signed main(){
	int t=read();
	while(t--){
		scanf("%s",a+1);
		int n=strlen(a+1);
		int l=1,r=n,f=0;
		while(l<=r){
			if(a[l]!='a'){
				puts("YES");
				for(int i=1;i<=r;i++)putchar(a[i]);
				putchar('a');
				for(int i=r+1;i<=n;i++)putchar(a[i]);
				puts("");f=1;break;
			}
			if(a[r]!='a'){
				puts("YES");
				for(int i=1;i<=l-1;i++)putchar(a[i]);
				putchar('a');
				for(int i=l;i<=n;i++)putchar(a[i]);
				puts("");f=1;break;
			}
			l++,r--;
		}
		if(!f)puts("NO");
	}
	return 0;
}