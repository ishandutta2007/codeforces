#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+10;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],k,n;
bool vis[N];
void out(int x,int y){printf("%d %d\n",x,y),vis[x]=vis[y]=true;}
int main(){
	int T=read();
	while(T-->0){
		n=read(),k=read();
		For(i,0,n)vis[i]=0;
		if(k==0){
			For(i,0,n-1)if(!vis[i])
				out(i,(n-1)^i);
			continue;
		}
		if(k+1==n){
			if(n<=4){puts("-1");}
			else{
				out(n-1,n-2);out(1,3);
				out(n-4,0);
				For(i,0,n-1)if(!vis[i])out(i,(n-1)^i);
			}
			continue;
		}
		out(k,n-1);out((n-1)^k,0);
		For(i,0,n-1)if(!vis[i])out(i,(n-1)^i);
	}
	return 0;
}