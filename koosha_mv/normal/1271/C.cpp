#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,r,u,l,d,w,x,y,xx,yy;
int main(){
	cin>>n>>x>>y;
	f(i,0,n){
		cin>>xx>>yy;
		if(xx>x) r++;
		if(xx<x) l++;
		if(yy>y) u++;
		if(yy<y) d++;
	}
	cout<<max(max(d,u),max(l,r))<<endl;
	if(max(max(d,u),max(l,r))==r){
		cout<<x+1<<" "<<y;return 0;
	}
	if(max(max(d,u),max(l,r))==l){
		cout<<x-1<<" "<<y;return 0;
	}
	if(max(max(d,u),max(l,r))==d){
		cout<<x<<" "<<y-1;return 0;
	}
	if(max(max(d,u),max(l,r))==u){
		cout<<x<<" "<<y+1;
	}
}