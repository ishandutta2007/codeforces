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
const int N=3e5+99;
ll n,m,a[N],b1[N],b2[N],ans,ans1,ans2,mx;
int main(){
	Get(n,m);
	n++;
	f(i,1,n){
		get(a[i]);
		ans+=(a[i]-a[i-1])*(i%2==1);
	}
	a[n]=m;
	ans+=(a[n]-a[n-1])*(n%2==1);
	mx=ans;
	f_(i,n-1,0){
		if(i%2==0)
			b1[i]=b1[i+2]+a[i+1]-a[i],b2[i]=b2[i+1];
		else
			b2[i]=b2[i+2]+a[i+1]-a[i],b1[i]=b1[i+1];
	//	cout<<b1[i]<<" "<<b2[i]<<endl;
	}
	f(i,0,n){
		if(i%2==0){
			maxm(mx,ans-b1[i+1]+b2[i+1]-1);
		}
		else{
			maxm(mx,ans-b1[i+1]+b2[i+1]+(a[i+1]-a[i]-1));
		}
	}
	cout<<mx<<endl;
}