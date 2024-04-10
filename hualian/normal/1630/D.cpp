#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e6+9;
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
int a[N],b[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T-->0){
		n=read(),m=read();
		int ans=0,res1=0,res2=0;
		rep(i,n)a[i]=read();
		rep(i,m)b[i]=read();
		int d=b[1];rep(i,m)d=__gcd(d,b[i]);
		rep(i,d){
			int sum=0,mn=1e18,f=0,ff=0;
			for(int j=i;j<=n;j+=d){
				if(a[j]<0)f^=1;
				else if(a[j]==0)ff=1;
				sum+=abs(a[j]);
				mn=min(mn,abs(a[j]));
			}
			ans+=sum;
			if(!ff){if(f)res1+=mn;else res2+=mn;}
		}
		printf("%lld\n",ans-2*min(res1,res2));
	}
	return 0;
}