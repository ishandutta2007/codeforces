#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int L,n,a[N],mn,mx; 
bool checkmn(int mid){
	int pre=0;
	a[n+1]=L;
	rep(i,n){
		pre+=mid;if(pre>a[i+1])return false;
		chmx(pre,a[i]);
	}return true;
}
int getmn(){
	int l=1,r=1000000000;
	 while(l<=r){
	 	int mid=(l+r)>>1;
	 	if(checkmn(mid))l=mid+1;
	 	else r=mid-1;
	 }return l-1;
}
pair<int,int>dp[N];
bool check(int l,int r){
	dp[0]=mk(0,0);
	rep(i,n){
		dp[i]=mk(dp[i-1].fi+l,dp[i-1].se+r);
		chmx(dp[i].fi,a[i]);
		chmn(dp[i].se,a[i+1]);
		if(dp[i].fi>dp[i].se)return false;
	}
	return (dp[n].se==L);
}
int getmx(){
	int l=mn,r=1000000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mn,mid))r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
int ans[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	L=read(),n=read();
	rep(i,n)a[i]=read();
	mn=getmn();mx=getmx();
//	cout<<mn<<" "<<mx<<endl;
	check(mn,mx);
	ans[n]=L;
	Rof(i,n-1,1){
		int nt=dp[i].fi+mn;
		if(nt<=ans[i+1]&&nt+(mx-mn)>=ans[i+1])
			{ans[i]=dp[i].fi;continue;}
		nt=dp[i].fi+mx;assert(nt<ans[i+1]);
		ans[i]=ans[i+1]-nt+dp[i].fi;
		assert(ans[i]<=dp[i].se&&ans[i]>=dp[i].fi);
	}
	rep(i,n)printf("%d %d\n",ans[i-1],ans[i]);
	return 0;
}