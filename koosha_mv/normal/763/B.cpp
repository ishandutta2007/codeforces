#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int main(){
	long long n,x,y,z,k;
	cin>>n;
	cout<<"YES"<<endl;
	f(i,0,n){
		cin>>x>>y>>z>>k;x+=1e9;y+=1e9;
		if(x%2==0 && y%2==0) cout<<1<<endl;
		if(x%2==1 && y%2==0) cout<<2<<endl;
		if(x%2==0 && y%2==1) cout<<3<<endl;
		if(x%2==1 && y%2==1) cout<<4<<endl;
	}
}