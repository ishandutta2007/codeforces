#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e7+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(long long &x,long long y){(x<y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int cnt[N];
long long dp[N];
bool vis[N];
int p[N/10],len;
void init(int n){
	For(i,2,n){
		if(!vis[i])p[++len]=i;
		
		for(int j=1;j<=len&&p[j]*i<=n;j++){
			vis[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
//	cout<<p[1]<<endl;exit(0);
	assert(len<=N/10-1);
}
int n; 
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();int m=0;
	rep(i,n){
		int x=read(),j=1;
		m=max(m,x);
		for(;j*j<x;j++)if(x%j==0)
			cnt[j]++,cnt[x/j]++;
		if(j*j==x)cnt[j]++;
	}
	init(m);
	rep(i,m)dp[i]=1ll*cnt[i]*i;
	Rof(i,m,1)for(int j=1;j<=len&&p[j]*i<=m;j++){
		chmx(dp[i],dp[i*p[j]]+1ll*(cnt[i]-cnt[i*p[j]])*i);
	}
//	cout<<dp[3]<<endl;
	cout<<dp[1]<<endl;
	return 0;
}