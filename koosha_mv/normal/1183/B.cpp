#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,k,q,x;
int main(){
	cin>>q;
	f(i,0,q){
		ll mx=0,mn=1e18+9;
		cin>>n>>k;
		f(i,0,n){
			cin>>x;mx=max(mx,x);mn=min(mn,x);
		}
		if(mx-(mn+k)<=k) cout<<mn+k<<endl;
		else cout<<-1<<endl;
		
	}
}