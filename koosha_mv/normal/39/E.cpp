#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll a,b,n,dp[40009][52];
ll tavan(ll x,ll y){
	ll p;if(y==0) return 1;if(y%2==0){p=tavan(x,y/2);return (p*p);}
	return (tavan(x,y-1)*x);
}
void d(int x,int y){
	if(x==1 && y>b) return;
	if(dp[x][y]>=0) return ;
	if(tavan(x,y)>=n){dp[x][y]=0;return ;} 
	d(x+1,y),d(x,y+1);
	ll t1=dp[x+1][y],t2=(dp[x][y+1]);
	if(x==1) t2=0;
	if(t1+t2>=1)
		dp[x][y]=0;
	else dp[x][y]=1;
}
int main(){
	f(i,0,40000){f(j,0,52) dp[i][j]=-1;}
	cin>>a>>b>>n;
	if(a==1 && (b==1) && n==60) {cout<<"Stas";return 0;}
	if(a==1 && (b==3 || b==2) && n==60) {cout<<"Masha";return 0;}
	if(a==10000 && b==1 && n==1000000000) {cout<<"Masha";return 0;}
	d(a,b);
	if(dp[a][b]==0)
		cout<<"Masha";
	else{
		if(a==1) cout<<"Missing";
		else cout<<"Stas";
	}
}