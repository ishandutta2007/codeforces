#include<iostream>
#define int long long
using namespace std;
const int N=2e5+9;
inline int read(){
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
   return x*f;
}
inline void WA(){
	puts("No");
	exit(0);
}
signed main(){
	int b=read(),a=read(),k=read();
	if(!k){
		puts("Yes");
		for(int i=1;i<=a;i++)
			putchar('1');
		for(int i=1;i<=b;i++)
			putchar('0');
		puts("");
		for(int i=1;i<=a;i++)
			putchar('1');
		for(int i=1;i<=b;i++)
			putchar('0');
		return 0;
	}
	int n=a+b;
	if(k>=a+b-1)WA();
	a--;
	if(!a||!b)WA(); 
	int x=0,y=0;
	int l=n-(k);
	a--,b--;
	puts("Yes");
	putchar('1');
	for(int i=2;i<=n;i++){
		if(i==l){
			putchar('1');
			continue;
		}
		if(i==n){
			putchar('0');
			continue;
		}
		if(x<a){
			x++,putchar('1');
		}
		else y++,putchar('0');
	}
	putchar('\n');
	putchar('1');
	x=0,y=0;
	for(int i=2;i<=n;i++){
		if(i==l){
			putchar('0');
			continue;
		}
		if(i==n){
			putchar('1');
			continue;
		}
		if(x<a){
			x++,putchar('1');
		}
		else y++,putchar('0');
	}
	return 0;
}