#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,ans,x,ts1,ts2;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		ts1+=x/2;ts2+=x/2;
		if(x%2==1){
			if(i%2==1)
				ts1++;
			else
				ts2++;
		}
	}
	cout<<min(ts1,ts2);
}