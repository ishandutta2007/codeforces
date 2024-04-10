#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e6+9;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int T,n,c;
int a[N];
int sum[N];
int main(){
//	freopen(".in","r",stdin);
//	froepen(".out","w",stdout);
	T=read();
	while(T--){
		n=read(),c=read();bool flag=1;
		rep(i,c+c)sum[i]=0;
		rep(i,n)sum[a[i]=read()]++;
		rep(i,c+c)sum[i]+=sum[i-1];
		sort(a+1,a+1+n);
		rep(i,n)if(a[i]!=a[i-1]){
			int x=a[i];
			for(int j=x;j<=c;j+=x){
				if(sum[j+x-1]-sum[j-1]){
					if(!(sum[j/x]-sum[j/x-1]))flag=0;
				}
			}
		}
		puts(flag?"Yes":"No") ;
	}
	return 0;
}