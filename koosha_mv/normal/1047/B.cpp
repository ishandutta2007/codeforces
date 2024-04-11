#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,mx,x,y;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x>>y;
		mx=max(mx,x+y);
	}
	cout<<mx;
}