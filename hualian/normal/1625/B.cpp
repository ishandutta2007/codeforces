#include<bits/stdc++.h>
#define int long long
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
using namespace std;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=3e5+9;
int a[N],m,n,pla[N],T,ans;
signed main(){
    T=read();
    while(T-->0){
        n=read();ans=-1;
        rep(i,n){
			a[i]=read();
			if(pla[a[i]])chmx(ans,n-i+pla[a[i]]);
			pla[a[i]]=i;
		}
		rep(i,n)pla[a[i]]=0;
		printf("%lld\n",ans);
    }
    return 0;
}