#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,n,k,t1,ans;
int main(){
	cin>>t1;
	f(i,0,t1){

		cin>>n>>t;
		ans=n-(n%t);
		n=n%t;
		n=min(n,t/2);
		cout<<ans+n<<endl;
	}
}