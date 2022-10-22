#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=41;

int n,n1,n2,k,ans,a[N][N],dp[(1<<20)],check[(1<<20)],mark[N];


bool is_bit(int x,int y){
	return (x%(1<<(y+1))>=(1<<y));
}
void find(int mask){
	if(dp[mask]>0) return ;
	int mn=N,mx=0,t=0;
	f(i,0,n2)
		if(is_bit(mask,i)){
			maxm(mx,dp[mask-(1<<i)]);
			minm(mn,dp[mask-(1<<i)]);
			t++;
		}
	dp[mask]=mx;
	if(mn==t-1)
		dp[mask]=t;
}
void ck(int mask){
	if(check[mask]>=0) return ;
	check[mask]=1;
	f(i,0,n2)
		if(is_bit(mask,i))
			if(check[mask-(1<<i)]==0)
				check[mask]=0;
}
int solve(int mask){
	fill(mark,mark+n2,1);
	int t=0;
	f(i,0,n1){
		if(is_bit(mask,i)){
			t++;
			f(j,0,n2)
				if(a[i][n1+j])
					mark[j]=0;
		}
	}
	int msk=0;
	f(i,0,n2)
		if(mark[i])
			msk+=(1<<i);
	return t+dp[msk];
}
int main(){
	cin>>n>>k;
	n1=n/2;
	n2=n-n1;
	fill(check,check+(1<<n1),-1);
	
	f(i,0,n)
		f(j,0,n){
			gett(a[i][j]);
			a[i][j]=1-a[i][j];
		}
	f(i,0,n2)
		dp[(1<<i)]=1;
	f(i,0,n2){
		dp[(1<<i)]=check[1<<i]=1;
		f(j,0,n2){
			check[(1<<i)+(1<<j)]=0;
			if(a[i][j]==0) check[(1<<i)+(1<<j)]=1; 
			dp[(1<<i)+(1<<j)]=1;
			if(a[n1+i][n1+j]==0)
				dp[(1<<i)+(1<<j)]=2;
		}
	}
	f(i,0,(1<<n2))
		find(i);
	f(i,0,(1<<n1)){
		ck(i);
		if(check[i])
			maxm(ans,solve(i));
	}
	printf("%.9f\n",(double(k)/double(ans))*(double(k)/double(ans))*double(ans*(ans-1)/2));
}