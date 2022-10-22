#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,q,a[N];
int main(){
	cin>>q;
	f(j,0,q){
		ll mn=0,mx=0,k=0,mn2=1e9;
		cin>>n;
		f(i,1,n+1){
			cin>>a[i];
			a[i]+=a[i-1];
			if(i<n){
				mx=max(mx,a[i]-mn);
			}
			else
				mx=max(mx,a[i]-mn2);
			mn=min(mn,a[i]);
			mn2=min(mn2,a[i]);
		}
		if(mx>=a[n])
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}