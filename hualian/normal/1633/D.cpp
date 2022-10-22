#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
#define int long long
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
const int N=1e3+10;
int n,k,w[N],v[N],f[N],g[N*13];
signed main(){
	memset(f,0x3f,sizeof f);f[1]=0;
	For(i,1,1000)For(x,1,i)f[i+i/x]=min(f[i+i/x],f[i]+1);
	int T=read();while(T--){
		n=read(),k=min(n*12,read());
		For(i,1,n)w[i]=f[read()];For(i,1,n)v[i]=read();
		memset(g,0,sizeof g);
		For(i,1,n)Rof(j,k,w[i])g[j]=max(g[j],g[j-w[i]]+v[i]);
		cout<<g[k]<<endl;
	}
	return 0;
}