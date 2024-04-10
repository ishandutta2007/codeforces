#include<bits/stdc++.h>
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
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T--){
		int n=read(),x=read(),y=read();
		if(x+y>n-2){puts("-1");continue;}
		if(abs(x-y)>=2){puts("-1");continue;}
		int l=1,r=n;
		if(y>x){
			rep(i,y)cout<<(r--)<<" "<<(l++)<<" ";
			For(i,l,r)cout<<i<<" ";puts("");
		}else if(x>y){
			rep(i,x)cout<<(l++)<<" "<<(r--)<<" ";
			Rof(i,r,l)cout<<i<<" ";puts("");	
		}else if(x==y){
			rep(i,x)cout<<(l++)<<" "<<(r--)<<" ";
			For(i,l,r)cout<<i<<" ";puts("");	
		}
	}
	return 0;
}