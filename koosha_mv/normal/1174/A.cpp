#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2005;
int n,a[N],ans;
int main(){
	cin>>n;
	f(i,0,n*2) cin>>a[i];
	sort(a,a+n+n);
	f(i,1,n*2)
		if(a[i]!=a[i-1])
			ans=1;
	if(ans)
		f(i,0,2*n) cout<<a[i]<<" ";
	else cout<<-1;
}