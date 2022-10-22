#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans;
string s[21];
int ad[21];
int dp[1<<21],mn[21];
unordered_map<int,int>mp[21];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)cin>>s[i];
	rep(i,n){
		mn[i]=1e9;
		For(j,0,(int)s[i].size()-1){
			ad[i]+=s[i][j]=='(',
			ad[i]-=s[i][j]==')';
			if(ad[i]<=mn[i])mp[i][ad[i]]++;
			chmn(mn[i],ad[i]);
		}
	}
	memset(dp,0xc0,sizeof dp);
	dp[0]=0;
	For(S,0,(1<<n)-1){
		int top=0;
		rep(i,n)if((S>>i-1)&1)top+=ad[i];
		rep(i,n)if(((S>>i-1)&1)==0){
			chmx(ans,dp[S]+mp[i][-top]);
			if(top+mn[i]>=0)chmx(dp[S|(1<<i-1)],dp[S]+mp[i][-top]);
		}
	}cout<<ans<<endl;
	return 0;
}