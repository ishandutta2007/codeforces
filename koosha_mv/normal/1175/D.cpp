#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+9;
ll n,k,a[N];
int main(){
	cin>>n>>k;
	f(i,1,n+1){
		get(a[i]);
		a[i]+=a[i-1];
	}
	a[n]*=k;
	sort(a+1,a+n);
	f(i,1,k)
		a[n]-=a[i];
	cout<<a[n];
		
}