#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=1e5+99;
ll ans,a[N],n;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(i>0){
			if(a[i]<a[i-1])
				ans+=(n-a[i-1]+1)*(a[i-1]-a[i]);
			if(a[i]>a[i-1])
				ans+=a[i-1]*(a[i]-a[i-1]);
		}
	}
	cout<<ans+(a[n-1]*(n-a[n-1]+1));
}