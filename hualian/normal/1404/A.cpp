#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
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
char s[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--) {
		int n=read(),k=read();
		scanf("%s",s+1);int f=1;
		int A=0,B=0,C=0;
		rep(i,k){
			int a=0,b=0,c=0;
			for(int j=i;j<=n;j+=k){
				if(s[j]=='1')a++;
				if(s[j]=='0')b++;
				if(s[j]=='?')c++;
			}
			if(a&&b)f=0;
			if(a)A++;if(b)B++;
			if(a+b==0)C++;
		}
		if(k%2)f=0;
		if(max(A,B)>k/2)f=0;
		puts(f?"YES":"NO");
	}
	return 0;
}