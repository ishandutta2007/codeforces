#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2030;

int n,m,t,up[N][N],dw[N][N];
string s[N];
ll ans;

void solve(int x,int y){
	int l=0,r=min(dw[x][y],(n-x)/2)+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(up[x+mid*2][y]>=mid) l=mid;
		else r=mid;
	}
	ans+=r;
}
void calc(){
	f(i,1,n)
		f(j,1,m-1)
			if(!(s[i-1][j]!=s[i][j] || s[i-1][j-1]!=s[i][j] || s[i-1][j+1]!=s[i][j])) 
				up[i][j]=min(up[i-1][j-1],min(up[i-1][j],up[i-1][j+1]))+1;
	f_(i,n-2,0)
		f_(j,m-2,1)
			if(!(s[i+1][j]!=s[i][j] || s[i+1][j-1]!=s[i][j] || s[i+1][j+1]!=s[i][j]))
				dw[i][j]=min(dw[i+1][j-1],min(dw[i+1][j],dw[i+1][j+1]))+1;
	f(i,0,n)
		f(j,0,m)
			solve(i,j);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	f(i,0,n)
		cin>>s[i];
	calc();
	cout<<ans;
}