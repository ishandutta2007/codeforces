#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,t,a[200999],k;
int main(){
	cin>>t;
	f(i,0,t){
		cin>>n;k=0;
		f(i,0,n){
			cin>>a[i];
			if(i>0 && (a[i]-a[i-1]>=2 || (a[i-1]-a[i])>=2) && k==0){
				k=1;
				cout<<"YES"<<endl;
				cout<<i<<" "<<i+1<<endl;
			}
		}
		if(k==0) cout<<"NO"<<endl;
	}
}