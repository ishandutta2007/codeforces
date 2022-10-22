#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

ll n,t,x,l,r,m,mid,ans[N];
ll a[N],sum;

int main(){
	cin>>n;
	mid=(n+1)/2;
	f(i,1,mid+1){ get(a[i]); a[i]+=a[i-1]; }
	cin>>x;
	sum=a[mid]+x*(n/2);
	if(x>=0)
		return cout<<(sum<=0 ? -1 : n),0;
	f(i,mid+1,n+1) a[i]=a[i-1]+x; 
	f(i,0,mid+1){
		l=mid,r=n+1;
		while(l+1<r){
			m=(l+r)/2;
			if(a[m]<=a[i]) r=m;
			else l=m;
		}
		ans[r-i]--,ans[n-i+1]++;
	}
	f(i,1,n+1){
		ans[i]+=ans[i-1];
		if(ans[i]>=0 && i>n/2)
			return cout<<i,0;
	}
	cout<<endl;
	cout<<-1;
}