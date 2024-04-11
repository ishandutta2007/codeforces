#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
int n,m,a[200009],b[200009],l,r,mid;
int main(){
	cin>>n>>m;
	f(i,0,n) cin>>a[i];
	f(i,0,m) cin>>b[i];
	sort(a,a+n);
	f(i,0,m){
		if(b[i]<a[0]) cout<<0<<" ";
		else{
			l=0,r=n;
			while(l+1<r){
				mid=(l+r)/2;
				if(a[mid]>b[i]) r=mid;
				else l=mid;
			}
			cout<<l+1<<" ";
		}
	}
}