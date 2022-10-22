#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int fr(int x){
	if(x<0)
		return 0;
	return x;
}
int main(){
	long long y,x,q,n;
	cin>>q;
	f(sa,0,q){
		cin>>n;
		long long mx=0,mn=1e10;
		f(i,0,n){
			cin>>x>>y;
			mn=min(mn,y);
			mx=max(mx,x);
		}
		cout<<fr(mx-mn)<<endl;
	}
	
}