#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
bool ppp;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m;
int gcd(int x,int y){return (!y)?x:(gcd(y,x%y));}
int g[N][21],a[N];
inline int ST(int l,int r){
	int k=log2(r-l+1);
	return gcd(g[l][k],g[r-(1<<k)+1][k]);
}bool pppp;
signed main(){//printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
//	freopen("edge1.in","r",stdin);
//	freopen("edge.out","w",stdout);
	int T=read();
	while(T--){
		int ans=0;
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		n--;
		for(int i=1;i<=n;i++)g[i][0]=abs(a[i]-a[i+1]);
		for(int j=1;j<=18;j++)for(int i=1;i<=n-(1<<j)+1;i++)
			g[i][j]=gcd(g[i][j-1],g[i+(1<<j-1)][j-1]);
		int j=1;
		for(int i=1;i<=n;i++){
			while(ST(j,i)<=1&&j<=i)j++;
			ans=max(ans,i-j+1);
		}
		 cout<<ans+1<<endl;
	}
	return 0;
}