#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m; 
int a[N],b[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n)a[i]=read();sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	rep(i,m)b[i]=read();
	if(n==1){
		rep(i,m)cout<<a[1]+b[i]<<" ";return 0;
	}
	int G=a[2]-a[1];
	For(i,2,n)G=gcd(G,a[i]-a[i-1]);
	rep(i,m){
		cout<<gcd(G,b[i]+a[1])<<" ";
	}
	return 0;
}