#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll mx=1,a[200099],n,b[200099],sb=1;
int main(){
	cin>>n;b[0]=0;
	f(i,0,n){
		cin>>a[i];
		if(i>0 && a[i]<=a[i-1]){
			b[sb]=i;
			sb++;
		}
	}
	if(sb==1){cout<<n; return 0;}
	if(sb==2){cout<<n-1; return 0;}
	int p1=0,p2=0,t=0;
	b[sb]=n;sb++;
	f(i,1,sb-1){
		if(b[i+1]-b[i-1]-1>1 && a[b[i]-1]<a[b[i]+1] || (b[i]>1 && a[b[i]-2]<a[b[i]])){
			mx=max(mx,b[i+1]-b[i-1]-1);
		}
		mx=max(mx,max(b[i]-b[i-1],b[i+1]-b[i]));
	}
	cout<<mx;
}