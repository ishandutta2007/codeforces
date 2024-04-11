#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,n,x,y,j;
int main(){
	cin>>t;
	f(sal,0,t){
		cin>>x>>y;
		n=abs(x-y);
		j=0;
		while(j*(j+1)/2<n || ((j*(j+1)/2)-n)%2==1 )
			j++;
		cout<<j<<endl;
	}
}