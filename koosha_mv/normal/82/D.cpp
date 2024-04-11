#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i<b;i+=2)
#define ll long long
#define pb push_back
ll n,dp[1004][1004],a[1002],mn=1e9,an=-1,kh[505],sk=0;
int dfs(int x,int mar){
	kh[mar/2]=x;
	if(mar==0) return 0;
	if(x>=mar){
		f(i,1,mar){
			if((dp[mar-2][i]+max(a[i],a[x+(x==mar)-(x!=mar)]))==dp[mar][x]){
				dfs(i,mar-2);
				return 0;
			}
		}
	}
	else{
		dfs(x,mar-2);
	}
	return 0;
}
int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f_(i,2,n){f(j,1,i+2)dp[i][j]=1e9;}
	dp[0][1]=0;
	f_(i,2,n){
		f(j,1,i+2){
			if(j<i)
				dp[i][j]=dp[i-2][j]+max(a[i],a[i+1]);
			else{
				f(k,1,i){
					dp[i][j]=min(dp[i][j],dp[i-2][k]+max(a[k],a[j+(j==i)-(j!=i)]));
				}
			}
		}
	}
	if(n%2==1){
		f(i,1,n+1){
			if(dp[n/2*2][i]+a[i]<mn){
				mn=dp[n/2*2][i]+a[i];
				an=i;
			}
		}
		cout<<mn<<endl;
		dfs(an,n-1);
		int gh=1;
		f(i,1,n/2+1){
			if(kh[i]==gh){
				cout<<i*2<<" "<<i*2+1<<endl;
			}
			else if(kh[i]==i*2){
				cout<<gh<<" "<<i*2+1<<endl;
			}
			else
				cout<<gh<<" "<<i*2<<endl;
			gh=kh[i];
		}
		cout<<an;
	}
	else{
		mn=1e9;
		f(i,1,n){
			if(dp[n-2][i]+max(a[i],a[n])<mn){
				mn=dp[n-2][i]+max(a[i],a[n]);
				an=i;
			}
		}
		cout<<mn<<endl;
		dfs(an,n-2);
		int gh=1;
		f(i,1,n/2){
			if(kh[i]==gh){
				cout<<i*2<<" "<<i*2+1<<endl;
			}
			else if(kh[i]==i*2){
				cout<<gh<<" "<<i*2+1<<endl;
			}
			else
				cout<<gh<<" "<<i*2<<endl;
			gh=kh[i];
		}
		cout<<an<<" "<<n;
	}
}