#include<bits/stdc++.h>
#define int long long
#define p2(x) ((x)*(x))
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n;
int res[N],a[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)a[i]=read();
	For(i,2,n){
		int x=i-2;
		for(int l=1,r;l<=x;l=r+1){
			r=min(x/(x/l),x);
			int fa=x/l+1;
			if(a[fa]>a[i])res[l]++,res[r+1]--;
		}
		if(a[1]>a[i])res[x+1]++;
	}
	rep(i,n)res[i]+=res[i-1];
	rep(i,n-1)printf("%d ",res[i]);
	return 0;
}