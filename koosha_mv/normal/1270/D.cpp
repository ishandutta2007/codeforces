#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=599;
ll ans[N][2],x,y,ans1,k,n;
int main(){
	cin>>n>>k;n=k+1;
	f(i,0,n){
		cout<<"?";
		f(j,i,i+k){
			cout<<" "<<(j%n)+1;
		}
		cout<<endl;
		cin>>ans[i][0]>>ans[i][1];
	}
	f(i,1,n){
		if(ans[i][0]==ans[0][0])
			ans1++;
	}
	if(ans[ans[0][0]%n][1]>ans[0][1])
		cout<<"! "<<k-ans1<<endl;
	else
		cout<<"! "<<ans1+1<<endl;
}