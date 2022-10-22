#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,a;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x>>y;
		a+=(x<0);
	}
	if(a<=1 || a>=n-1)
		cout<<"YES";
	else
		cout<<"NO";
}