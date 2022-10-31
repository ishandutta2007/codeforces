// Hydro submission #62cd07414125dc528b1ce0fd@1657603906241
#include<bits/stdc++.h>
#define ll long long
#define Il inline
#define mem(u,v) memset(u,v,sizeof(u))
#define rep(i,a,b) for(ll i=(a),KKK##i=(b);i<=KKK##i;i++)
#define drep(i,a,b) for(ll i=(a),KKK##i=(b);i>=KKK##i;i--)
#define go(u) for(ll i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define _go(u) for(ll i=Head[u],v=E[i].to;i;i=E[i].nxt,v=E[i].to)
#define __go(u) for(ll i=Head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),puts("")
using namespace std;
Il ll read(){ll sum=0,f=0;char ch=getchar();for(;!isdigit(ch);ch=getchar())f|=(ch=='-');for(;isdigit(ch);ch=getchar())sum=((sum<<1)+(sum<<3)+(ch^48));return f?-sum:sum;}
void write(const ll x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
char getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c;}
#define N 1010
ll n,m,x,y;double a[N][N],f[N];
void gauss(ll n){
	rep(i,1,n){
		if(i<n)a[i][i+1]/=a[i][i];
		a[i][n+1]/=a[i][i];a[i][i]=1;
		a[i+1][i+1]-=a[i][i+1]*a[i+1][i];
		a[i+1][n+1]-=a[i][n+1]*a[i+1][i];
		a[i+1][i]=0;
	}
	drep(i,n-1,1)a[i][n+1]-=a[i][i+1]*a[i+1][n+1];
}
void show(){}
int main(){
	n=read();m=read();x=read(),y=read();n-=x-1;
	if(m==1)return printf("%.10lf",2.0*(n-1)),0;
	drep(i,n-1,1){
		mem(a,0);
		a[1][1]=2;a[1][2]=-1;
		rep(j,2,m-1)a[j][j]=3,a[j][j-1]=a[j][j+1]=-1;
		a[m][m-1]=-1,a[m][m]=2;
		rep(j,2,m-1)a[j][m+1]=f[j]+4;
		a[1][m+1]=f[1]+3,a[m][m+1]=f[m]+3;
		gauss(m);
		rep(j,1,m)f[j]=a[j][m+1];
	}
	printf("%.10lf",f[y]);
}