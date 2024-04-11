#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=42;
ll dp[N][N][N][N],g[N][N],m,n,a[N][N],q,mn,a1,a2,a3,a4;
char w;
int main(){
	cin>>n>>m>>q;
	f(i,1,n+1){
		f(j,1,m+1){
			cin>>w;
			a[i][j]=(w=='1');
		}
	}
	f(x,1,n+1){
		f(y,1,m+1)
			g[x][y]=(g[x-1][y]+(a[x][y]==0))*(a[x][y]==0);
	}
	f(x,1,n+1){
		f(y,1,m+1){
			f(i,1,x+1){
				f(j,1,y+1){
					dp[i][j][x][y]=dp[i][j][x][y-1]+dp[i][j][x-1][y]-dp[i][j][x-1][y-1];
					mn=x-i+1;
					f_(p,y,j){
						minm(mn,g[x][p]);
						dp[i][j][x][y]+=mn;
					}
					//cout<<'('<<i<<','<<j<<')'<<' '<<'('<<x<<','<<y<<')'<<" : "<<dp[i][j][x][y]<<endl;
				}
			}
		}
	}
	f(i,0,q){
		cin>>a1>>a2>>a3>>a4;
		cout<<dp[a1][a2][a3][a4]<<endl;
	}
}