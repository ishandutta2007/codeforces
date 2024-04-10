#include<bits/stdc++.h>
#define int long long
#define p2(x) ((x)*(x))
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
int min(int x,int y){return x>y?y:x;}
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans=1e18;
struct node{
	int a1,a2;
	double a3,a4;
	void change(double &c,double &s){
		a3=c*a1-s*a2;
		a4=s*a1+c*a2;
	}
	bool operator<(const node&x)const{return a3*a4<x.a3*x.a4;}
}a[N];
int dis(node&x,node&y){
	return p2(x.a1-y.a1)+p2(x.a2-y.a2);
}
void solve(double k){
	double x1=cos(k),x2=sin(k);
	rep(i,n)a[i].change(x1,x2);
	sort(a+1,a+1+n);
	rep(i,n)For(j,i+1,min(i+50,n))
		chmn(ans,dis(a[i],a[j]));
}
double Rand(){
	int x=rand()%1001;
	double y=1.0*x/1000;
	return y;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)a[i].a1=i,a[i].a2=read()+a[i-1].a2;
	rep(i,3)solve(Rand());
	cout<<ans<<endl;
	return 0;
}