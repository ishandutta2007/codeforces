#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2010;
double eps=1e-8;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,A,B; 
int cntA,cntB;
double a[N],b[N],c[N],res;
void check(double m1,double m2){
	res=0;cntA=0;cntB=0;
	rep(i,n){
		double x1,x2,x3,x4;
		x1=0;x2=a[i]-m1;x3=b[i]-m2;x4=c[i]-m1-m2;
		if(x1>=x2&&x1>=x3&&x1>=x4){res+=x1;continue;}
		if(x2>=x1&&x2>=x3&&x2>=x4){res+=x2;cntA++;continue;}
		if(x3>=x1&&x3>=x2&&x3>=x4){res+=x3;cntB++;continue;}
		if(x4>=x1&&x4>=x2&&x4>=x3){res+=x4;cntA++,cntB++;continue;}
	}
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),A=read(),B=read();
	rep(i,n)cin>>a[i];rep(i,n)cin>>b[i];
	rep(i,n)c[i]=1-(1-a[i])*(1-b[i]);
	double l1=0,r1=1,l2,r2,m1,m2;
	while(abs(r1-l1)>eps){
		m1=(l1+r1)/2;
		l2=0,r2=1;
		while(abs(r2-l2)>eps){
			m2=(l2+r2)/2;	
			check(m1,m2);
			if(cntB==B)break;
			if(cntB>B)l2=m2;
			else r2=m2;
		}
		if(cntA==A)break;
		if(cntA>A)l1=m1;
		else r1=m1;
	}
	printf("%.8lf",res+A*m1+B*m2);
	return 0;
}