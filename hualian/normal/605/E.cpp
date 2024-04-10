#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e3+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
bool vis[N];
double p[N][N];
double prod[N];
double ans[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();if(n==1){puts("0");return 0;}
	rep(i,n)rep(j,n)p[i][j]=1.0*read()/100;
	rep(i,n-1)prod[i]=1-p[i][n],ans[i]=1;vis[n]=1;
	ans[0]=1e18;
	rep(k,n){
		int id=0;
		rep(i,n)if(!vis[i]&&ans[i]/(1-prod[i])<ans[id]/(1-prod[id]))id=i;
		if(id==1)return printf("%.8lf",ans[1]/(1-prod[id])),0;
		vis[id]=1;
		rep(i,n)ans[i]+=ans[id]/(1-prod[id])*p[i][id]*prod[i],prod[i]*=(1-p[i][id]); 
	}
	return 0;
}