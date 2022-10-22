#include<bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n;
struct node{
	int a,c; 
	bool operator<(const node&x)const{
		return a==x.a?c<x.c:a<x.a;
	}
}A[N];//aj>=ai+ci 
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();int ans=0; 
	rep(i,n)A[i].a=read(),A[i].c=read(),ans+=A[i].c;
	sort(A+1,A+1+n);
	int mx=A[1].a+A[1].c;
	rep(i,n){
		ans+=max(0ll,A[i].a-mx);
		chmx(mx,A[i].a+A[i].c);
	}cout<<ans<<endl;
	return 0;
}