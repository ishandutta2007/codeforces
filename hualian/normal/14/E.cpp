#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=30;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,t;
int dp[N][N][N][5][5];
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),t=read();
	rep(i,4)rep(j,4)if(i!=j)dp[2][0][0][i][j]=1;
	For(i,3,n)For(a,0,i)For(b,0,i)rep(j,4)rep(k,4)rep(l,4){
		if(j==k||k==l||!dp[i-1][a][b][j][k])continue;
		if(j>k&&k<l)dp[i][a][b+1][k][l]+=dp[i-1][a][b][j][k];
		else if(j<k&&k>l)dp[i][a+1][b][k][l]+=dp[i-1][a][b][j][k];
		else dp[i][a][b][k][l]+=dp[i-1][a][b][j][k];
	}
	int res=0;
	rep(i,4)rep(j,4)res+=dp[n][t][t-1][i][j];
	cout<<res<<endl;
	return 0;
}