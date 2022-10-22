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
const int N=1e6+9;
int n,m,t,a[N],mark[N],ans,p,dp[N][5][3],a1,a2;
int main(){
	cin>>n>>m;
	f(i,0,n){gett(a[i]);mark[a[i]]++;}
	f_(i,m,0){
		f(j,0,5){
			f(k,0,3){
				if(j<=mark[i] && k<=mark[i+1]){
					a1=mark[i]-j,a2=mark[i+1]-k;
					f(p,0,3){
						if(p<=a1 && p<=a2 && p<=mark[i+2]){
							maxm(dp[i][j][k],dp[i+1][k+p][p]+p+((a1-p)/3));
						}
					}
				}
			}
		}
	}
	cout<<dp[0][0][0];
}