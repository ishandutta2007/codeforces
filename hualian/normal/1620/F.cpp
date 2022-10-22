#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int T,n,a[N];
int dp[N][2];
int ans[N][2];
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	T=read();
	while(T-->0){
		n=read();
		rep(i,n)a[i]=read(),dp[i][0]=dp[i][1]=1e9;
		a[0]=n+1;dp[0][0]=-1e9;dp[0][1]=0;
		rep(i,n){
			For(k,0,1){
				int x=(k?a[i-1]:-a[i-1]),y=dp[i-1][k];
				if(x<y)swap(x,y);//x1y2
				int now=a[i];
				if(now>x){
					if(y<dp[i][1])dp[i][1]=y,ans[i][1]=k;
				}
				else if(now>y){
					if(x<dp[i][1])dp[i][1]=x,ans[i][1]=k;
				}
				now=-a[i];
				if(now>x){
					if(y<dp[i][0])dp[i][0]=y,ans[i][0]=k;
				}
				else if(now>y){
					if(x<dp[i][0])dp[i][0]=x,ans[i][0]=k;
				}
			}
		}
		if(dp[n][0]<=n||dp[n][1]<=n){
			int x=((dp[n][0]<=n)?0:1);
			Rof(i,n,1){
				a[i]=x?a[i]:-a[i];
				x=ans[i][x];
			}puts("YES");
			rep(i,n)printf("%d ",a[i]);puts("");
		}else puts("NO");
	}
	return 0;
}