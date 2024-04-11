#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=82;
int n,k,g[N][N],ans=1e9,a[17];
pair<int,int> dp[N][N][7];

int solve(int x){
	int p=0,o=0;
	f(i,1,k/2){
		a[i]=x%80,x/=80;
		if(a[i]>=n) return 1e9;
	}
	f(i,0,k/2){
		o=0;
		f(j,0,6){
			if(dp[a[i]][a[i+1]][j].S!=a[0] && dp[a[i]][a[i+1]][j].S!=a[1] && dp[a[i]][a[i+1]][j].S!=a[2] && dp[a[i]][a[i+1]][j].S!=a[3] && dp[a[i]][a[i+1]][j].S!=a[4]){
				p+=dp[a[i]][a[i+1]][j].F;
				o=1;
				break;
			}
		}
		if(o==0) return 1e9;
	}
	return  p;
}
int main(){
	f(i,0,10) a[i]=1e9;
	scanf("%d%d",&n,&k);
	a[0]=0;a[k/2]=0;
	f(i,0,n){
		f(j,0,n) scanf("%d",&g[i][j]);
	}
	f(i,0,n){
		f(j,0,n){
			f(l,0,6) dp[i][j][l].F=1e9;
			f(l,1,n){
				if(l!=i && l!=j){
					dp[i][j][5]=mp(g[i][l]+g[l][j],l);
					sort(dp[i][j],dp[i][j]+6);
				}
			}
		}
	}
	f(i,0,4e7+5e6)
		minm(ans,solve(i));
	cout<<ans<<endl;
}