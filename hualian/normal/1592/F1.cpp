#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=510;
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
int n,m; 
int a[N][N],s[N][N];
int ans;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n)rep(j,m){
		char c;cin>>c;
		a[i][j]=(c=='B');
	}
	rep(i,n)rep(j,m)s[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1],ans+=s[i][j];
	For(i,2,n)For(j,2,m){
		if(s[i-1][j-1]&&s[i-1][m]&&s[n][j-1]&&s[n][m]){cout<<ans-1<<endl;return 0;}
	}cout<<ans<<endl;
	return 0;
}