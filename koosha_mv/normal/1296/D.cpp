#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);

const int N=3e5+9;
ll a1,n,a[N],b,k,x,ans=0,t;
int main(){
	cin>>n>>a1>>b>>k;
	f(i,0,n){
		cin>>x;
		x-=(x-1)/(a1+b)*(a1+b);
		a[i]=(x/a1)+(x%a1>0)-1;
	}
	sort(a,a+n);
	ans=0;
	f(i,0,n){
		if(ans+a[i]<=k)
			ans+=a[i],t++;
	}
	cout<<t<<endl;
}