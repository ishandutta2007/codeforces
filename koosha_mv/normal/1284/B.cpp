#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n;
ll x,ans,a[100009],mx[100009],mn[1000009],k,p1;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		k=1;
		f(i,0,x){
			cin>>a[i];
			if(i>0 && a[i]>a[i-1])
				k=0;
		}
		if(k==1){
			mn[a[x-1]]++;
			mx[p1]=a[0];
			p1++;
		}
	}
	f_(i,1000000,0){
		mn[i]=mn[i]+mn[i+1];
	}
	f(i,0,p1){
		ans+=mn[mx[i]];
	}
	cout<<n*n-ans<<endl;
}