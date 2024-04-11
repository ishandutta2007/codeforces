#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,t,k,x,k1,k2;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>k1>>k2;k=0;
		f(i,0,k1){
			cin>>x;
			if(x==n) k=1;
		}
		f(i,0,k2){
			cin>>x;
		}
		if(k==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}