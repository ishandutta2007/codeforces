#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
int p1,p2,n,k,a[100099],cost,mx,ad;
int main(){
	cin>>n>>k;
	f(i,0,n){
		cin>>a[i];}
	sort(a,a+n);
	p1=n-1,p2=n-2;
	while(p1>=0 && p2>=0){
		if(cost+a[p1]-a[p2]<=k){
			cost+=a[p1]-a[p2];
			if(p1-p2+1>=mx){
				mx=p1-p2+1;
				ad=a[p1];}
			p2--;
		}
		else{
			cost-=(p1-p2-1)*(a[p1]-a[p1-1]);
			p1--;}
	}
	if(mx==0){cout<<1<<" "<<a[0];return 0;}
	cout<<mx<<" "<<ad;
}