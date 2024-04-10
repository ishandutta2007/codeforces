#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q;
char s[N];
int aa[N],bb[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();scanf("%s",s+1);
	rep(i,n)
		aa[i]=aa[i-1]+(s[i]=='0'&&s[i-1]=='0'),
		bb[i]=bb[i-1]+(s[i]=='1'&&s[i-1]=='1');
	while(q--){
		int l=read(),r=read();
		int x=aa[r]-aa[l];
		int y=bb[r]-bb[l];
		printf("%d\n",max(x,y)+1);
	}
	return 0;
}