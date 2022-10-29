#include<iostream>
#include<cmath> 
#include<cstdio>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,i,x,y,ans;

int main(){
	cin>>n;
	ans=0;
	rep(i,1,n){
		cin>>x>>y;
		if (y-x>=2){
			ans++; 
		} 
	}
	cout<<ans<<endl;
	return 0;
}