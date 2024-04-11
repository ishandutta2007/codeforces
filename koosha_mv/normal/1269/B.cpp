#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,m,a[3000],b[3000],e,mn=1e9,l;
int main(){
	cin>>n>>m;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n) cin>>b[i];
	sort(a,a+n);sort(b,b+n);
	f(i,0,n){
		e=(b[i]+m-a[0])%m;l=0;
		f(j,0,n){
			if((a[j]+e)%m!=b[(i+j)%n]){
				l=1;break;
			}
		}
		if(l==0) mn=min(mn,e);
	}
	cout<<mn;
}