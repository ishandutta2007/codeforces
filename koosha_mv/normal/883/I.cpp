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
ll a[N],l=-1,r=1e9+2,n,mid,p[N],p1=0,s=0,k;
bool check(ll x){
	p[0]=1;
	f(i,1,n+1) p[i]=0;
	p1=1;
	f(i,1,n+1){
		while(a[i]-a[p1]>x) p1++;
		p[i]=p[i-1]+(p1-2<i-k && (p1==1 || p[i-k]>p[p1-2]));
	}
	return !(p[n]>p[n-1]);
}
int main(){
	cin>>n>>k;
	f(i,1,n+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<r;
}