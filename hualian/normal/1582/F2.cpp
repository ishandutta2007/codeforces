#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
const int lim=8192;
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
int n;
stack<int>s[8192];
int a[N],dp[N];
void add(int x,int l,int r){
	chmn(r,lim-1);
	For(i,l,r)s[i].push(x^i);
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)a[i]=read();
	rep(i,lim)dp[i]=lim;dp[0]=0;
	rep(i,lim-1)s[i].push(i);
	//s[i]jij 
	rep(i,n){
		int x;
		while(s[a[i]].size()){
			x=s[a[i]].top();s[a[i]].pop();
			//a[i]x
			if(dp[x]>a[i])add(x,a[i]+1,dp[x]),dp[x]=a[i];
		}
	}
	int cnt=0;
	For(i,0,lim)if(dp[i]!=lim)cnt++;
	cout<<cnt<<endl;
	For(i,0,lim)if(dp[i]!=lim)printf("%d ",i);
	
	return 0;
}