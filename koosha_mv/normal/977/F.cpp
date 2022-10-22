#include <bits/stdc++.h>
#include<map>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
map <int,int> dp;
int a[200099];
int main(){
	int x,n,mx=0,a1;cin>>n;
	f(i,0,n){
		cin>>x;a[i]=x;
		dp[x]=dp[x-1]+1;
		mx=max(mx,dp[x]);
		if(mx==dp[x])
			a1=x;}
	cout<<mx<<endl;a1=a1-mx+1;
	f(j,0,n){
		if(a[j]==a1){cout<<j+1<<" ";a1++;}
	}
}