#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
ll n,k,l,a[N],ans,t,p;
int main(){
	cin>>n>>k>>l;
	f(i,0,n*k) cin>>a[i];
	sort(a,a+n*k);
	f(j,0,n*k){
		p=j;
		if(a[j+1]-a[0]>l)
			break;
	}
	if(p<n-1){cout<<0;return 0;}
	f(i,1,n+1){
		while(n*k-p<i*k)
			p--;
		ans+=a[p];
		p--;
	}
	cout<<ans;
}