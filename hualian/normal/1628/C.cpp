#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e3+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans=0;
int a[N][N],A[N][N];
int b[N][N];
void solve(){
	rep(i,n+2)rep(j,n+2)b[i][j]=0;
	For(k,0,30){
		rep(i,n)rep(j,n)a[i][j]=(A[i][j]&(1<<k));
		rep(i,n-1)b[i+1][i]=(a[i][i]^b[i][i-1]);
		rep(i,n-1){
			int x=i+2,y=i-1;
			int X=i-1,Y=i+2;
			while(x<=n&&y>=1){
				b[x][y]=a[x-1][y]^a[X][Y-1]^b[x-1][y-1]^b[x-2][y]^b[x-1][y+1];
				x++;y--;
				X--;Y++;
			}
		}
		rep(i,n)rep(j,n)ans^=b[i][j];
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T-->0){
		n=read();ans=0;
		rep(i,n)rep(j,n)A[i][j]=read();
		solve();
		rep(i,n)reverse(A[i]+1,A[i]+1+n);
		solve();
		cout<<ans<<endl;
	}
	return 0;
}