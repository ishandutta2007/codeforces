#include<iostream>
#include<cmath> 
#include<cstdio>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,i,x,p,j,m,k,ans,a[1200];

int main(){
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>a[i];
	} 
	cin>>x;
	ans=0;
	rep(i,1,m){
		p=n;
		rep(j,0,n-1){
			if (((x&(1<<j))==(a[i]&(1<<j)))) p--;
		}
		if (p<=k){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}