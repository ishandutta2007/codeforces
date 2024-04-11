#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
int n,m,k,mx[510][510],mxl[510],mxr[510],r,l,dp[509][509];
string s;
int main(){
	cin>>n>>m>>k;
	f(p,1,n+1){
		cin>>s;r=0;l=0;
		f(i,0,501){
			mxl[i]=mxr[i]=0;
		}
		f(i,0,s.size()){
			if(s[i]=='1'){
				mxl[l]=i;l++;			
			}
		}
		f_(i,s.size()-1,0){
			if(s[i]=='1'){
				mxr[r]=i;r++;
			}
		}
		f(i,0,r){
			for(int j=0;j+i<=r;j++){
				if(mx[p][i+j]==0) mx[p][i+j]=mxr[i]-mxl[j]+1;
				else mx[p][i+j]=min(mx[p][i+j],mxr[i]-mxl[j]+1);
			}
		}
		mx[p][r]=0;
		f(i,0,k+1) dp[p][i]=1e8;
		f(i,0,k+1){
			f(j,0,i+1){
				dp[p][i]=min(dp[p][i],dp[p-1][i-j]+mx[p][j]);
			}
		}
	}
	cout<<dp[n][k];
}