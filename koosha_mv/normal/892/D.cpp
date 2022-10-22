#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define get(x,y) scanf("%I64d%I64d",&x,&y);
ll n,a[25],b[25];
map<ll,ll> mp;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];b[i]=a[i];
	}
	sort(b,b+n);
	f(i,0,n)
		mp[b[i]]=b[(i+n-1)%n];
	f(i,0,n)
		cout<<mp[a[i]]<<" ";
}