#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int inf=1e18;
const int N=1e3+9;
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
int a[N],n,ans=inf;
int G(int x){
	int res=0;
	rep(i,n)res+=x/a[i],x-=x/a[i]*a[i];
	return res;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)a[i]=read();
	For(i,2,n){
		int x=a[i-1]-1,res=0;
		For(j,i,n){
			res+=x/a[j];
			x-=x/a[j]*a[j];
			if(res+1<G((a[i-1]-1)-x+a[j]))
				chmn(ans,(a[i-1]-1)-x+a[j]);
		}
	}
	if(ans==inf)puts("-1");
	else cout<<ans<<endl;
	return 0;
}