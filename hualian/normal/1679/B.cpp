#include<bits/stdc++.h>
#define int long long
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
int a[N],tag[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),q=read();
	int sum=0;
	rep(i,n)a[i]=read(),sum+=a[i];
	int now=0,all=0;
	while(q--){
		int t=read();
		if(t==1){
			int i=read(),x=read();
			if(tag[i]==now)sum-=a[i],sum+=x,a[i]=x;
			else sum-=all,sum+=x,a[i]=x,tag[i]=now;
		}else{
			now++;all=read();sum=all*n;
		}
		cout<<sum<<endl;
	}
	return 0;
}