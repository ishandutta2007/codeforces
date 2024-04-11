#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=52,mod=1e9+7;

int n,p,s,ans,a[N],Pow[N],dp[N][N][N];
// frd siah,fard sefid

void calc1(int sia,int sef){
	if(sia+sef>s) return ;
	if(sef){
		if(sia) dp[s][sia][sef]=1ll*dp[s-1][sia][sef-1]*Pow[s-2]%mod;
		else dp[s][sia][sef]=1ll*dp[s-1][sia][sef-1]*Pow[s-1]%mod;
	}
	if(sia+sef==s || sia==0) return;
	Add(dp[s][sia][sef],1ll*dp[s-1][sia][sef]*Pow[s-2]%mod);
}
void calc0(int fs,int sef){
	if(fs+sef>s) return ;
	if(fs){
		if(sef) Add(dp[s][fs][sef],1ll*dp[s-1][fs-1][sef]*Pow[s-2]%mod);
		else Add(dp[s][fs][sef],1ll*dp[s-1][fs-1][sef]*Pow[s-1]%mod);
	}
	if(fs+sef==s || sef==0) return;
	Add(dp[s][fs][sef],1ll*dp[s-1][fs][sef]*Pow[s-2]%mod);
}

int main(){
	Pow[0]=1;
	f(i,1,N) Pow[i]=Pow[i-1]*2ll%mod;
	cin>>n>>p;
	f(i,1,n+1) gett(a[i]);
	dp[1][1][0]=(a[1]!=1);
	dp[1][0][1]=(a[1]!=0);
	f(an,2,n+1){
		s=an;
		f(i,0,n+1)
			f(j,0,n+1){
				if(a[an]!=0) calc1(i,j);
				if(a[an]!=1) calc0(i,j);
			}
	}
	f(i,0,n+1)
		f(j,0,n+1)
			if((i+j)%2==p)
				Add(ans,dp[n][i][j]);
	cout<<ans<<endl;
}