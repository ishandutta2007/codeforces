#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[200010];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--) {
		int n=read(),k=read();rep(i,n)a[i]=read();
		int g=0;
		sort(a+1,a+1+n);
		rep(i,n-1)g=__gcd(g,abs(a[i]-a[i+1]));
		if(abs(k-a[1])%g==0)puts("YES");
		else puts("NO");
	}
	return 0;
}