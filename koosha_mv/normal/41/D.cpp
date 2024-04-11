#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=103,e=1e6;
ll dp[N][N][11],n,m,k,mx=-1,an;
string a[N],s;
int dfs(int x,int y,int mod){
	if(x==1){cout<<y+1<<endl;return 0;}
	if(y>0 && dp[x-1][y-1][(mod+(e*k)-(a[x][y]-'0'))%k]+(a[x][y]-'0')==dp[x][y][mod]){
		s+='R';
		dfs(x-1,y-1,(mod+(e*k)-(a[x][y]-'0'))%k);
		return 0;
	}
	s+='L';
	dfs(x-1,y+1,(mod+(e*k)-(a[x][y]-'0'))%k);
	return 0;
}
int main(){
	cin>>n>>m>>k;k++;
	f_(i,n,0){
		if(i!=0) cin>>a[i];
		f(j,0,m){
			f(l,0,k){
				dp[i][j][l]=-1;
				if(i==0 && l==0) dp[i][j][l]=0;
			}
		}
	}
	f(i,1,n+1){
		f(j,0,m){
			f(l,0,k){
				if(j>0){
					if(dp[i-1][j-1][(l+(e*k)-(a[i][j]-'0'))%k]!=-1)
						dp[i][j][l]=dp[i-1][j-1][(l+(e*k)-(a[i][j]-'0'))%k]+(a[i][j]-'0');
				}
				if(j<m-1){
					if(dp[i-1][j+1][(l+(e*k)-(a[i][j]-'0'))%k]!=-1)
						dp[i][j][l]=max(dp[i][j][l],dp[i-1][j+1][(l+(e*k)-(a[i][j]-'0'))%k]+(a[i][j]-'0'));
				}
			}
			if(i==n && dp[i][j][0]>mx){
				mx=dp[i][j][0],an=j;
			}
		}
	}
	if(mx==-1){cout<<-1;return 0;}
	cout<<mx<<endl;
	dfs(n,an,0);
	reverse(s.begin(),s.end());
	cout<<s;
}