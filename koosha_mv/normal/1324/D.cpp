#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5,mod=1e9+7;
ll n,a[N],b[N],x,p1=0,ans;
int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	f(i,0,n){
		cin>>x;
		b[i]=a[i]-x;
	}
	sort(b,b+n);
	f(i,1,n){
		while(p1<i && b[p1]+b[i]<=0)
			p1++;
		while(p1>0 && b[p1-1]+b[i]>0)
			p1--;
		ans+=i-p1;
	}
	cout<<ans;
}